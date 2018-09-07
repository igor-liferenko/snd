/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief This file manages the audio task.
//!
//! - Compiler:           IAR EWAVR and GNU GCC for AVR
//! - Supported devices:  ATmega32U4
//!
//! \author               Atmel Corporation: http://www.atmel.com \n
//!                       Support and FAQ: http://support.atmel.no/
//!
//! ***************************************************************************

/* Copyright (c) 2007, Atmel Corporation All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of ATMEL may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//_____  I N C L U D E S ___________________________________________________

#include "config.h"
#include "conf_usb.h"
#include "audio_task.h"
#include "lib_board/evk_527/evk_527.h"
#include "lib_mcu/usb/usb_drv.h"
#include "lib_mcu/adc/adc_drv.h"
#include "usb_descriptors.h"
#include "modules/usb/device_chap9/usb_standard_request.h"
#include "sound.h"
#include "lib_mcu/timer/timer8_drv.h"
#include "lib_mcu/timer/timer16_drv.h"
#include "lib_mcu/pll/pll_drv.h"
#include "lib_mcu/timer/timerhs_drv.h"

//_____ M A C R O S ________________________________________________________


//_____ D E F I N I T I O N S ______________________________________________

U16   Get_adc_ext_val(void);


//_____ D E C L A R A T I O N S ____________________________________________

//! Mute control of speaker
//! TRUE when ACTIVE, FALSE otherwise
//!
bit b_speaker_mute;

//! Represents the current volume of audio stream speaker
S16 s16_speaker_volume;

//! Speaker datas must be storaged in a buffer to control and ajust the speaker frequency
#define BUFFER_SIZE  0x400
U8 g_buffer_speaker[BUFFER_SIZE];
U8 *ptr_speaker_data_wr;
U8 *ptr_speaker_data_rd;

//! Mute control of micro
//! TRUE when ACTIVE, FALSE otherwise
//!
bit b_micro_mute;

//! Represents the current volume of audio stream micro
//! No effet in this demo
//!
S16 s16_micro_volume;

//! Play position in sample sound storage in flash raw
//!
U16 g_u16_micro_sample_pos=0;

#if( SPEAKER_FREQUENCY == 32000 )
#define TIMER1_MIN_FREQUENCY   251     // (8MHz/1) / 32KHz > 251ctn
#define TIMER1_MAX_FREQUENCY   249     // (8MHz/1) / 32KHz < 249ctn
#elif( SPEAKER_FREQUENCY == 8000 )
#define TIMER1_MIN_FREQUENCY  1000     // (8MHz/1) / 8KHz > 999ctn
#define TIMER1_MAX_FREQUENCY   999     // (8MHz/1) / 8KHz < 1001ctn
#else
#error SPEAKER_FREQUENCY must be define in config.h
#endif



//! @brief This function initializes the USB the associated variables.
//!
void audio_task_init(void)
{
   Joy_init();
   Hwb_button_init();
   init_adc();

   ptr_speaker_data_wr = g_buffer_speaker;
   ptr_speaker_data_rd  = g_buffer_speaker;

   //** Micro setup
   // At 8 kHz, signal is be sampled every 125µs. When endpoint is full (8 sample words), it is validated.
   // But periodically a real-time problem may occur, since the Host token is also sent approx. every 1ms : it can happen
   // that the token arrives while the Device endpoint has not been validated yet (the difference between these
   // two moments can be some µsecs), and the packet is not sent : 1 frame (1ms) is missed. So the sample rate has been
   // fixed every 120µs, to have a 40µs endpoint "free" delay to decrease error cases.
   Timer8_set_waveform_mode(TIMER8_WGM_CTC_OCR);   // Timer 0 mode CTC
   Timer8_set_compare(120);                        // (1/(8MHz/8)) * 120ctn => 120µS
   Timer8_set_clock(TIMER8_0_CLKIO_BY_8);          // Prescaler div8
   Timer8_compare_it_enable();                     // Enable compare interrupt
   
   //** Speaker setup 
   // The clock for High Speed timer is already start by USB task
   /*
   OSCCAL=0;
   Set_RC_pll_clock();
   Pll_start_auto();
   */
   // Init High Speed timer on PWM
   Pll_set_hs_tmr_pscal_1dot5();
   Timerhs_clear();
   Timerhs_set_waveform_mode(TIMERHS_WGM_FAST_PWM);
   Timerhs_set_nb_bit(10);
   Enable_DAC_pwm();
   Timerhs_set_clock(TIMERHS_CLK_BY_1);

   // Timer 1 used to update PWM factor
   Timer16_set_waveform_mode(TIMER16_WGM_CTC_OCR); // Timer 1 mode CTC
   Timer16_set_compare_a(TIMER1_MAX_FREQUENCY);
   Timer16_set_clock(TIMER16_CLKIO_BY_1);          // Prescaler div1
   Timer16_compare_a_it_enable();                  // Enable compare interrupt

   // default audio controls
   b_speaker_mute = FALSE;
   b_micro_mute   = FALSE;
   s16_speaker_volume= SPEAKER_VOL_MAX;
   s16_micro_volume  = MICRO_VOL_MAX;
}


