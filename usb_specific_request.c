typedef float Float16;

typedef unsigned char U8 ;
typedef unsigned short U16;
typedef unsigned long U32;
typedef signed char S8 ;
typedef signed short S16;
typedef long S32;



typedef unsigned char Bool;


typedef U8 Status;
typedef Bool Status_bool;
typedef unsigned char Uchar;


typedef unsigned char Uint8;
typedef unsigned int Uint16;
typedef unsigned long int Uint32;

typedef char Int8;
typedef int Int16;
typedef long int Int32;

typedef unsigned char Byte;
typedef unsigned int Word;
typedef unsigned long int DWord;

typedef union
{
  Uint32 dw;
  Uint16 w[2];
  Uint8 b[4];
} Union32;

typedef union
{
  Uint16 w;
  Uint8 b[2];
} Union16;
typedef char p_uart_ptchar;
typedef char r_uart_ptchar;
#include  <avr/interrupt.h>
#include  <avr/pgmspace.h>
#include  <avr/io.h>
U8 flash_read_sig(unsigned long adr);







U8 flash_read_fuse(unsigned long adr);
   U16 Get_adc_mic_val(void);
   U16 Get_adc_temp_val(void);
   S16 Read_temperature(void);
extern void suspend_action(void);
typedef enum endpoint_parameter{ep_num, ep_type, ep_direction, ep_size, ep_bank, nyet_status} t_endpoint_parameter;
U8 usb_config_ep (U8, U8);
U8 usb_select_enpoint_interrupt (void);
U16 usb_get_nb_byte_epw (void);
U8 usb_send_packet (U8 , U8*, U8);
U8 usb_read_packet (U8 , U8*, U8);
void usb_halt_endpoint (U8);
void usb_reset_endpoint (U8);
U8 usb_init_device (void);
extern volatile U16 g_usb_event;
extern U8 g_usb_mode;
extern U8 usb_remote_wup_feature;
void usb_task_init (void);
void usb_task (void);

extern volatile U8 private_sof_counter;
void usb_process_request( void);










void usb_generate_remote_wakeup(void);

extern U8 usb_configuration_nb;
extern U8 remote_wakeup_feature;
typedef struct
{
   U8 bmRequestType;
   U8 bRequest;
   U16 wValue;
   U16 wIndex;
   U16 wLength;
} S_UsbRequest;



typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 bscUSB;
   U8 bDeviceClass;
   U8 bDeviceSubClass;
   U8 bDeviceProtocol;
   U8 bMaxPacketSize0;
   U16 idVendor;
   U16 idProduct;
   U16 bcdDevice;
   U8 iManufacturer;
   U8 iProduct;
   U8 iSerialNumber;
   U8 bNumConfigurations;
} S_usb_device_descriptor;



typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 wTotalLength;
   U8 bNumInterfaces;
   U8 bConfigurationValue;
   U8 iConfiguration;
   U8 bmAttibutes;
   U8 MaxPower;
} S_usb_configuration_descriptor;



typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U8 bInterfaceNumber;
   U8 bAlternateSetting;
   U8 bNumEndpoints;
   U8 bInterfaceClass;
   U8 bInterfaceSubClass;
   U8 bInterfaceProtocol;
   U8 iInterface;
} S_usb_interface_descriptor;




typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U8 bDescritorSubtype;
   U16 bcdADC;
   U16 wTotalLength;
   U8 bInCollection;
   U8 baInterface1;
   U8 baInterface2;
} S_usb_ac_interface_descriptor;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bTerminalID;
   U16 wTerminalType;
   U8 bAssocTerminal;
   U8 bNrChannels;
   U16 wChannelConfig;
   U8 iChannelNames;
   U8 iTerminal;
} S_usb_in_ter_descriptor;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bUnitID;
   U8 bSourceID;
   U8 bControSize;
   U8 bmaControlMaster;
   U8 bmaControlCh1;
} S_usb_feature_unit_descriptor_speaker;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bUnitID;
   U8 bSourceID;
   U8 bControSize;
   U8 bmaControlMaster;
   U8 bmaControlCh1;
} S_usb_feature_unit_descriptor_micro;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bTerminalID;
   U16 wTerminalType;
   U8 bAssocTerminal;
   U8 bSourceID;
   U8 iTerminal;
} S_usb_out_ter_descriptor;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bTerminalLink;
   U8 bDelay;
   U16 wFormatTag;
} S_usb_as_interface_descriptor;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bFormatType;
   U8 bNrChannels;
   U8 bSubFrameSize;
   U8 bBitResolution;
   U8 bSampleFreqType;
   U16 wLsbyteiSamFreq;
   U8 bMsbyteiSamFreq;
} S_usb_format_type;


