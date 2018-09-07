/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief USB Identifers.
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

#ifndef _USB_USERCONFIG_H_
#define _USB_USERCONFIG_H_

//_____ I N C L U D E S ____________________________________________________

#include "config.h"
#include "modules/usb/device_chap9/usb_standard_request.h"
#include "conf_usb.h"

//_____ M A C R O S ________________________________________________________

#define  Usb_get_dev_desc_pointer()        (&(usb_dev_desc.bLength))
#define  Usb_get_dev_desc_length()         (sizeof (usb_dev_desc))
#define  Usb_get_conf_desc_pointer()       (&(usb_conf_desc.cfg.bLength))
#define  Usb_get_conf_desc_length()        (sizeof (usb_conf_desc))



//_____ U S B    D E F I N E _______________________________________________

                  // USB Device descriptor
#define  USB_SPECIFICATION             0x0200
#define  DEVICE_CLASS                  0        // each configuration has its own class
#define  DEVICE_SUB_CLASS              0        // each configuration has its own sub-class
#define  DEVICE_PROTOCOL               0        // each configuration has its own protocol
#define  EP_CONTROL_LENGTH             32
#define  VENDOR_ID                     VID_ATMEL
#define  PRODUCT_ID                    PID_MegaAUDIO_IN_OUT
#define  RELEASE_NUMBER                0x1000
#define  MAN_INDEX                     0x01
#define  PROD_INDEX                    0x02   
#define  SN_INDEX                      0x03
#define  NB_CONFIGURATION              1


               // USB mic configuration descriptor
#define  NB_INTERFACE                  3        // Audio Control + Audio Stream OUT (Speaker) + Audio Stream IN (Micro) interface
#define  CONF_NB                       1
#define  CONF_INDEX                    0
#define  CONF_ATTRIBUTES               USB_CONFIG_BUSPOWERED
#define  MAX_POWER                     50       // 100 mA
        
              // Standard Audio control (AC) interface descriptor
#define  AC_INTERFACE_NB               0        // Interface's number
#define  AC_ALTERNATE                  0
#define  AC_NB_ENDPOINT                0        // No endpoint for AC interface
#define  AC_INTERFACE_CLASS            AUDIO_CLASS
#define  AC_INTERFACE_SUB_CLASS        AUDIO_SUB_CLASS_CONTROL
#define  AC_INTERFACE_PROTOCOL         NO_PROTOCOL
#define  AC_INTERFACE_INDEX            0
        
              // USB Endpoint 1 for Audio stream Speaker
#define  ENDPOINT_NB_OUT               (EP_AUDIO_OUT | USB_ENDPOINT_OUT)
#define  EP_ATTRIBUTES_OUT             0x01     // BULK = 0x02, INTERUPT = 0x03
#define  EP_SIZE_OUT                   (128)
#define  EP_INTERVAL_OUT               0x01     // One packet per frame

              // USB Endpoint 1 for Audio stream Speaker
#define  ENDPOINT_NB_IN                (EP_AUDIO_IN | USB_ENDPOINT_IN)
#define  EP_ATTRIBUTES_IN              0x01     // BULK = 0x02, INTERUPT = 0x03
#define  EP_SIZE_IN                    16
#define  EP_INTERVAL_IN                0x01     // One packet per frame


//** AC interface descriptor Audio specific
#define  NB_OF_STREAMING_INTERFACE     0x02

             //* AC interface descriptor for speaker
             // Input Terminal descriptor
#define  SPEAKER_INPUT_TERMINAL_ID           0x01
#define  SPEAKER_INPUT_TERMINAL_TYPE         AUDIO_TE_TYPE_USB_STREAMING      // USB Streaming
#define  SPEAKER_INPUT_TERMINAL_ASSOCIATION  0x00                             // No association
#define  SPEAKER_INPUT_TERMINAL_NB_CHANNELS  0x01                             // 1 channel for input terminal
#define  SPEAKER_INPUT_TERMINAL_CHANNEL_CONF AUDIO_CHANNEL_NO_POSITION        // Mono sets no position
#define  SPEAKER_INPUT_TERMINAL_CH_NAME_ID   0x00                             // No channel name
#define  SPEAKER_INPUT_TERMINAL_NAME_ID      0x00                             // No terminal name
             // Feature Unit Control descriptor
