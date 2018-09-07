/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief This file contains the low level macros and definition for the ADC
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

#ifndef ADC_DRV_H
#define ADC_DRV_H

//_____ I N C L U D E S ____________________________________________________

#ifndef  ADHSM
#define  ADHSM   7
#endif

//! @defgroup ADC_module ADC
//! ADC Module
//! @{
//_____ M A C R O S ________________________________________________________

#define ADC_ADC1_ADC0_x200          0x0B
#define ADC_ADC1_ADC0_x10           0x09
#define ADC_ADC1_ADC0_x40           0x26
#define ADC_TEMP_SENSOR_CHANNEL     0x27
#define ADC_GND_CHANNEL             0x1F
#define ADC_BG_CHANNEL              0x1E

   //! @defgroup ADC_macros ADC Macros
   //! Low level macros that permit the use of the ADC of the product.
   //! @{

      //! @defgroup Turn_on_adc Turn on the ADC
      //! Turn on the ADC
      //! @{
#define Enable_adc()                         (ADCSRA |= (1<<ADEN))
      //! @}

      //! @defgroup ADC_alignement_configuration ADC Alignement Configuration
      //! Configure the Result alignement
      //! @{
#define Right_adjust_adc_result()            (ADMUX  &= ~(1<<ADLAR))
#define Left_adjust_adc_result()             (ADMUX  |=  (1<<ADLAR))
      //! @}

      //! @defgroup ADC_high_speed_mode_configuration ADC High Speed Mode Configuration
      //! Set the high spped mode in case ADC frequency is higher than 200KHz
      //! @{
#define Enable_adc_high_speed_mode()         (ADCSRB |=  (1<<ADHSM))
#define Disable_adc_high_speed_mode()        (ADCSRB &= ~(1<<ADHSM))
      //! @}


      //! @defgroup ADC_vref_configuration ADC Vref Configuration
      //! Configure the Vref
      //! @{
#define Enable_internal_vref()               (ADMUX  |=  ((1<<REFS1)|(1<<REFS0)) )
#define Enable_external_vref()               (ADMUX  &= ~((1<<REFS1)|(1<<REFS0)) )
#define Enable_vcc_vref()                    (ADMUX  &= ~(1<<REFS1),          \
                                              ADMUX  |=  (1<<REFS0) )
      //! @}

      //! @defgroup ADC_it_configuration ADC IT Configuration
      //! Configure the ADC IT
      //! @{
#define Enable_all_it()                      (SREG   |=  (0x80) )
#define Disable_all_it()                     (SREG   &= ~(0x80) )
#define Enable_adc_it()                      (ADCSRA |=  (1<<ADIE) )
#define Disable_adc_it()                     (ADCSRA &= ~(1<<ADIE) )
#define Clear_adc_flag()                     (ADCSRA |=  (1<<ADIF) )
      //! @}

      //! @defgroup ADC_prescaler_configuration ADC Prescaler Configuration
      //! Configure the ADC prescaler
      //! @{
#define Set_adc_prescaler(prescaler)             (ADCSRA &= ~((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)),\
                                              ADCSRA |=  (prescaler) )
      //! @}

      //! @defgroup ADC_channel_selection ADC Channel Selection
      //! Select the ADC channel to be converted
      //! @{
#define MUX4_0_MSK                           ((1<<MUX4)|(1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0))
#define Clear_adc_mux()                      (ADMUX  &= ~((1<<MUX4)|(1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0)), ADCSRB &= ~(1<<MUX5) )
#define Select_adc_channel(channel)          (Clear_adc_mux(), ADMUX |= (channel&MUX4_0_MSK), ADCSRB |= (channel>>5)<<MUX5  )
      //! @}

      //! @defgroup ADC_start_conversion ADC Start Conversion
      //! Start the Analog to Digital Conversion
      //! @{

         //! @defgroup ADC_start_normal_conversion ADC Start Normal Conversion
         //! Start the conversion in normal mode
         //! @{
#define Start_conv()                          (ADCSRA |= (1<<ADSC) )
#define Start_conv_channel(channel)           (Select_adc_channel(channel), Start_conv() )
         //! @}

         //! @defgroup ADC_start_idle_conversion ADC Start Idle Conversion
         //! Start the Analog to Digital Conversion in noise reduction mode
         //! @{
#define Start_conv_idle()                    (SMCR   |=  (1<<SM0)|(1<<SE) )
#define Start_conv_idle_channel(channel)     (Select_adc_channel(channel), Start_conv_idle() )
#define Clear_sleep_mode()                   (SMCR   &= ~(1<<SM0)|(1<<SE) )
         //! @}

      //! @}

      //! @defgroup ADC_get_x_bits_result ADC Get x Bits Result
      //! ADC Get x Bits Result
      //! @{
#define Adc_get_8_bits_result()               ((U8)(ADCH))
#define Adc_get_10_bits_result()              ((U16)(ADCL+((U16)(ADCH<<8))))
      //! @}


      //! @defgroup Turn_off_adc Turn Off the ADC
      //! Turn Off the ADC
      //! @{
#define Disable_adc()                        (ADCSRA &= ~(1<<ADEN))
      //! @}

      //! @defgroup Check conversion is finished or not
      //! Check conversion status
      //! @{
#define Is_adc_conv_finished()               ((ADCSRA &  (1<<ADIF)) ? TRUE : FALSE)
#define Is_adc_conv_not_finished()           ((ADCSRA | ~(1<<ADIF)) ? TRUE : FALSE)
      //! @}

   //! @}

//_____ D E F I N I T I O N S ______________________________________________

//_____ F U N C T I O N S __________________________________________________
   //! @defgroup ADC_low_level_functions ADC Low Level Fucntions
   //! ADC Low Level Functions
   //! @{

//! Configures the ADC accordingly to the ADC Define Configuration values.
//! Take care that you have to select the ports which will be converted as
//! analog inputs thanks to the DIDR0 and DIDR1 registers.
//!
void init_adc(void);
   //! @}


//! @}

#endif  // ADC_DRV_H