typedef struct{
   U8 bLenght;
   U8 bDescriptorType;
   U8 bDescriptorSubType;
   U8 bmAttributes;
   U8 bLockDelayUnits;
   U16 wLockDelay;
}S_usb_endpoint_audio_specific;


typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U8 bEndpointAddress;
   U8 bmAttributes;
   U16 wMaxPacketSize;
   U8 bInterval;
   U8 bRefresh;
   U8 bSynAddress;
} S_usb_endpoint_audio_descriptor;


typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U8 bEndpointAddress;
   U8 bmAttributes;
   U16 wMaxPacketSize;
   U8 bInterval;
} S_usb_endpoint_descriptor;



typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 bscUSB;
   U8 bDeviceClass;
   U8 bDeviceSubClass;
   U8 bDeviceProtocol;
   U8 bMaxPacketSize0;
   U8 bNumConfigurations;
   U8 bReserved;
} S_usb_device_qualifier_descriptor;



typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 wlangid;
} S_usb_language_id;






typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 wstring[ 5 ];
} S_usb_manufacturer_string_descriptor;






typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 wstring[ 18 ];
} S_usb_product_string_descriptor;






typedef struct {
   U8 bLength;
   U8 bDescriptorType;
   U16 wstring[ 0x05 ];
} S_usb_serial_number;




typedef struct
{
   S_usb_configuration_descriptor cfg;
   S_usb_interface_descriptor ifc;
   S_usb_ac_interface_descriptor audioac;
   S_usb_in_ter_descriptor speaker_in_ter;
   S_usb_feature_unit_descriptor_speaker speaker_fea_unit;
   S_usb_out_ter_descriptor speaker_out_ter;
   S_usb_in_ter_descriptor mic_in_ter;
   S_usb_feature_unit_descriptor_micro mic_fea_unit;
   S_usb_out_ter_descriptor mic_out_ter;
   S_usb_interface_descriptor speaker_as_alt0;
   S_usb_interface_descriptor speaker_as_alt1;
   S_usb_as_interface_descriptor speaker_g_as;
   S_usb_format_type speaker_format_type;
   S_usb_endpoint_audio_descriptor speaker_ep1;
   S_usb_endpoint_audio_specific speaker_ep1_s;
   S_usb_interface_descriptor mic_as_alt0;
   S_usb_interface_descriptor mic_as_alt1;
   S_usb_as_interface_descriptor mic_g_as;
   S_usb_format_type mic_format_type;
   S_usb_endpoint_audio_descriptor mic_ep1;
   S_usb_endpoint_audio_specific mic_ep1_s;
} S_usb_user_configuration_descriptor;



extern const  PROGMEM  S_usb_device_descriptor usb_dev_desc;
extern const  PROGMEM  S_usb_user_configuration_descriptor usb_conf_desc;
extern const  PROGMEM  S_usb_user_configuration_descriptor usb_other_conf_desc;
extern const  PROGMEM  S_usb_device_qualifier_descriptor usb_qual_desc;
extern const  PROGMEM  S_usb_manufacturer_string_descriptor usb_user_manufacturer_string_descriptor;
extern const  PROGMEM  S_usb_product_string_descriptor usb_user_product_string_descriptor;
extern const  PROGMEM  S_usb_serial_number usb_user_serial_number;
extern const  PROGMEM  S_usb_language_id usb_user_language_id;





Bool usb_user_read_request (U8, U8);
Bool usb_user_get_descriptor (U8 , U8);
void usb_user_endpoint_init (U8);


void audio_speaker_set_mute (void);
void audio_speaker_get_mute (void);
void audio_speaker_set_volume (void);
void audio_speaker_get_vol_cur (void);
void audio_speaker_get_vol_min (void);
void audio_speaker_get_vol_max (void);
void audio_speaker_get_vol_res (void);


void audio_micro_set_mute (void);
void audio_micro_get_mute (void);
void audio_micro_set_volume (void);
void audio_micro_get_vol_cur (void);
void audio_micro_get_vol_min (void);
void audio_micro_get_vol_max (void);
void audio_micro_get_vol_res (void);







typedef struct {
  U8 target;
  U8 cs;
} st_audio_cmd;




st_audio_cmd check_audio_control_request(void);





extern PGM_VOID_P pbuffer;
extern U8 data_to_transfer;