#define  SPEAKER_FEATURE_UNIT_ID             0x02
#define  SPEAKER_FEATURE_UNIT_SOURCE_ID      SPEAKER_INPUT_TERMINAL_ID
#define  SPEAKER_FEATURE_UNIT_CTRL_CH_MASTER (AUDIO_FU_CONTROL_CS_MUTE|AUDIO_FU_CONTROL_CS_VOLUME) // Mute + Volume control on master channel
#define  SPEAKER_FEATURE_UNIT_CTRL_CH_1      0x00                             // No control on channel 1
             // Output Terminal descriptor
#define  SPEAKER_OUTPUT_TERMINAL_ID          0x03
#define  SPEAKER_OUTPUT_TERMINAL_TYPE        AUDIO_TE_TYPE_OUTPUT_SPEAKER     // Output terminal is a speaker
#define  SPEAKER_OUTPUT_TERMINAL_ASSOCIATION 0x00                             // No association
#define  SPEAKER_OUTPUT_TERMINAL_SOURCE_ID   SPEAKER_FEATURE_UNIT_ID          // From Feature Unit Terminal
#define  SPEAKER_OUTPUT_TERMINAL_NAME_ID     0x00                             // No terminal name

             //* AC interface descriptor for micro
             // Input Terminal descriptor
#define  MICRO_INPUT_TERMINAL_ID             0x04
#define  MICRO_INPUT_TERMINAL_TYPE           AUDIO_TE_TYPE_INPUT_MICROPHONE   // Terminal is microphone
#define  MICRO_INPUT_TERMINAL_ASSOCIATION    0x00                             // No association
#define  MICRO_INPUT_TERMINAL_NB_CHANNELS    0x01                             // One channel for input terminal
#define  MICRO_INPUT_TERMINAL_CHANNEL_CONF   AUDIO_CHANNEL_NO_POSITION        // Mono sets no position
#define  MICRO_INPUT_TERMINAL_CH_NAME_ID     0x00                             // No channel name
#define  MICRO_INPUT_TERMINAL_NAME_ID        0x00                             // No terminal name
             // Feature Unit Control descriptor
#define  MICRO_FEATURE_UNIT_ID               0x05
#define  MICRO_FEATURE_UNIT_SOURCE_ID        MICRO_INPUT_TERMINAL_ID
#define  MICRO_FEATURE_UNIT_CTRL_CH_MASTER   (AUDIO_FU_CONTROL_CS_MUTE|AUDIO_FU_CONTROL_CS_VOLUME) // Mute + Volume control on master channel
#define  MICRO_FEATURE_UNIT_CTRL_CH_1        0x00                             // No control on channel 1
             // Output Terminal descriptor
#define  MICRO_OUTPUT_TERMINAL_ID            0x06
#define  MICRO_OUTPUT_TERMINAL_TYPE          AUDIO_TE_TYPE_USB_STREAMING      // USB Streaming
#define  MICRO_OUTPUT_TERMINAL_ASSOCIATION   0x00                             // No association
#define  MICRO_OUTPUT_TERMINAL_SOURCE_ID     MICRO_FEATURE_UNIT_ID            // From Feature Unit Terminal
#define  MICRO_OUTPUT_TERMINAL_NAME_ID       0x00                             // No terminal name


             // Audio Streaming (AS) interface descriptor for speaker
#define  STD_AS_OUT_INTERFACE_NB             0x01                             // Index of Std AS Interface
             //Alternate O Audio Streaming (AS) interface descriptor         
#define  ALT0_AS_OUT_INTERFACE_INDEX         0x00                             // Index of Std AS interface Alt0
#define  ALT0_AS_OUT_NB_ENDPOINT             0x00                             // Nb od endpoints for alt0 interface
#define  ALT0_AS_OUT_INTERFACE_CLASS         AUDIO_CLASS                      // Audio class
#define  ALT0_AS_OUT_INTERFACE_SUB_CLASS     AUDIO_SUB_CLASS_STREAMING        // Audio streamn sub class
#define  ALT0_AS_OUT_INTERFACE_PROTOCOL      NO_PROTOCOL                      // Unused
             //Alternate 1 Audio Streaming (AS) interface descriptor         
