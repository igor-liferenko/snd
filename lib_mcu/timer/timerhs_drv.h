/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief This file contains the low level functions (drivers) of 10-bit High Speed timer
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

#ifndef _TIMERHS_DRV_H_
#define _TIMERHS_DRV_H_

//_____ I N C L U D E S ________________________________________________________

#include "config.h"

//_____ G E N E R A L    D E F I N I T I O N S _________________________________

   // IAR 5.11B patch ...
   #ifndef COM4D1
      #define COM4D1 3
   #endif
   #ifndef COM4D0
      #define COM4D0 2
   #endif
   //End IAR 5.11B patch


//_____ M A C R O S ____________________________________________________________

    // ---------- To order the loading (reading) of 16-bit registers
#define Timerhs_get_counter()       ( timerhs_get_counter() )        // c.f. "timerhs_drv.c" file
#define Timerhs_get_capture()       ( timerhs_get_capture() )        // c.f. "timerhs_drv.c" file
    // ---------- Two ways to have a look on the things
#define Timerhs_set_pwm_a(value)    ( Timerhs_set_compare_a(value) ) // c.f. above !
#define Timerhs_set_pwm_b(value)    ( Timerhs_set_compare_b(value) ) // c.f. above !
#define Timerhs_set_pwm_c(value)    ( Timerhs_set_compare_c(value) ) // c.f. above !
#define Timerhs_get_pwm_a()         ( Timerhs_get_compare_a() )      // c.f. above !
#define Timerhs_get_pwm_b()         ( Timerhs_get_compare_b() )      // c.f. above !
#define Timerhs_get_pwm_c()         ( Timerhs_get_compare_c() )      // c.f. above !
    // ---------- If no clock, the timer is off !
#define Timerhs_off()                 Timerhs_set_clock(TIMER16_NO_CLOCK)

//_____ D E F .  &   M A C R O S   for   H W   C O N F . _______________________

    //----- CARE WITH THE ORDER WHEN 16-BIT REGISTERS ARE READ
    //      ==================================================
    //----- For sensitive 16-bit registers (c.f. temporary reg), the macros are:
    //-----     *  Timerhs_get_nnn_low()
    //-----     *  Timerhs_get_nnn_high()
    //----- For instance, in your main, do not write:
    //-----     short_temp = ((Timerhs_get_nnn_high())<<8) | (Timerhs_get_nnn_low());
    //-----   or
    //-----     short_temp = (Timerhs_get_nnn_low()) | ((Timerhs_get_nnn_high())<<8);
    //-----   because IAR and ImageCraft doesn't evaluate the operandes in the same order!
    //-----
    //----- The good way to write a READ (load) sequence is in 2 times:
    //-----     short_temp  =  Timerhs_get_nnn_low();
    //-----     short_temp |= (Timerhs_get_nnn_high() << 8 );
    //-----
    //----- Otherwise a macro "Timerhs_get_nnn()" exits and call "timerhs_get_counter()" function

    // ---------- Macros
#       define Timerhs_clear()  ( TCCR4B=0, TCCR4A=0, TCCR4C=0, TCCR4D=0, TCCR4E=0,TC4H=0, TCNT4= 0,\
                                  TC4H=0, OCR4A=0, \
                                  TC4H=0, OCR4B=0, \
                                  TC4H=0, OCR4D=0\
                                )
        // ----------
#       define Timerhs_set_synchronous_mode()   PLL_SET_HS_TMR_PSCAL_NULL


        // ----------
#       define Timerhs_set_counter(value)       ( TC4H = ((U8)((value)>>8)), TCNT4L = ((U8)(value)))
#       define Timerhs_get_counter_low()        ((U16)(TCNT4))
#       define Timerhs_get_counter_high()       ((U16)(TC4H))
        // ----------
#       define Timerhs_set_compare_a(value)     ( TC4H = ((U16)((value)>>8)), OCR4A = ((U8)(value)))
#       define Timerhs_set_compare_b(value)     ( TC4H = ((U16)((value)>>8)), OCR4B = ((U8)(value)))
#       define Timerhs_set_compare_c(value)     ( TC4H = ((U16)((value)>>8)), OCR4C = ((U8)(value)))
#       define Timerhs_set_top(value)           Timerhs_set_compare_c(value)
#       define Timerhs_set_nb_bit(n)            Timerhs_set_compare_c((U16)((1<<n)-1))
#       define Timerhs_set_compare_d(value)     ( TC4H = ((U8)((value)>>8)), OCR4D = ((U8)(value)))
#       define Timerhs_get_compare_a()          ( (U16)OCR4A|TC4H<<8 )      
#       define Timerhs_get_compare_b()          ( (U16)OCR4B|TC4H<<8 )      
#       define Timerhs_get_compare_d()          ( (U16)OCR4D|TC4H<<8 )      
        // ----------
