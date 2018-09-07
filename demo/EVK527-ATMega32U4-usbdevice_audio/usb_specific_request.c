/*This file has been prepared for Doxygen automatic documentation generation.*/
//! \file *********************************************************************
//!
//! \brief user call-back functions
//!
//!  This file contains the user call-back functions corresponding to the
//!  application:
//!  AUDIO MICROPHONE
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

#define TARGET_UNDEFINE 0
#define TARGET_SPEAKER  1
#define TARGET_MICRO    2

typedef struct {
  U8 target;   // audio target (speaker or micro)
  U8 cs;       // Command slector
} st_audio_cmd;


//_____ D E F I N I T I O N ________________________________________________

st_audio_cmd check_audio_control_request(void);


//_____ P R I V A T E   D E C L A R A T I O N ______________________________

#ifdef __GNUC__
extern PGM_VOID_P pbuffer;
#else
extern U8   code *pbuffer;
#endif
extern U8   data_to_transfer;

extern bit b_speaker_mute;
extern S16 s16_speaker_volume;
extern bit b_micro_mute;
extern S16 s16_micro_volume;


//_____ D E C L A R A T I O N ______________________________________________

//! @breif This function checks the specific request and if known then processes it
//!
//! @param type      corresponding at bmRequestType (see USB specification)
//! @param request   corresponding at bRequest (see USB specification)
//!
//! @return TRUE,  when the request is processed
//! @return FALSE, if the request is'nt know (STALL handshake is managed by the main standard request function).
//!
Bool usb_user_read_request(U8 type, U8 request)
{
   st_audio_cmd cmd;

   //** Specific request from Class Audio
   //* AudioControl Requests
   if( USB_SETUP_SET_CLASS_INTER == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_SET_CUR:
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case TARGET_SPEAKER:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_speaker_set_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_speaker_set_volume();
               return TRUE;
               break;
            }
            break;
            case TARGET_MICRO:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_micro_set_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_micro_set_volume();
               return TRUE;
               break;
            }
            break;
         }
         break;

         case SETUP_AUDIO_SET_MIN:
         case SETUP_AUDIO_SET_MAX:
         case SETUP_AUDIO_SET_RES:
         // TODO
         break;
      }
   }

   if( USB_SETUP_GET_CLASS_INTER == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_CUR:
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case TARGET_SPEAKER:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_speaker_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_speaker_get_vol_cur();
               return TRUE;
               break;
            }
            break;
            case TARGET_MICRO:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_micro_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_micro_get_vol_cur();
               return TRUE;
               break;
            }
            break;
         }
         break;
         
         case SETUP_AUDIO_GET_MIN:
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case TARGET_SPEAKER:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_speaker_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_speaker_get_vol_min();
               return TRUE;
               break;
            }
            break;
            case TARGET_MICRO:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_micro_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_micro_get_vol_min();
               return TRUE;
               break;
            }
            break;
         }
         break;
         
         case SETUP_AUDIO_GET_MAX:
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case TARGET_SPEAKER:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_speaker_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_speaker_get_vol_max();
               return TRUE;
               break;
            }
            break;
            case TARGET_MICRO:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_micro_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_micro_get_vol_max();
               return TRUE;
               break;
            }
            break;
         }
         break;
         
         case SETUP_AUDIO_GET_RES:
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case TARGET_SPEAKER:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_speaker_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_speaker_get_vol_res();
               return TRUE;
               break;
            }
            break;
            case TARGET_MICRO:
            switch( cmd.cs )
            {
               case AUDIO_FU_CONTROL_CS_MUTE:
               audio_micro_get_mute();
               return TRUE;
               break;
               case AUDIO_FU_CONTROL_CS_VOLUME:
               audio_micro_get_vol_res();
               return TRUE;
               break;
            }
            break;
         }
         break;
      }
   }
   
   //* AudioStreaming Requests
   if( USB_SETUP_SET_CLASS_ENDPOINT == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_SET_MEM:
         case SETUP_AUDIO_SET_MIN:
         case SETUP_AUDIO_SET_MAX:
         case SETUP_AUDIO_SET_RES:
         // TODO
         break;
      }
   }
   if( USB_SETUP_GET_CLASS_ENDPOINT == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_CUR:
         case SETUP_AUDIO_GET_MIN:
         case SETUP_AUDIO_GET_MAX:
         case SETUP_AUDIO_GET_RES:
         // TODO
         break;
      }
   }

   //* Additional Requests
   // Set Memory Request
   if( USB_SETUP_SET_CLASS_INTER == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_SET_MEM:
         // TODO
         break;
      }
   }
   if( USB_SETUP_SET_CLASS_ENDPOINT == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_SET_MEM:
         // TODO
         break;
      }
   }
   // Get Memory Request
   if( USB_SETUP_GET_CLASS_INTER == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_MEM:
         // TODO
         break;
      }
   }
   if( USB_SETUP_GET_CLASS_ENDPOINT == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_MEM:
         // TODO
         break;
      }
   }
   // Get Status Request
   if( USB_SETUP_GET_CLASS_INTER == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_STAT:
         // TODO
         break;
      }
   }
   if( USB_SETUP_GET_CLASS_ENDPOINT == type )
   {
      switch( request )
      {
         case SETUP_AUDIO_GET_STAT:
         // TODO
         break;
      }
   }
   
   return FALSE;
}