#define  ALT1_AS_OUT_INTERFACE_INDEX         0x01                             // Index of Std AS interface Alt1
#define  ALT1_AS_OUT_NB_ENDPOINT             0x01                             // Nb od endpoints for alt1 interface
#define  ALT1_AS_OUT_INTERFACE_CLASS         AUDIO_CLASS                      // Audio class
#define  ALT1_AS_OUT_INTERFACE_SUB_CLASS     AUDIO_SUB_CLASS_STREAMING        // Audio streamn sub class
#define  ALT1_AS_OUT_INTERFACE_PROTOCOL      NO_PROTOCOL                      // Unused
             //AS general Interface descriptor                               
#define  AS_OUT_TERMINAL_LINK                SPEAKER_INPUT_TERMINAL_ID        // Unit Id of the output terminal
#define  AS_OUT_DELAY                        0x01                             // Interface delay
#define  AS_OUT_FORMAT_TAG                   AUDIO_FORMAT_TI_PCM              // PCM Format
             // Format type                                                  
#define  OUT_FORMAT_TYPE                     AUDIO_FORMAT_TYPE_I              // Format TypeI
#define  OUT_FORMAT_NB_CHANNELS              0x01                             // One Channel
#define  OUT_FORMAT_FRAME_SIZE               0x02                             // Two bytes per audio sample
#define  OUT_FORMAT_BIT_RESOLUTION           0x10                             // 16 bits per sample
#define  OUT_FORMAT_SAMPLE_FREQ_NB           0x01                             // One frequency supported
#if( SPEAKER_FREQUENCY == 44100 )
#define  OUT_FORMAT_LSBYTE_SAMPLE_FREQ       0xAC44                           // 0x00AC44 = 44.1kHz Sample frequency
#elif( SPEAKER_FREQUENCY == 32000 )
#define  OUT_FORMAT_LSBYTE_SAMPLE_FREQ       0x7D00                           // 0x007D00 = 32kHz Sample frequency
#elif( SPEAKER_FREQUENCY == 8000 )
#define  OUT_FORMAT_LSBYTE_SAMPLE_FREQ       0x1F40                           // 0x001F40 = 8kHz Sample frequency
#else
#error SPEAKER_FREQUENCY must be define in config.h
#endif
#define  OUT_FORMAT_MSBYTE_SAMPLE_FREQ       0x00                             // MsByte        
             //Audio endpoint specific descriptor field                      
#define  AUDIO_EP_OUT_ATRIBUTES              0x00                             // No sampling freq, no pitch, no pading
#define  AUDIO_EP_OUT_DELAY_UNIT             0x00                             // Unused
#define  AUDIO_EP_OUT_LOCK_DELAY             0x0000                           // Unused
                                                                             
                                                                             
             // Audio Streaming (AS) interface descriptor for micro          
#define  STD_AS_IN_INTERFACE_NB              0x02                             // Index of Std AS Interface
             //Alternate O Audio Streaming (AS) interface descriptor         
#define  ALT0_AS_IN_INTERFACE_INDEX          0x00                             // Index of Std AS interface Alt0
#define  ALT0_AS_IN_NB_ENDPOINT              0x00                             // Nb od endpoints for alt0 interface
#define  ALT0_AS_IN_INTERFACE_CLASS          AUDIO_CLASS                      // Audio class
#define  ALT0_AS_IN_INTERFACE_SUB_CLASS      AUDIO_SUB_CLASS_STREAMING        // Audio streamn sub class
#define  ALT0_AS_IN_INTERFACE_PROTOCOL       NO_PROTOCOL                      // Unused
             //Alternate 1 Audio Streaming (AS) interface descriptor         
#define  ALT1_AS_IN_INTERFACE_INDEX          0x01                             // Index of Std AS interface Alt1
#define  ALT1_AS_IN_NB_ENDPOINT              0x01                             // Nb od endpoints for alt1 interface
#define  ALT1_AS_IN_INTERFACE_CLASS          AUDIO_CLASS                      // Audio class
#define  ALT1_AS_IN_INTERFACE_SUB_CLASS      AUDIO_SUB_CLASS_STREAMING        // Audio streamn sub class
#define  ALT1_AS_IN_INTERFACE_PROTOCOL       NO_PROTOCOL                      // Unused
             //AS general Interface descriptor                               