//! @brief Entry point of the audio management task
//!
void audio_task(void)
{
   Bool b_endpoint_no_empty = FALSE;
   
   if( !Is_device_enumerated() )
     return;   // Device not ready

   // Adjust timer
   if( ptr_speaker_data_wr < ptr_speaker_data_rd )
   {
      if( TIMER1_MAX_FREQUENCY == Timer16_get_compare_a() )
      {
         if( (BUFFER_SIZE*1/8)>((U16)ptr_speaker_data_wr+((U16)BUFFER_SIZE-(U16)ptr_speaker_data_rd)) )
         {
            Timer16_set_compare_a(TIMER1_MIN_FREQUENCY);
         }
      }else{
         if( (BUFFER_SIZE*7/8)<((U16)ptr_speaker_data_wr+((U16)BUFFER_SIZE-(U16)ptr_speaker_data_rd)) )
         {
            Timer16_set_compare_a(TIMER1_MAX_FREQUENCY);
         }
      }
   }
   else
   {
      if( TIMER1_MAX_FREQUENCY == Timer16_get_compare_a() )
      {
         if( (BUFFER_SIZE*1/8)>(ptr_speaker_data_wr-ptr_speaker_data_rd) )
         {
            Timer16_set_compare_a(TIMER1_MIN_FREQUENCY);
         }
      }else{
         if( (BUFFER_SIZE*7/8)>(ptr_speaker_data_wr-ptr_speaker_data_rd) )
         {
            Timer16_set_compare_a(TIMER1_MAX_FREQUENCY);
         }
      }
   }  

   // Fill audio buffer
   Usb_select_endpoint(EP_AUDIO_OUT);
   if(!Is_usb_receive_out())
      return;   
   while (Usb_byte_counter()!=0)
   {     
      b_endpoint_no_empty = TRUE;
      *ptr_speaker_data_wr++ = Usb_read_byte();
      *ptr_speaker_data_wr++ = Usb_read_byte();
      if( ptr_speaker_data_wr == (g_buffer_speaker+BUFFER_SIZE) )
         ptr_speaker_data_wr = g_buffer_speaker;
   }
   // If pipe empty then free it
   if( b_endpoint_no_empty )
   {
      Usb_free_out_bank();
   }
 
}


//! @brief Timer0 comparator interrupt routine service
//!
//! Get ADC sample (microphone or alternate external source) and load it to
//! the Isochronous endpoint.
//!
//! @note The dual bank endpoint usage allows to get ride of an extra synchonisation buffer
//!
#ifdef __GNUC__
 ISR(TIMER0_COMPA_vect)