extern  U8  b_speaker_mute;
extern S16 s16_speaker_volume;
extern  U8  b_micro_mute;
extern S16 s16_micro_volume;
Bool usb_user_read_request(U8 type, U8 request)
{
   st_audio_cmd cmd;



   if(  ( (0<<7) | (1<<5) | (1) )  == type )
   {
      switch( request )
      {
         case  0x01 :
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case  1 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_speaker_set_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_speaker_set_volume();
               return  (1==1) ;
               break;
            }
            break;
            case  2 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_micro_set_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_micro_set_volume();
               return  (1==1) ;
               break;
            }
            break;
         }
         break;

         case  0x02 :
         case  0x03 :
         case  0x04 :

         break;
      }
   }

   if(  ( (1<<7) | (1<<5) | (1) )  == type )
   {
      switch( request )
      {
         case  0x81 :
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case  1 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_speaker_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_speaker_get_vol_cur();
               return  (1==1) ;
               break;
            }
            break;
            case  2 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_micro_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_micro_get_vol_cur();
               return  (1==1) ;
               break;
            }
            break;
         }
         break;

         case  0x82 :
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case  1 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_speaker_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_speaker_get_vol_min();
               return  (1==1) ;
               break;
            }
            break;
            case  2 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_micro_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_micro_get_vol_min();
               return  (1==1) ;
               break;
            }
            break;
         }
         break;

         case  0x83 :
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case  1 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_speaker_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_speaker_get_vol_max();
               return  (1==1) ;
               break;
            }
            break;
            case  2 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_micro_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_micro_get_vol_max();
               return  (1==1) ;
               break;
            }
            break;
         }
         break;

         case  0x84 :
         cmd = check_audio_control_request();
         switch( cmd.target )
         {
            case  1 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_speaker_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_speaker_get_vol_res();
               return  (1==1) ;
               break;
            }
            break;
            case  2 :
            switch( cmd.cs )
            {
               case  0x01 :
               audio_micro_get_mute();
               return  (1==1) ;
               break;
               case  0x02 :
               audio_micro_get_vol_res();
               return  (1==1) ;
               break;
            }
            break;
         }
         break;
      }
   }


   if(  ( (0<<7) | (1<<5) | (2) )  == type )
   {
      switch( request )
      {
         case  0x05 :
         case  0x02 :
         case  0x03 :
         case  0x04 :

         break;
      }
   }
   if(  ( (1<<7) | (1<<5) | (2) )  == type )
   {
      switch( request )
      {
         case  0x81 :
         case  0x82 :
         case  0x83 :
         case  0x84 :

         break;
      }
   }



   if(  ( (0<<7) | (1<<5) | (1) )  == type )
   {
      switch( request )
      {
         case  0x05 :

         break;
      }
   }
   if(  ( (0<<7) | (1<<5) | (2) )  == type )
   {
      switch( request )
      {
         case  0x05 :

         break;
      }
   }

   if(  ( (1<<7) | (1<<5) | (1) )  == type )
   {
      switch( request )
      {
         case  0x85 :

         break;
      }
   }
   if(  ( (1<<7) | (1<<5) | (2) )  == type )
   {
      switch( request )
      {
         case  0x85 :

         break;
      }
   }

   if(  ( (1<<7) | (1<<5) | (1) )  == type )
   {
      switch( request )
      {
         case  0xFF :

         break;
      }
   }
   if(  ( (1<<7) | (1<<5) | (2) )  == type )
   {
      switch( request )
      {
         case  0xFF :

         break;
      }
   }

   return  (0==1) ;
}






void usb_user_endpoint_init(U8 conf_nb)
{
  ( (UENUM = (U8)1 ) , usb_config_ep( ((1 <<6) | (0 <<1) | (0 )) , ((4 <<4) | (1 <<2) ) )) ;
  ( (UENUM = (U8)2 ) , usb_config_ep( ((1 <<6) | (0 <<1) | (1 )) , ((1 <<4) | (1 <<2) ) )) ;
}









Bool usb_user_get_descriptor(U8 type, U8 string)
{
   switch(type)
   {
      case  0x03 :
      switch (string)
      {
         case  0x00 :
         data_to_transfer = sizeof (usb_user_language_id);
         pbuffer = &(usb_user_language_id.bLength);
         return  (1==1) ;
         break;

         case  0x01 :
         data_to_transfer = sizeof (usb_user_manufacturer_string_descriptor);
         pbuffer = &(usb_user_manufacturer_string_descriptor.bLength);
         return  (1==1) ;
         break;

         case  0x02 :
         data_to_transfer = sizeof (usb_user_product_string_descriptor);
         pbuffer = &(usb_user_product_string_descriptor.bLength);
         return  (1==1) ;
         break;

         case  0x03 :
         data_to_transfer = sizeof (usb_user_serial_number);
         pbuffer = &(usb_user_serial_number.bLength);
         return  (1==1) ;
         break;
      }
   }
   return  (0==1) ;
}