//! @brief This function configures the endpoints
//!
//! @param conf_nb configuration number choosed by USB host
//!
void usb_user_endpoint_init(U8 conf_nb)
{
  usb_configure_endpoint(EP_AUDIO_OUT,    \
                         TYPE_ISOCHRONOUS,\
                         DIRECTION_OUT,   \
                         SIZE_128,        \
                         TWO_BANKS,       \
                         NYET_ENABLED);

  usb_configure_endpoint(EP_AUDIO_IN,     \
                         TYPE_ISOCHRONOUS,\
                         DIRECTION_IN,    \
                         SIZE_16,         \
                         TWO_BANKS,       \
                         NYET_ENABLED);
}


//! This function fills the global descriptor
//!
//! @param type      corresponding at MSB of wValue (see USB specification)
//! @param string    corresponding at LSB of wValue (see USB specification)
//!
//! @return FALSE, if the global descriptor no filled
//!
Bool usb_user_get_descriptor(U8 type, U8 string)
{
   switch(type)
   {
      case DESCRIPTOR_STRING:
      switch (string)
      {
         case LANG_ID:
         data_to_transfer = sizeof (usb_user_language_id);
         pbuffer = &(usb_user_language_id.bLength);
         return TRUE;
         break;
         
         case MAN_INDEX:
         data_to_transfer = sizeof (usb_user_manufacturer_string_descriptor);
         pbuffer = &(usb_user_manufacturer_string_descriptor.bLength);
         return TRUE;
         break;
         
         case PROD_INDEX:
         data_to_transfer = sizeof (usb_user_product_string_descriptor);
         pbuffer = &(usb_user_product_string_descriptor.bLength);
         return TRUE;
         break;
         
         case SN_INDEX:
         data_to_transfer = sizeof (usb_user_serial_number);
         pbuffer = &(usb_user_serial_number.bLength);
         return TRUE;
         break;
      }
   }
   return FALSE;
}