#define  AS_IN_TERMINAL_LINK                 MICRO_OUTPUT_TERMINAL_ID         // Unit Id of the output terminal
#define  AS_IN_DELAY                         0x01                             // Interface delay
#define  AS_IN_FORMAT_TAG                    AUDIO_FORMAT_TI_PCM              // PCM Format
             // Format type                                                  
#define  IN_FORMAT_TYPE                      AUDIO_FORMAT_TYPE_I              // Format TypeI
#define  IN_FORMAT_NB_CHANNELS               0x01                             // One Channel
#define  IN_FORMAT_FRAME_SIZE                0x02                             // Two bytes per audio sample
#define  IN_FORMAT_BIT_RESOLUTION            0x10                             // 16 bits per sample
#define  IN_FORMAT_SAMPLE_FREQ_NB            0x01                             // One frequency supported
#define  IN_FORMAT_LSBYTE_SAMPLE_FREQ        0x1F40                           // 0x001F40=8kHz Sample frequency
#define  IN_FORMAT_MSBYTE_SAMPLE_FREQ        0x00                             // MsByte of 0x001F40       
             //Audio endpoint specific descriptor field                      
#define  AUDIO_EP_IN_ATRIBUTES               0x00                             // No sampling freq, no pitch, no pading
#define  AUDIO_EP_IN_DELAY_UNIT              0x00                             // Unused
#define  AUDIO_EP_IN_LOCK_DELAY              0x0000                           // Unused



#define  LANG_ID                             0x00
#define  DEVICE_STATUS                       DEVICE_STATUS_BUS_POWERED
#define  INTERFACE_STATUS                    0x00     // TBD


#define  USB_MN_LENGTH         5
#define  USB_MANUFACTURER_NAME \
{ Usb_unicode('A') \
, Usb_unicode('T') \
, Usb_unicode('M') \
, Usb_unicode('E') \
, Usb_unicode('L') \
}

#define  USB_PN_LENGTH         18
#define  USB_PRODUCT_NAME \
{ Usb_unicode('A') \
 ,Usb_unicode('V') \
 ,Usb_unicode('R') \
 ,Usb_unicode(' ') \
 ,Usb_unicode('U') \
 ,Usb_unicode('S') \
 ,Usb_unicode('B') \
 ,Usb_unicode(' ') \
 ,Usb_unicode('A') \
 ,Usb_unicode('U') \
 ,Usb_unicode('D') \
 ,Usb_unicode('I') \
 ,Usb_unicode('O') \
 ,Usb_unicode(' ') \
 ,Usb_unicode('D') \
 ,Usb_unicode('E') \
 ,Usb_unicode('M') \
 ,Usb_unicode('O') \
}

#define  USB_SN_LENGTH         0x05
#define  USB_SERIAL_NUMBER \
{ Usb_unicode('1') \
 ,Usb_unicode('.') \
 ,Usb_unicode('0') \
 ,Usb_unicode('.') \
 ,Usb_unicode('0') \
}
                           //Audio Channel Name
#define  AUDIO_CHANNEL_NAME \
{ Usb_unicode('A') \
, Usb_unicode('T') \
, Usb_unicode('M') \
, Usb_unicode('E') \
, Usb_unicode('L') \
}

#define  LANGUAGE_ID           0x0409


                  //! Usb Request
typedef struct
{
   U8    bmRequestType;       //!< Characteristics of the request
   U8    bRequest;            //!< Specific request
   U16   wValue;              //!< field that varies according to request
   U16   wIndex;              //!< field that varies according to request
   U16   wLength;             //!< Number of bytes to transfer if Data
}  S_UsbRequest;


                //! Usb Device Descriptor