#else
#pragma vector = TIMER0_COMPA_vect
__interrupt void timer0_comp_interrupt()
#endif
{
   S16 sample;
   U8 sav_ep;
      
   if(!Is_device_enumerated())
      return;                                // Device not ready

   sav_ep=Usb_get_selected_endpoint();       // save actually pipe
   Usb_select_endpoint(EP_AUDIO_IN);
   if(!Is_usb_write_enabled())
   {
      Usb_select_endpoint(sav_ep);           // restore pipe
      return;                                // Endpoint not free
   }
   
   if( (b_micro_mute == FALSE)
   &&  (s16_micro_volume > 0 ) )
   {
      //** Acquires new sample (from on-board micro, from external source, or from sample in flash raw )
      if( Is_joy_down() )
      {
         // Play flash raw sample
#ifdef __GNUC__
         LSB(sample) = pgm_read_byte_near(&sample_sound[g_u16_micro_sample_pos++]);
         MSB(sample) = pgm_read_byte_near(&sample_sound[g_u16_micro_sample_pos++]);
#else
         LSB(sample) = sample_sound[g_u16_micro_sample_pos++];
         MSB(sample) = sample_sound[g_u16_micro_sample_pos++];
#endif
         if (g_u16_micro_sample_pos > SAMPLE_SOUND_LEN)
            g_u16_micro_sample_pos=0;        // end of sample sound, then run in a loop
      }
      else if( Is_joy_select() || Is_joy_up() )
      {
         // Get external input
         sample = (S32) (64*Get_adc_ext_val()-0x8000);
      }
      else
      {
         // All joystick directions released
         // Get micro input
         sample = (S32) (64*(Get_adc_mic_val()>>(7-(MSB(s16_micro_volume)>>4)))-0x8000);
      }
      // Send new sample
      Usb_write_byte(LSB(sample));
      Usb_write_byte(MSB(sample));
   }
   else
   {
      //** Mute enable then send new sample null
      Usb_write_byte(0);
      Usb_write_byte(0);
   }

   // If pipe full then send it   
   if (Usb_byte_counter()==EP_SIZE_IN)
   {
      Usb_send_in();
   }
   Usb_select_endpoint(sav_ep);              // restore pipe
}


//! @brief  Analog Channel 13 Acquisition routine (ADC)
//!
//! @note   User can choose to transmit a signal that is present on the free PB6 input (available on J4.7 of STK527)
//!         This can be used to do some measures from a pure sine wave sent on PB6 from an external generator.
//!
U16 Get_adc_ext_val(void)
{
   Start_conv_channel(0x25);
   while (!Is_adc_conv_finished());
   return (U16)(ADCL+((U16)(ADCH<<8)));
}


//! @brief Timer1 comparator interrupt routine service
//!
//! Get sample value from USB Isochronous endpoint and load it to the PWM
//!
//! @note The dual bank endpoint usage allows to get ride of an extra synchonisation buffer
//!
#ifdef __GNUC__
 ISR(TIMER1_COMPA_vect)
#else
#pragma vector = TIMER1_COMPA_vect
__interrupt void timer1_comp_a_interrupt()
#endif
{
   U16 sample;

   if(!Is_device_enumerated())
   {
      // Set PWM factor at 0 to remove the noise because the pll is disabled by USB
      Timerhs_set_compare_d( 0 );     
      return;  // Device not ready
   }

   // Check mute control
   if( b_speaker_mute )
   {
      Timerhs_set_compare_d( 0x400/4 );
      return;
   }

   // Read audio datas
   if( ptr_speaker_data_wr == ptr_speaker_data_rd )
      return; // no data avaliable
   LSB(sample) = *ptr_speaker_data_rd++;
   MSB(sample) = *ptr_speaker_data_rd++;
   if( ptr_speaker_data_rd == (g_buffer_speaker+BUFFER_SIZE) )
      ptr_speaker_data_rd = g_buffer_speaker;
   
   // Rescale audio datas :
   // - +0x8000, to change 16bits signed to 16bits unsigned
   // - >>7, to change 16bits to 9bits (Don't use all 10bits from PWM because the factor 100% isn't supported by AOP on STK527)
   // - >>9-(U8)s16_speaker_volume, the volume control discreases the value by 2 power.
   // And send audio datas in PWM
   Timerhs_set_compare_d( (((U16)sample+0x8000)>>7)>>(9-(U8)s16_speaker_volume) );
}

