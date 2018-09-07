/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief USB parameters.
//!
//!  This file contains the usb parameters that uniquely identify the
//!  application through descriptor tables.
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


//_____ I N C L U D E S ____________________________________________________

#include "config.h"
#include "conf_usb.h"

#include "lib_mcu/usb/usb_drv.h"
#include "usb_descriptors.h"
#include "modules/usb/device_chap9/usb_standard_request.h"
#include "usb_specific_request.h"


//_____ M A C R O S ________________________________________________________




//_____ D E F I N I T I O N ________________________________________________

// usb_user_device_descriptor
code S_usb_device_descriptor usb_dev_desc =
{
  sizeof(usb_dev_desc)
, DESCRIPTOR_DEVICE
, Usb_write_word_enum_struc(USB_SPECIFICATION)
, DEVICE_CLASS
, DEVICE_SUB_CLASS
, DEVICE_PROTOCOL
, EP_CONTROL_LENGTH
, Usb_write_word_enum_struc(VENDOR_ID)
, Usb_write_word_enum_struc(PRODUCT_ID)
, Usb_write_word_enum_struc(RELEASE_NUMBER)
, MAN_INDEX
, PROD_INDEX
, SN_INDEX
, NB_CONFIGURATION
};

// usb_user_configuration_descriptor FS
code S_usb_user_configuration_descriptor usb_conf_desc = {
 { sizeof(S_usb_configuration_descriptor)
 , DESCRIPTOR_CONFIGURATION
 , Usb_write_word_enum_struc(sizeof(S_usb_user_configuration_descriptor))
 , NB_INTERFACE
 , CONF_NB
 , CONF_INDEX
 , CONF_ATTRIBUTES
 , MAX_POWER
 }
 ,
 
 //** The first interface is the Control Audio Interface
 // The AudioControl (AC) interface descriptors contain all relevant information to fully characterize the corresponding audio function.
 { sizeof(S_usb_interface_descriptor)
 , DESCRIPTOR_INTERFACE
 , AC_INTERFACE_NB
 , AC_ALTERNATE
 , AC_NB_ENDPOINT
 , AC_INTERFACE_CLASS
 , AC_INTERFACE_SUB_CLASS
 , AC_INTERFACE_PROTOCOL
 , AC_INTERFACE_INDEX
 }
 ,
 // Class-Specific AC Interface Descriptor
 { sizeof(S_usb_ac_interface_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_HEADER
 ,Usb_write_word_enum_struc(AUDIO_CLASS_REVISION)
 ,Usb_write_word_enum_struc(sizeof(S_usb_ac_interface_descriptor)\
               +sizeof(S_usb_in_ter_descriptor)+sizeof(S_usb_feature_unit_descriptor_speaker)+sizeof(S_usb_out_ter_descriptor)\
               +sizeof(S_usb_in_ter_descriptor)+sizeof(S_usb_feature_unit_descriptor_micro)+sizeof(S_usb_out_ter_descriptor))
 ,NB_OF_STREAMING_INTERFACE
 ,STD_AS_IN_INTERFACE_NB
 ,STD_AS_OUT_INTERFACE_NB
 }
 ,
 
 //* Desccriptors for speaker
 // Class-Specific Input Terminal Descriptor
 { sizeof(S_usb_in_ter_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_INPUT_TERMINAL
 ,SPEAKER_INPUT_TERMINAL_ID
 ,Usb_write_word_enum_struc(SPEAKER_INPUT_TERMINAL_TYPE)
 ,SPEAKER_INPUT_TERMINAL_ASSOCIATION
 ,SPEAKER_INPUT_TERMINAL_NB_CHANNELS
 ,SPEAKER_INPUT_TERMINAL_CHANNEL_CONF
 ,SPEAKER_INPUT_TERMINAL_CH_NAME_ID
 ,SPEAKER_INPUT_TERMINAL_NAME_ID
 }
 ,
 // Class-Specific Feature Unit Descriptor
 { sizeof(S_usb_feature_unit_descriptor_speaker)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_FEATURE_UNIT
 ,SPEAKER_FEATURE_UNIT_ID
 ,SPEAKER_FEATURE_UNIT_SOURCE_ID
 ,0x01
 ,SPEAKER_FEATURE_UNIT_CTRL_CH_MASTER
 ,SPEAKER_FEATURE_UNIT_CTRL_CH_1
 }
 ,
 // Class-Specific Output Terminal Descriptor
 { sizeof(S_usb_out_ter_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_OUTPUT_TERMINAL
 ,SPEAKER_OUTPUT_TERMINAL_ID
 ,Usb_write_word_enum_struc(SPEAKER_OUTPUT_TERMINAL_TYPE)
 ,SPEAKER_OUTPUT_TERMINAL_ASSOCIATION
 ,SPEAKER_OUTPUT_TERMINAL_SOURCE_ID
 ,SPEAKER_OUTPUT_TERMINAL_NAME_ID
 }
 ,
 //* Desccriptors for micro
 // Class-Specific Input Terminal Descriptor
 { sizeof(S_usb_in_ter_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_INPUT_TERMINAL
 ,MICRO_INPUT_TERMINAL_ID
 ,Usb_write_word_enum_struc(MICRO_INPUT_TERMINAL_TYPE)
 ,MICRO_INPUT_TERMINAL_ASSOCIATION
 ,MICRO_INPUT_TERMINAL_NB_CHANNELS
 ,MICRO_INPUT_TERMINAL_CHANNEL_CONF
 ,MICRO_INPUT_TERMINAL_CH_NAME_ID
 ,MICRO_INPUT_TERMINAL_NAME_ID
 }
 ,
 // Class-Specific Feature Unit Descriptor
 { sizeof(S_usb_feature_unit_descriptor_micro)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_FEATURE_UNIT
 ,MICRO_FEATURE_UNIT_ID
 ,MICRO_FEATURE_UNIT_SOURCE_ID
 ,0x01
 ,MICRO_FEATURE_UNIT_CTRL_CH_MASTER
 ,MICRO_FEATURE_UNIT_CTRL_CH_1
 }
 ,
 // Class-Specific Output Terminal Descriptor
 { sizeof(S_usb_out_ter_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AC_OUTPUT_TERMINAL
 ,MICRO_OUTPUT_TERMINAL_ID
 ,Usb_write_word_enum_struc(MICRO_OUTPUT_TERMINAL_TYPE)
 ,MICRO_OUTPUT_TERMINAL_ASSOCIATION
 ,MICRO_OUTPUT_TERMINAL_SOURCE_ID
 ,MICRO_OUTPUT_TERMINAL_NAME_ID
 }
 ,
 
 //** The second interface is the Audio Stream Interface for Speaker (with two alternate interface)
 // Standard AS Interface Descriptor (Alternate 0 without endpoint)
 { sizeof(S_usb_interface_descriptor)
 ,DESCRIPTOR_INTERFACE
 ,STD_AS_OUT_INTERFACE_NB
 ,ALT0_AS_OUT_INTERFACE_INDEX
 ,ALT0_AS_OUT_NB_ENDPOINT
 ,ALT0_AS_OUT_INTERFACE_CLASS
 ,ALT0_AS_OUT_INTERFACE_SUB_CLASS
 ,ALT0_AS_OUT_INTERFACE_PROTOCOL
 ,0x00
 }
 ,
 // Standard AS Interface Descriptor (Alternate 1 with 1 endpoint)
 { sizeof(S_usb_interface_descriptor)
 ,DESCRIPTOR_INTERFACE
 ,STD_AS_OUT_INTERFACE_NB
 ,ALT1_AS_OUT_INTERFACE_INDEX
 ,ALT1_AS_OUT_NB_ENDPOINT
 ,ALT1_AS_OUT_INTERFACE_CLASS
 ,ALT1_AS_OUT_INTERFACE_SUB_CLASS
 ,ALT1_AS_OUT_INTERFACE_PROTOCOL
 ,0x00
 }
 ,
 // Class-Specific AS Interface Descriptor
 { sizeof(S_usb_as_interface_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AS_GENERAL
 ,AS_OUT_TERMINAL_LINK
 ,AS_OUT_DELAY
 ,Usb_write_word_enum_struc(AS_OUT_FORMAT_TAG)
 }
 ,
 { sizeof(S_usb_format_type)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AS_FORMAT_TYPE
 ,OUT_FORMAT_TYPE
 ,OUT_FORMAT_NB_CHANNELS
 ,OUT_FORMAT_FRAME_SIZE
 ,OUT_FORMAT_BIT_RESOLUTION
 ,OUT_FORMAT_SAMPLE_FREQ_NB
 ,Usb_write_word_enum_struc(OUT_FORMAT_LSBYTE_SAMPLE_FREQ)
 ,OUT_FORMAT_MSBYTE_SAMPLE_FREQ
 }
 ,
 { sizeof(S_usb_endpoint_audio_descriptor)
 , DESCRIPTOR_ENDPOINT
 , ENDPOINT_NB_OUT
 , EP_ATTRIBUTES_OUT
 , Usb_write_word_enum_struc(EP_SIZE_OUT)
 , EP_INTERVAL_OUT
 , 0x00
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_specific)
 ,DESCRIPTOR_AUDIO_ENDPOINT
 ,DESCRIPTOR_SUBTYPE_AUDIO_ENDP_GENERAL
 ,AUDIO_EP_OUT_ATRIBUTES
 ,AUDIO_EP_OUT_DELAY_UNIT
 ,Usb_write_word_enum_struc(AUDIO_EP_OUT_LOCK_DELAY)
 }
 ,
 
 //** The thirh interface is the Audio Stream Interface for Micro (with two alternate interface)
 // Standard AS Interface Descriptor (Alternate 0 without endpoint)
 { sizeof(S_usb_interface_descriptor)
 ,DESCRIPTOR_INTERFACE
 ,STD_AS_IN_INTERFACE_NB
 ,ALT0_AS_IN_INTERFACE_INDEX
 ,ALT0_AS_IN_NB_ENDPOINT
 ,ALT0_AS_IN_INTERFACE_CLASS
 ,ALT0_AS_IN_INTERFACE_SUB_CLASS
 ,ALT0_AS_IN_INTERFACE_PROTOCOL
 ,0x00
 }
 ,
 // Standard AS Interface Descriptor (Alternate 1 with 1 endpoint)
 { sizeof(S_usb_interface_descriptor)
 ,DESCRIPTOR_INTERFACE
 ,STD_AS_IN_INTERFACE_NB
 ,ALT1_AS_IN_INTERFACE_INDEX
 ,ALT1_AS_IN_NB_ENDPOINT
 ,ALT1_AS_IN_INTERFACE_CLASS
 ,ALT1_AS_IN_INTERFACE_SUB_CLASS
 ,ALT1_AS_IN_INTERFACE_PROTOCOL
 ,0x00
 }
 ,
 // Class-Specific AS Interface Descriptor
 { sizeof(S_usb_as_interface_descriptor)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AS_GENERAL
 ,AS_IN_TERMINAL_LINK
 ,AS_IN_DELAY
 ,Usb_write_word_enum_struc(AS_IN_FORMAT_TAG)
 }
 ,
 { sizeof(S_usb_format_type)
 ,DESCRIPTOR_AUDIO_INTERFACE
 ,DESCRIPTOR_SUBTYPE_AUDIO_AS_FORMAT_TYPE
 ,IN_FORMAT_TYPE
 ,IN_FORMAT_NB_CHANNELS
 ,IN_FORMAT_FRAME_SIZE
 ,IN_FORMAT_BIT_RESOLUTION
 ,IN_FORMAT_SAMPLE_FREQ_NB
 ,Usb_write_word_enum_struc(IN_FORMAT_LSBYTE_SAMPLE_FREQ)
 ,IN_FORMAT_MSBYTE_SAMPLE_FREQ
 }
 ,
 { sizeof(S_usb_endpoint_audio_descriptor)
 , DESCRIPTOR_ENDPOINT
 , ENDPOINT_NB_IN
 , EP_ATTRIBUTES_IN
 , Usb_write_word_enum_struc(EP_SIZE_IN)
 , EP_INTERVAL_IN
 , 0x00
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_specific)
 ,DESCRIPTOR_AUDIO_ENDPOINT
 ,DESCRIPTOR_SUBTYPE_AUDIO_ENDP_GENERAL
 ,AUDIO_EP_IN_ATRIBUTES
 ,AUDIO_EP_IN_DELAY_UNIT
 ,Usb_write_word_enum_struc(AUDIO_EP_IN_LOCK_DELAY)
 } 
};



                                      // usb_user_manufacturer_string_descriptor
code S_usb_manufacturer_string_descriptor usb_user_manufacturer_string_descriptor = {
  sizeof(usb_user_manufacturer_string_descriptor)
, DESCRIPTOR_STRING
, USB_MANUFACTURER_NAME
};


                                      // usb_user_product_string_descriptor

code S_usb_product_string_descriptor usb_user_product_string_descriptor = {
  sizeof(usb_user_product_string_descriptor)
, DESCRIPTOR_STRING
, USB_PRODUCT_NAME
};


                                      // usb_user_serial_number

code S_usb_serial_number usb_user_serial_number = {
  sizeof(usb_user_serial_number)
, DESCRIPTOR_STRING
, USB_SERIAL_NUMBER
};


                                      // usb_user_language_id

code S_usb_language_id usb_user_language_id = {
  sizeof(usb_user_language_id)
, DESCRIPTOR_STRING
, Usb_write_word_enum_struc(LANGUAGE_ID)
};