typedef struct {
   U8    bLength;             //!< Size of this descriptor in bytes
   U8    bDescriptorType;     //!< DEVICE descriptor type
   U16   bscUSB;              //!< Binay Coded Decimal Spec. release
   U8    bDeviceClass;        //!< Class code assigned by the USB
   U8    bDeviceSubClass;     //!< Sub-class code assigned by the USB
   U8    bDeviceProtocol;     //!< Protocol code assigned by the USB
   U8    bMaxPacketSize0;     //!< Max packet size for EP0
   U16   idVendor;            //!< Vendor ID. ATMEL = 0x03EB
   U16   idProduct;           //!< Product ID assigned by the manufacturer
   U16   bcdDevice;           //!< Device release number
   U8    iManufacturer;       //!< Index of manu. string descriptor
   U8    iProduct;            //!< Index of prod. string descriptor
   U8    iSerialNumber;       //!< Index of S.N.  string descriptor
   U8    bNumConfigurations;  //!< Number of possible configurations
}  S_usb_device_descriptor;


          //! Usb Configuration Descriptor
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< CONFIGURATION descriptor type
   U16   wTotalLength;        //!< total length of data returned
   U8    bNumInterfaces;      //!< number of interfaces for this conf.
   U8    bConfigurationValue; //!< value for SetConfiguration resquest
   U8    iConfiguration;      //!< index of string descriptor
   U8    bmAttibutes;         //!< Configuration characteristics
   U8    MaxPower;            //!< maximum power consumption
}  S_usb_configuration_descriptor;


              //! Usb Interface Descriptor
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< INTERFACE descriptor type
   U8    bInterfaceNumber;    //!< Number of interface
   U8    bAlternateSetting;   //!< value to select alternate setting
   U8    bNumEndpoints;       //!< Number of EP except EP 0
   U8    bInterfaceClass;     //!< Class code assigned by the USB
   U8    bInterfaceSubClass;  //!< Sub-class code assigned by the USB
   U8    bInterfaceProtocol;  //!< Protocol code assigned by the USB
   U8    iInterface;          //!< Index of string descriptor
}  S_usb_interface_descriptor;


            //! A U D I O Specific
            //! Class-Specific AC Interface Descriptor
typedef struct {
   U8    bLength;             //!< Size of this descriptor in bytes
   U8    bDescriptorType;     //!< CS interface
   U8    bDescritorSubtype;   //!< HEADER Subtype 
   U16   bcdADC;              //!< Revision of class spec 
   U16   wTotalLength;        //!< Total size of class specific descriptor 
   U8    bInCollection;       //!< Number of streaming interface 
   U8    baInterface1;        //!< Interface number of the first AudioStreaming or MIDIStreaming interface in the Collection.
   U8    baInterface2;        //!< Interface number of the second AudioStreaming or MIDIStreaming interface in the Collection.
} S_usb_ac_interface_descriptor;

            //! Class-Specific Input Terminal Descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bTerminalID;
   U16   wTerminalType;
   U8    bAssocTerminal;
   U8    bNrChannels;
   U16   wChannelConfig;
   U8    iChannelNames;
   U8    iTerminal;
} S_usb_in_ter_descriptor;

            //! Class-Specific Feature Unit Descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bUnitID;
   U8    bSourceID;
   U8    bControSize;
   U8    bmaControlMaster;
   U8    bmaControlCh1;
} S_usb_feature_unit_descriptor_speaker;

            //! Class-Specific Feature Unit Descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bUnitID;
   U8    bSourceID;
   U8    bControSize;
   U8    bmaControlMaster;
   U8    bmaControlCh1;
} S_usb_feature_unit_descriptor_micro;

            //! Class-Specific Output Terminal Descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bTerminalID;
   U16   wTerminalType;
   U8    bAssocTerminal;
   U8    bSourceID;
   U8    iTerminal;
} S_usb_out_ter_descriptor;

            //! Class-Specific AS Interface Descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bTerminalLink;
   U8    bDelay;
   U16   wFormatTag;
} S_usb_as_interface_descriptor;

            //! Audio Format Type descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;
   U8    bFormatType;
   U8    bNrChannels;
   U8    bSubFrameSize;
   U8    bBitResolution;
   U8    bSampleFreqType;
   U16   wLsbyteiSamFreq;
   U8    bMsbyteiSamFreq;
} S_usb_format_type;

            //! Endpoint AUDIO Specific descriptor
typedef struct{
   U8    bLenght;
   U8    bDescriptorType;
   U8    bDescriptorSubType;   
   U8    bmAttributes;
   U8    bLockDelayUnits;
   U16   wLockDelay;
}S_usb_endpoint_audio_specific;

               //! Usb Audio Endpoint Descriptor