//! Checks if the audio control request is a Feature Unit Control request for the good feature unit  and channel
//!
//! @return the target audio and the Control Selector from request 
//!
st_audio_cmd check_audio_control_request(void)
{
   st_audio_cmd cmd;
   U16 wValue;
   U16 wIndex;
   U16 length;

   LSB(wValue)=Usb_read_byte();
   MSB(wValue)=Usb_read_byte();
   LSB(wIndex)=Usb_read_byte();
   MSB(wIndex)=Usb_read_byte();
   LSB(length)=Usb_read_byte();
   MSB(length)=Usb_read_byte();
   Usb_ack_receive_setup();

   cmd.target = TARGET_UNDEFINE;
   cmd.cs     = AUDIO_FU_CONTROL_CS_UNDEFINED;
   
   // Note: The wValue field interpretation is qualified by the value in the wIndex field.
   // Check target of the command
   if( LSB(wIndex) == AC_INTERFACE_NB)
   {
      // The request is for the Feature Unit Control then
      // MSB(wIndex) = Feature Unit ID, LSB(wValue) = Channel Number (CN), MSB(wValue) = Control Selector (CS)
      cmd.cs = MSB(wValue);

      if( (MSB(wIndex) == SPEAKER_FEATURE_UNIT_ID)
      &&  (LSB(wValue) == 0) )
      {
         // for Master Channel of speaker
         cmd.target = TARGET_SPEAKER;

      }
      if( (MSB(wIndex) == MICRO_FEATURE_UNIT_ID)
      &&  (LSB(wValue) == 0) )
      {
         // for Master Channel of micro
         cmd.target = TARGET_MICRO;
      }
   }
   return cmd;
}

//******* Speaker control
void audio_speaker_set_mute(void)
{
   while(!Is_usb_receive_out());
   b_speaker_mute=Usb_read_byte();
   Usb_ack_receive_out();
   Usb_send_control_in();        // send a ZLP
}
void audio_speaker_get_mute(void)
{
   Usb_write_byte(b_speaker_mute);
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_speaker_set_volume(void)
{
   while(!Is_usb_receive_out());
   LSB(s16_speaker_volume)=Usb_read_byte();
   MSB(s16_speaker_volume)=Usb_read_byte();
   Usb_ack_receive_out();
   Usb_send_control_in();        // send a ZLP
}
void audio_speaker_get_vol_cur(void)
{
   Usb_write_byte(LSB(s16_speaker_volume));
   Usb_write_byte(MSB(s16_speaker_volume));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_speaker_get_vol_min(void)
{
   Usb_write_byte(LOW(SPEAKER_VOL_MIN));
   Usb_write_byte(HIGH(SPEAKER_VOL_MIN));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_speaker_get_vol_max(void)
{
   Usb_write_byte(LOW(SPEAKER_VOL_MAX));
   Usb_write_byte(HIGH(SPEAKER_VOL_MAX));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_speaker_get_vol_res(void)
{
   Usb_write_byte(LOW(SPEAKER_VOL_RES));
   Usb_write_byte(HIGH(SPEAKER_VOL_RES));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}


//******* Micro control
void audio_micro_set_mute(void)
{
   while(!Is_usb_receive_out());
   b_micro_mute=Usb_read_byte();
   Usb_ack_receive_out();
   Usb_send_control_in();        // send a ZLP
}
void audio_micro_get_mute(void)
{
   Usb_write_byte(b_micro_mute);
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_micro_set_volume(void)
{
   while(!Is_usb_receive_out());
   LSB(s16_micro_volume)=Usb_read_byte();
   MSB(s16_micro_volume)=Usb_read_byte();
   Usb_ack_receive_out();
   Usb_send_control_in();        // send a ZLP
}
void audio_micro_get_vol_cur(void)
{
   Usb_write_byte(LSB(s16_micro_volume));
   Usb_write_byte(MSB(s16_micro_volume));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_micro_get_vol_min(void)
{
   Usb_write_byte(LOW(MICRO_VOL_MIN));
   Usb_write_byte(HIGH(MICRO_VOL_MIN));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_micro_get_vol_max(void)
{
   Usb_write_byte(LOW(MICRO_VOL_MAX));
   Usb_write_byte(HIGH(MICRO_VOL_MAX));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
void audio_micro_get_vol_res(void)
{
   Usb_write_byte(LOW(MICRO_VOL_RES));
   Usb_write_byte(HIGH(MICRO_VOL_RES));
   Usb_send_control_in();
   while(!Is_usb_receive_out()); // send a ZLP
   Usb_ack_receive_out();
}
