typedef float Float16;

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
typedef signed char S8;
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

typedef union {
  Uint32 dw;
  Uint16 w[2];
  Uint8 b[4];
} Union32;

typedef union {
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
extern volatile U16 g_usb_event;
extern U8 g_usb_mode;
extern U8 usb_remote_wup_feature;
void usb_task_init(void);
void usb_task(void);

extern volatile U8 private_sof_counter;
typedef enum endpoint_parameter { ep_num, ep_type, ep_direction, ep_size,
    ep_bank, nyet_status } t_endpoint_parameter;
U8 usb_config_ep(U8, U8);
U8 usb_select_enpoint_interrupt(void);
U16 usb_get_nb_byte_epw(void);
U8 usb_send_packet(U8, U8 *, U8);
U8 usb_read_packet(U8, U8 *, U8);
void usb_halt_endpoint(U8);
void usb_reset_endpoint(U8);
U8 usb_init_device(void);
void usb_process_request(void);

void usb_generate_remote_wakeup(void);

extern U8 usb_configuration_nb;
extern U8 remote_wakeup_feature;
typedef struct {
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

typedef struct {
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

typedef struct {
  U8 bLenght;
  U8 bDescriptorType;
  U8 bDescriptorSubType;
  U8 bUnitID;
  U8 bSourceID;
  U8 bControSize;
  U8 bmaControlMaster;
  U8 bmaControlCh1;
} S_usb_feature_unit_descriptor_speaker;

typedef struct {
  U8 bLenght;
  U8 bDescriptorType;
  U8 bDescriptorSubType;
  U8 bUnitID;
  U8 bSourceID;
  U8 bControSize;
  U8 bmaControlMaster;
  U8 bmaControlCh1;
} S_usb_feature_unit_descriptor_micro;

typedef struct {
  U8 bLenght;
  U8 bDescriptorType;
  U8 bDescriptorSubType;
  U8 bTerminalID;
  U16 wTerminalType;
  U8 bAssocTerminal;
  U8 bSourceID;
  U8 iTerminal;
} S_usb_out_ter_descriptor;

typedef struct {
  U8 bLenght;
  U8 bDescriptorType;
  U8 bDescriptorSubType;
  U8 bTerminalLink;
  U8 bDelay;
  U16 wFormatTag;
} S_usb_as_interface_descriptor;

typedef struct {
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

typedef struct {
  U8 bLenght;
  U8 bDescriptorType;
  U8 bDescriptorSubType;
  U8 bmAttributes;
  U8 bLockDelayUnits;
  U16 wLockDelay;
} S_usb_endpoint_audio_specific;

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
  U16 wstring[5];
} S_usb_manufacturer_string_descriptor;

typedef struct {
  U8 bLength;
  U8 bDescriptorType;
  U16 wstring[18];
} S_usb_product_string_descriptor;

typedef struct {
  U8 bLength;
  U8 bDescriptorType;
  U16 wstring[0x05];
} S_usb_serial_number;

typedef struct {
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
#include  <avr/power.h>
void set_idle_mode(void);
void set_power_down_mode(void);
void set_adc_noise_reduction_mode(void);
void set_power_save_mode(void);
void set_standby_mode(void);
void set_ext_standby_mode(void);
void Clock_switch_external(void);
void Clock_switch_internal(void);
#include  <avr/io.h>
#include  <avr/wdt.h>
extern U8 usb_suspended;

extern U8 usb_connected;
void usb_device_task_init(void);
void usb_start_device(void);
void usb_device_task(void);
volatile U16 g_usb_event = 0;

extern U8 usb_connected;

extern U8 usb_configuration_nb;

extern U8 remote_wakeup_feature;
void usb_task_init(void)
{
  usb_device_task_init();

  usb_remote_wup_feature = 0;

}

void usb_task(void)
{
  usb_device_task();
}

ISR(USB_GEN_vect)
{

  if (((USBINT & (1 << VBUSTI)) ? (1 == 1) : (0 == 1))
      && ((USBCON & (1 << VBUSTE)) ? (1 == 1) : (0 == 1))) {
    (USBINT &= ~(1 << VBUSTI));
    if (((USBSTA & (1 << VBUS)) ? (1 == 1) : (0 == 1))) {
      usb_connected = (1 == 1);
      (g_usb_event |= (1 << 1));
      (UDIEN |= (1 << EORSTE));
      usb_start_device();
      (UDCON &= ~(1 << DETACH));
    }
    else {
      usb_connected = (0 == 1);
      usb_configuration_nb = 0;
      (g_usb_event |= (1 << 2));
    }
  }

  if (((UDINT & (1 << SOFI)) ? (1 == 1) : (0 == 1))
      && ((UDIEN & (1 << SOFE)) ? (1 == 1) : (0 == 1))) {
    (UDINT &= ~(1 << SOFI));
  }

  if (((UDINT & (1 << SUSPI)) ? (1 == 1) : (0 == 1))
      && ((UDIEN & (1 << SUSPE)) ? (1 == 1) : (0 == 1))) {
    usb_suspended = (1 == 1);
    (UDINT &= ~(1 << WAKEUPI));
    (g_usb_event |= (1 << 5));
    (UDINT &= ~(1 << SUSPI));
    (UDIEN |= (1 << WAKEUPE));
    (UDIEN &= ~(1 << EORSME));
    (USBCON |= (1 << FRZCLK));
    (PLLCSR &= (~(1 << PLLE)), PLLCSR = 0);
  }

  if (((UDINT & (1 << WAKEUPI)) ? (1 == 1) : (0 == 1))
      && ((UDIEN & (1 << WAKEUPE)) ? (1 == 1) : (0 == 1))) {
    if ((PLLCSR & (1 << PLOCK)) == (0 == 1)) {
      PLLCSR = 1 << PINDIV;
      PLLCSR |= 1 << PLLE;
      while (!(PLLCSR & (1 << PLOCK))) ;
    }
    (USBCON &= ~(1 << FRZCLK));
    (UDINT &= ~(1 << WAKEUPI));
    if (usb_suspended) {
      (UDIEN |= (1 << EORSME));
      (UDIEN |= (1 << EORSTE));
      (UDINT &= ~(1 << WAKEUPI));
      (UDIEN &= ~(1 << WAKEUPE));
      (g_usb_event |= (1 << 6));
      (UDIEN |= (1 << SUSPE));
      (UDIEN |= (1 << EORSME));
      (UDIEN |= (1 << EORSTE));

    }
  }

  if (((UDINT & (1 << EORSMI)) ? (1 == 1) : (0 == 1))
      && ((UDIEN & (1 << EORSME)) ? (1 == 1) : (0 == 1))) {
    usb_suspended = (0 == 1);
    (UDIEN &= ~(1 << WAKEUPE));
    (UDINT &= ~(1 << EORSMI));
    (UDIEN &= ~(1 << EORSME));
    (g_usb_event |= (1 << 7));
  }

  if (((UDINT & (1 << EORSTI)) ? (1 == 1) : (0 == 1))
      && ((UDIEN & (1 << EORSTE)) ? (1 == 1) : (0 == 1))) {

    usb_remote_wup_feature = 0;

    (UDINT &= ~(1 << EORSTI));
    usb_init_device();
    (g_usb_event |= (1 << 8));
  }

}