st_audio_cmd check_audio_control_request(void)
{
   st_audio_cmd cmd;
   U16 wValue;
   U16 wIndex;
   U16 length;

   (((U8* )&wValue)[0]) = (UEDATX) ;
   (((U8* )&wValue)[1]) = (UEDATX) ;
   (((U8* )&wIndex)[0]) = (UEDATX) ;
   (((U8* )&wIndex)[1]) = (UEDATX) ;
   (((U8* )&length)[0]) = (UEDATX) ;
   (((U8* )&length)[1]) = (UEDATX) ;
   (UEINTX &= ~(1<<RXSTPI)) ;

   cmd.target =  0 ;
   cmd.cs =  0x00 ;



   if(  (((U8* )&wIndex)[0])  ==  0 )
   {


      cmd.cs =  (((U8* )&wValue)[1]) ;

      if( ( (((U8* )&wIndex)[1])  ==  0x02 )
      && ( (((U8* )&wValue)[0])  == 0) )
      {

         cmd.target =  1 ;

      }
      if( ( (((U8* )&wIndex)[1])  ==  0x05 )
      && ( (((U8* )&wValue)[0])  == 0) )
      {

         cmd.target =  2 ;
      }
   }
   return cmd;
}


void audio_speaker_set_mute(void)
{
   while(! (UEINTX&(1<<RXOUTI)) );
   b_speaker_mute= (UEDATX) ;
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
}
void audio_speaker_get_mute(void)
{
   (UEDATX = (U8)b_speaker_mute) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_speaker_set_volume(void)
{
   while(! (UEINTX&(1<<RXOUTI)) );
   (((U8* )&s16_speaker_volume)[0]) = (UEDATX) ;
   (((U8* )&s16_speaker_volume)[1]) = (UEDATX) ;
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
}
void audio_speaker_get_vol_cur(void)
{
   (UEDATX = (U8) (((U8* )&s16_speaker_volume)[0]) ) ;
   (UEDATX = (U8) (((U8* )&s16_speaker_volume)[1]) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_speaker_get_vol_min(void)
{
   (UEDATX = (U8) ((Uchar) 7 ) ) ;
   (UEDATX = (U8) ((Uchar)( 7 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_speaker_get_vol_max(void)
{
   (UEDATX = (U8) ((Uchar) 9 ) ) ;
   (UEDATX = (U8) ((Uchar)( 9 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_speaker_get_vol_res(void)
{
   (UEDATX = (U8) ((Uchar) 1 ) ) ;
   (UEDATX = (U8) ((Uchar)( 1 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}



void audio_micro_set_mute(void)
{
   while(! (UEINTX&(1<<RXOUTI)) );
   b_micro_mute= (UEDATX) ;
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
}
void audio_micro_get_mute(void)
{
   (UEDATX = (U8)b_micro_mute) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_micro_set_volume(void)
{
   while(! (UEINTX&(1<<RXOUTI)) );
   (((U8* )&s16_micro_volume)[0]) = (UEDATX) ;
   (((U8* )&s16_micro_volume)[1]) = (UEDATX) ;
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
}
void audio_micro_get_vol_cur(void)
{
   (UEDATX = (U8) (((U8* )&s16_micro_volume)[0]) ) ;
   (UEDATX = (U8) (((U8* )&s16_micro_volume)[1]) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_micro_get_vol_min(void)
{
   (UEDATX = (U8) ((Uchar) 0x0000 ) ) ;
   (UEDATX = (U8) ((Uchar)( 0x0000 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_micro_get_vol_max(void)
{
   (UEDATX = (U8) ((Uchar) 0x7000 ) ) ;
   (UEDATX = (U8) ((Uchar)( 0x7000 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
void audio_micro_get_vol_res(void)
{
   (UEDATX = (U8) ((Uchar) 0x1000 ) ) ;
   (UEDATX = (U8) ((Uchar)( 0x1000 >>8)) ) ;
   (UEINTX &= ~(1<<TXINI)) ;
   while(! (UEINTX&(1<<RXOUTI)) );
   (UEINTX &= ~(1<<RXOUTI), (UEINTX &= ~(1<<FIFOCON)) ) ;
}