#       define Timerhs_enable_pwm_a()           (DDRC|=0x80, TCCR4A |= (1<<COM4A1), TCCR4A |= (1<<PWM4A))
#       define Timerhs_enable_pwm_b()           (DDRB|=0x40, TCCR4A |= (1<<COM4B1), TCCR4A |= (1<<PWM4B))
#       define Timerhs_enable_pwm_d()           (DDRD|=0x80, TCCR4C |= (1<<COM4D1), TCCR4C |= (1<<PWM4D))

#       define Timerhs_enable_pwm_a_and_na()    (DDRC|=0xC0, TCCR4A |= (1<<COM4A0), TCCR4A |= (1<<PWM4A))
#       define Timerhs_enable_pwm_b_and_nb()    (DDRB|=0x60, TCCR4A |= (1<<COM4B0), TCCR4A |= (1<<PWM4B))
#       define Timerhs_enable_pwm_d_and_nd()    (DDRD|=0xC0, TCCR4C |= (1<<COM4D0), TCCR4C |= (1<<PWM4D))

#       define Timerhs_set_enhanced_pwm_mode()  (TCCRAE |= (1<<ENHC4))

        // ----------
#       define Timerhs_set_waveform_mode(conf)  ( TCCR4D = (TCCR4A & (~((1<<WGM41)|(1<<WGM40)))) | ((conf &  0x3) ))
        // ----------
#       define Timerhs_set_clock(value)        ( TCCR4B = (TCCR4B & (~TIMERHS_CLK_MASK)) | (value)  )
#       define Timerhs_get_clock()             (((TCCR4B & TIMERHS_CLK_MASK) )
        // ----------


//_____ T I M E R   D E F I N I T I O N S ______________________________________

    // ---------- Pre-definitions for "conf" field for Timerhs_set_waveform_mode(conf) macro
#define TIMERHS_WGM_NORMAL                   (0)
#define TIMERHS_WGM_FAST_PWM                 (0)
#define TIMERHS_WGM_PHASEFREQCORRECT_PWM     (1)
#define TIMERHS_WGM_PWM6_SINGLE_SLOPE        (2)
#define TIMERHS_WGM_PWM6_DUAL_SLOPE          (3)


    // ---------- Pre-definitions for "value" field for Timerhs_set_clock(value) macro
#define TIMERHS_NO_CLOCK                  (0)
#define TIMERHS_CLK_BY_1                  (1)
#define TIMERHS_CLK_BY_2                  (2)
#define TIMERHS_CLK_BY_4                  (3)
#define TIMERHS_CLK_BY_8                  (4)
#define TIMERHS_CLK_BY_16                 (5)
#define TIMERHS_CLK_BY_32                 (6)
#define TIMERHS_CLK_BY_64                 (7)
#define TIMERHS_CLK_BY_128                (8)
#define TIMERHS_CLK_BY_256                (9)
#define TIMERHS_CLK_BY_512                (10)
#define TIMERHS_CLK_BY_1024               (11)
#define TIMERHS_CLK_BY_2048               (12)
#define TIMERHS_CLK_BY_4096               (13)
#define TIMERHS_CLK_BY_8192               (14)
#define TIMERHS_CLK_BY_16384              (15)

#define TIMERHS_CLK_MASK                  ((1<<CS43) | (1<<CS42) |(1<<CS41) |(1<<CS40) )

//_____ D E C L A R A T I O N S ________________________________________________

//------------------------------------------------------------------------------
//  @fn timerhs_get_counter
//!
//! This function READ the 16-bit TIMER counter.
//!
//! @warning
//!
//! @param
//!
//! @return 16-bit counter value
//!
extern  U16 timerhs_get_counter(void);

//------------------------------------------------------------------------------
//  @fn timerhs_get_capture
//!
//! This function READ the 16-bit TIMER capture register.
//!
//! @warning
//!
//! @param
//!
//! @return 16-bit capture value
//!
extern  U16 timerhs_get_capture(void);

//______________________________________________________________________________

#endif  // _TIMERHS_DRV_H_































