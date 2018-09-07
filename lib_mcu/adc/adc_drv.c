/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief This file contains the low level functions for the ADC
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

#ifdef USE_ADC //!< this define is set on config.h file
#include "adc_drv.h"

//_____ M A C R O S ________________________________________________________


//_____ P R I V A T E    D E C L A R A T I O N _____________________________


//_____ D E F I N I T I O N ________________________________________________


//_____ D E C L A R A T I O N ______________________________________________
//! Configures the ADC accordingly to the ADC Define Configuration values.
//! Take care that you have to select the ports which will be converted as
//! analog inputs thanks to the DIDR0 and DIDR1 registers.
//!
void init_adc(void)
{
    Enable_adc();
#   if (ADC_RIGHT_ADJUST_RESULT == 1)
       Right_adjust_adc_result();
#   elif (ADC_RIGHT_ADJUST_RESULT == 0)
       Left_adjust_adc_result();
#   else
#      error (ADC_RIGHT_ADJUST_RESULT should be 0 or 1... See config.h file)
#   endif

#   if (ADC_HIGH_SPEED_MODE == 1)
       Enable_adc_high_speed_mode();
#   elif (ADC_HIGH_SPEED_MODE == 0)
       Disable_adc_high_speed_mode();
#   else
#      error (ADC_HIGH_SPEED_MODE should be 0 or 1... See config.h file)
#   endif

#   if (ADC_INTERNAL_VREF == 2)
       Enable_vcc_vref();
#   elif (ADC_INTERNAL_VREF == 1)
       Enable_internal_vref();
#   elif (ADC_INTERNAL_VREF == 0)
       Enable_vcc_vref();
#   else
#      error (ADC_INTERNAL_VREF should be 0, 1 or 2... See config.h file)
#   endif

#   if (ADC_IT == 1)
       Enable_all_it();
       Enable_adc_it();
#   elif (ADC_IT == 0)
       Disable_adc_it();
#   else
#      error (ADC_IT should be 0 or 1... See config.h file)
#   endif

#   if (ADC_PRESCALER == 128)
       Set_adc_prescaler(7);
#   elif (ADC_PRESCALER == 64)
       Set_adc_prescaler(6);
#   elif (ADC_PRESCALER == 32)
       Set_adc_prescaler(5);
#   elif (ADC_PRESCALER == 16)
       Set_adc_prescaler(4);
#   elif (ADC_PRESCALER ==  8)
       Set_adc_prescaler( 3);
#   elif (ADC_PRESCALER ==  4)
       Set_adc_prescaler( 2);
#   elif (ADC_PRESCALER ==  2)
       Set_adc_prescaler( 1);
#   else
#      error (ADC_PRESCALER should be 2, 4, 8, 16, 32, 64 or 128... See config.h file)
#   endif
}

#endif // USE_ADC
