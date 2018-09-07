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










const  PROGMEM  S_usb_device_descriptor usb_dev_desc =
{
  sizeof(usb_dev_desc)
,  0x01
,  ( 0x0200 )
,  0
,  0
,  0
,  32
,  ( 0x03EB )
,  ( 0x201B )
,  ( 0x1000 )
,  0x01
,  0x02
,  0x03
,  1
};


const  PROGMEM  S_usb_user_configuration_descriptor usb_conf_desc = {
 { sizeof(S_usb_configuration_descriptor)
 ,  0x02
 ,  (sizeof(S_usb_user_configuration_descriptor))
 ,  3
 ,  1
 ,  0
 ,  ( 0x80 | 0x00)
 ,  50
 }
 ,



 { sizeof(S_usb_interface_descriptor)
 ,  0x04
 ,  0
 ,  0
 ,  0
 ,  0x01
 ,  0x01
 ,  0x00
 ,  0
 }
 ,

 { sizeof(S_usb_ac_interface_descriptor)
 , 0x24
 , 0x01
 , ( 0x0100 )
 , (sizeof(S_usb_ac_interface_descriptor) +sizeof(S_usb_in_ter_descriptor)+sizeof(S_usb_feature_unit_descriptor_speaker)+sizeof(S_usb_out_ter_descriptor) +sizeof(S_usb_in_ter_descriptor)+sizeof(S_usb_feature_unit_descriptor_micro)+sizeof(S_usb_out_ter_descriptor))
 , 0x02
 , 0x02
 , 0x01
 }
 ,



 { sizeof(S_usb_in_ter_descriptor)
 , 0x24
 , 0x02
 , 0x01
 , ( 0x0101 )
 , 0x00
 , 0x01
 , 0x0000
 , 0x00
 , 0x00
 }
 ,

 { sizeof(S_usb_feature_unit_descriptor_speaker)
 , 0x24
 , 0x06
 , 0x02
 , 0x01
 ,0x01
 , ( 0x01 | 0x02 )
 , 0x00
 }
 ,

 { sizeof(S_usb_out_ter_descriptor)
 , 0x24
 , 0x03
 , 0x03
 , ( 0x0301 )
 , 0x00
 , 0x02
 , 0x00
 }
 ,


 { sizeof(S_usb_in_ter_descriptor)
 , 0x24
 , 0x02
 , 0x04
 , ( 0x0201 )
 , 0x00
 , 0x01
 , 0x0000
 , 0x00
 , 0x00
 }
 ,

 { sizeof(S_usb_feature_unit_descriptor_micro)
 , 0x24
 , 0x06
 , 0x05
 , 0x04
 ,0x01
 , ( 0x01 | 0x02 )
 , 0x00
 }
 ,

 { sizeof(S_usb_out_ter_descriptor)
 , 0x24
 , 0x03
 , 0x06
 , ( 0x0101 )
 , 0x00
 , 0x05
 , 0x00
 }
 ,



 { sizeof(S_usb_interface_descriptor)
 , 0x04
 , 0x01
 , 0x00
 , 0x00
 , 0x01
 , 0x02
 , 0x00
 ,0x00
 }
 ,

 { sizeof(S_usb_interface_descriptor)
 , 0x04
 , 0x01
 , 0x01
 , 0x01
 , 0x01
 , 0x02
 , 0x00
 ,0x00
 }
 ,

 { sizeof(S_usb_as_interface_descriptor)
 , 0x24
 , 0x01
 , 0x01
 , 0x01
 , ( 0x0001 )
 }
 ,
 { sizeof(S_usb_format_type)
 , 0x24
 , 0x02
 , 0x01
 , 0x01
 , 0x02
 , 0x10
 , 0x01
 , ( 0x7D00 )
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_descriptor)
 ,  0x05
 ,  ( 1 | 0x00 )
 ,  0x01
 ,  ( (128) )
 ,  0x01
 , 0x00
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_specific)
 , 0x25
 , 0x01
 , 0x00
 , 0x00
 , ( 0x0000 )
 }
 ,



 { sizeof(S_usb_interface_descriptor)
 , 0x04
 , 0x02
 , 0x00
 , 0x00
 , 0x01
 , 0x02
 , 0x00
 ,0x00
 }
 ,

 { sizeof(S_usb_interface_descriptor)
 , 0x04
 , 0x02
 , 0x01
 , 0x01
 , 0x01
 , 0x02
 , 0x00
 ,0x00
 }
 ,

 { sizeof(S_usb_as_interface_descriptor)
 , 0x24
 , 0x01
 , 0x06
 , 0x01
 , ( 0x0001 )
 }
 ,
 { sizeof(S_usb_format_type)
 , 0x24
 , 0x02
 , 0x01
 , 0x01
 , 0x02
 , 0x10
 , 0x01
 , ( 0x1F40 )
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_descriptor)
 ,  0x05
 ,  ( 2 | 0x80 )
 ,  0x01
 ,  ( 16 )
 ,  0x01
 , 0x00
 , 0x00
 }
 ,
 { sizeof(S_usb_endpoint_audio_specific)
 , 0x25
 , 0x01
 , 0x00
 , 0x00
 , ( 0x0000 )
 }
};




const  PROGMEM  S_usb_manufacturer_string_descriptor usb_user_manufacturer_string_descriptor = {
  sizeof(usb_user_manufacturer_string_descriptor)
,  0x03
,  { ((U16)('A')) , ((U16)('T')) , ((U16)('M')) , ((U16)('E')) , ((U16)('L')) }
};




const  PROGMEM  S_usb_product_string_descriptor usb_user_product_string_descriptor = {
  sizeof(usb_user_product_string_descriptor)
,  0x03
,  { ((U16)('A')) , ((U16)('V')) , ((U16)('R')) , ((U16)(' ')) , ((U16)('U')) , ((U16)('S')) , ((U16)('B')) , ((U16)(' ')) , ((U16)('A')) , ((U16)('U')) , ((U16)('D')) , ((U16)('I')) , ((U16)('O')) , ((U16)(' ')) , ((U16)('D')) , ((U16)('E')) , ((U16)('M')) , ((U16)('O')) }
};




const  PROGMEM  S_usb_serial_number usb_user_serial_number = {
  sizeof(usb_user_serial_number)
,  0x03
,  { ((U16)('1')) , ((U16)('.')) , ((U16)('0')) , ((U16)('.')) , ((U16)('0')) }
};




const  PROGMEM  S_usb_language_id usb_user_language_id = {
  sizeof(usb_user_language_id)
,  0x03
,  ( 0x0409 )
};