typedef struct {
   U8    bLength;             //!< Size of this descriptor in bytes
   U8    bDescriptorType;     //!< ENDPOINT descriptor type
   U8    bEndpointAddress;    //!< Address of the endpoint
   U8    bmAttributes;        //!< Endpoint's attributes
   U16   wMaxPacketSize;      //!< Maximum packet size for this EP
   U8    bInterval;           //!< Interval for polling EP in ms
   U8    bRefresh;
   U8    bSynAddress;
} S_usb_endpoint_audio_descriptor;

               //! Usb Endpoint Descriptor
typedef struct {
   U8    bLength;             //!< Size of this descriptor in bytes
   U8    bDescriptorType;     //!< ENDPOINT descriptor type
   U8    bEndpointAddress;    //!< Address of the endpoint
   U8    bmAttributes;        //!< Endpoint's attributes
   U16   wMaxPacketSize;      //!< Maximum packet size for this EP
   U8    bInterval;           //!< Interval for polling EP in ms
} S_usb_endpoint_descriptor;


               //! Usb Device Qualifier Descriptor
typedef struct {
   U8    bLength;             //!< Size of this descriptor in bytes
   U8    bDescriptorType;     //!< Device Qualifier descriptor type
   U16   bscUSB;              //!< Binay Coded Decimal Spec. release
   U8    bDeviceClass;        //!< Class code assigned by the USB
   U8    bDeviceSubClass;     //!< Sub-class code assigned by the USB
   U8    bDeviceProtocol;     //!< Protocol code assigned by the USB
   U8    bMaxPacketSize0;     //!< Max packet size for EP0
   U8    bNumConfigurations;  //!< Number of possible configurations
   U8    bReserved;           //!< Reserved for future use, must be zero
}  S_usb_device_qualifier_descriptor;


               //! Usb Language Descriptor
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< STRING descriptor type
   U16   wlangid;             //!< language id
}  S_usb_language_id;


//_____ U S B   M A N U F A C T U R E R   D E S C R I P T O R _______________


//struct usb_st_manufacturer
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< STRING descriptor type
   U16   wstring[USB_MN_LENGTH]; //!< unicode characters
} S_usb_manufacturer_string_descriptor;


//_____ U S B   P R O D U C T   D E S C R I P T O R _________________________


//struct usb_st_product
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< STRING descriptor type
   U16   wstring[USB_PN_LENGTH]; //!< unicode characters
} S_usb_product_string_descriptor;


//_____ U S B   S E R I A L   N U M B E R   D E S C R I P T O R _____________


//struct usb_st_serial_number
typedef struct {
   U8    bLength;             //!< size of this descriptor in bytes
   U8    bDescriptorType;     //!< STRING descriptor type
   U16   wstring[USB_SN_LENGTH]; //!< unicode characters
} S_usb_serial_number;


//_____ U S B   A U D I O   D E S C R I P T O R _____________________________

typedef struct
{
   S_usb_configuration_descriptor         cfg;
   S_usb_interface_descriptor             ifc;
   S_usb_ac_interface_descriptor          audioac;
   S_usb_in_ter_descriptor                speaker_in_ter;
   S_usb_feature_unit_descriptor_speaker  speaker_fea_unit;
   S_usb_out_ter_descriptor               speaker_out_ter;
   S_usb_in_ter_descriptor                mic_in_ter;
   S_usb_feature_unit_descriptor_micro    mic_fea_unit;
   S_usb_out_ter_descriptor               mic_out_ter;
   S_usb_interface_descriptor             speaker_as_alt0;   
   S_usb_interface_descriptor             speaker_as_alt1;   
   S_usb_as_interface_descriptor          speaker_g_as;
   S_usb_format_type                      speaker_format_type;
   S_usb_endpoint_audio_descriptor        speaker_ep1;
   S_usb_endpoint_audio_specific          speaker_ep1_s;
   S_usb_interface_descriptor             mic_as_alt0;   
   S_usb_interface_descriptor             mic_as_alt1;   
   S_usb_as_interface_descriptor          mic_g_as;
   S_usb_format_type                      mic_format_type;
   S_usb_endpoint_audio_descriptor        mic_ep1;
   S_usb_endpoint_audio_specific          mic_ep1_s;
} S_usb_user_configuration_descriptor;

#endif

