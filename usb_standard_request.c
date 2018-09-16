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
extern volatile U16 g_usb_event;
extern U8 g_usb_mode;
extern U8 usb_remote_wup_feature;
void usb_task_init(void);
void usb_task(void);

extern volatile U8 private_sof_counter;
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

extern const PROGMEM S_usb_device_descriptor usb_dev_desc;
extern const PROGMEM S_usb_user_configuration_descriptor usb_conf_desc;
extern const PROGMEM S_usb_user_configuration_descriptor
  usb_other_conf_desc;
extern const PROGMEM S_usb_device_qualifier_descriptor usb_qual_desc;
extern const PROGMEM S_usb_manufacturer_string_descriptor
  usb_user_manufacturer_string_descriptor;
extern const PROGMEM S_usb_product_string_descriptor
  usb_user_product_string_descriptor;
extern const PROGMEM S_usb_serial_number usb_user_serial_number;
extern const PROGMEM S_usb_language_id usb_user_language_id;

Bool usb_user_read_request(U8, U8);
Bool usb_user_get_descriptor(U8, U8);
void usb_user_endpoint_init(U8);

void audio_speaker_set_mute(void);
void audio_speaker_get_mute(void);
void audio_speaker_set_volume(void);
void audio_speaker_get_vol_cur(void);
void audio_speaker_get_vol_min(void);
void audio_speaker_get_vol_max(void);
void audio_speaker_get_vol_res(void);

void audio_micro_set_mute(void);
void audio_micro_get_mute(void);
void audio_micro_set_volume(void);
void audio_micro_get_vol_cur(void);
void audio_micro_get_vol_min(void);
void audio_micro_get_vol_max(void);
void audio_micro_get_vol_res(void);

static void usb_get_descriptor(void);
static void usb_set_address(void);
static void usb_set_configuration(void);
static void usb_clear_feature(void);
static void usb_set_feature(void);
static void usb_get_status(void);
static void usb_get_configuration(void);
static void usb_get_interface(void);
static void usb_set_interface(void);
static U8 zlp;
static U8 endpoint_status[7];
static U8 device_status = 1;

PGM_VOID_P pbuffer;
U8 data_to_transfer;

U16 wInterface;

static U8 bmRequestType;
U8 remote_wakeup_feature = 0;
U8 usb_configuration_nb;
extern U8 usb_connected;
extern const PROGMEM S_usb_device_descriptor usb_user_device_descriptor;
extern const PROGMEM S_usb_user_configuration_descriptor
  usb_user_configuration_descriptor;

U8 usb_remote_wup_feature;
void usb_process_request(void)
{
  U8 bmRequest;

  (UEINTX &= ~(1 << RXOUTI));
  bmRequestType = (UEDATX);
  bmRequest = (UEDATX);

  switch (bmRequest) {
  case 0x06:
    if (((1 << 7) | (0 << 5) | (0)) == bmRequestType) {
      usb_get_descriptor();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x08:
    if (((1 << 7) | (0 << 5) | (0)) == bmRequestType) {
      usb_get_configuration();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x05:
    if (((0 << 7) | (0 << 5) | (0)) == bmRequestType) {
      usb_set_address();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x09:
    if (((0 << 7) | (0 << 5) | (0)) == bmRequestType) {
      usb_set_configuration();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x01:
    if (((0 << 7) | (0 << 5) | (2)) >= bmRequestType) {
      usb_clear_feature();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x03:
    if (((0 << 7) | (0 << 5) | (2)) >= bmRequestType) {
      usb_set_feature();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x00:
    if ((0x7F < bmRequestType) & (0x82 >= bmRequestType)) {
      usb_get_status();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x0A:
    if (bmRequestType == ((1 << 7) | (0 << 5) | (1))) {
      usb_get_interface();
    }
    else {
      usb_user_read_request(bmRequestType, bmRequest);
    }
    break;

  case 0x0B:
    if (bmRequestType == ((0 << 7) | (0 << 5) | (1))) {
      usb_set_interface();
    }
    break;

  case 0x07:
  case 0x0C:
  default:
    if (usb_user_read_request(bmRequestType, bmRequest) == (0 == 1)) {
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
      return;
    }
    break;
  }
}

void usb_set_address(void)
{
  U8 addr = (UEDATX);
  (UDADDR = (UDADDR & (1 << ADDEN)) | ((U8) addr & 0x7F));

  (UEINTX &= ~(1 << RXSTPI));

  (UEINTX &= ~(1 << TXINI));
  while (!(UEINTX & (1 << TXINI))) ;

  (UDADDR |= (1 << ADDEN));
}

void usb_set_configuration(void)
{
  U8 configuration_number;

  configuration_number = (UEDATX);

  if (configuration_number <= 1) {
    (UEINTX &= ~(1 << RXSTPI));
    usb_configuration_nb = configuration_number;
  }
  else {

    (UECONX |= (1 << STALLRQ));
    (UEINTX &= ~(1 << RXSTPI));
    return;
  }

  (UEINTX &= ~(1 << TXINI));

  usb_user_endpoint_init(usb_configuration_nb);
}

void usb_get_descriptor(void)
{
  U16 wLength;
  U8 descriptor_type;
  U8 string_type;
  U8 dummy;
  U8 nb_byte;

  zlp = (0 == 1);
  string_type = (UEDATX);
  descriptor_type = (UEDATX);

  switch (descriptor_type) {
  case 0x01:
    data_to_transfer = (sizeof (usb_dev_desc));
    pbuffer = (&(usb_dev_desc.bLength));
    break;
  case 0x02:
    data_to_transfer = (sizeof (usb_conf_desc));
    pbuffer = (&(usb_conf_desc.cfg.bLength));
    break;
  default:
    if (usb_user_get_descriptor(descriptor_type, string_type) == (0 == 1)) {
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
      return;
    }
    break;
  }

  dummy = (UEDATX);
  dummy = (UEDATX);
  (((U8 *) & wLength)[0]) = (UEDATX);
  (((U8 *) & wLength)[1]) = (UEDATX);
  (UEINTX &= ~(1 << RXSTPI));

  if (wLength > data_to_transfer) {
    if ((data_to_transfer % 32) == 0) {
      zlp = (1 == 1);
    }
    else {
      zlp = (0 == 1);
    }
  }
  else {
    data_to_transfer = (U8) wLength;
  }

  (UEINTX &= ~(1 << NAKOUTI));

  while ((data_to_transfer != 0) && (!(UEINTX & (1 << NAKOUTI)))) {
    while (!(UEINTX & (1 << TXINI))) {
      if ((UEINTX & (1 << NAKOUTI)))
        break;
    }

    nb_byte = 0;
    while (data_to_transfer != 0) {
      if (nb_byte++ == 32) {
        break;
      }

      (UEDATX = (U8) pgm_read_byte_near((unsigned int) pbuffer++));

      data_to_transfer--;
    }

    if ((UEINTX & (1 << NAKOUTI)))
      break;
    else
      (UEINTX &= ~(1 << TXINI));
  }

  if ((zlp == (1 == 1)) && (!(UEINTX & (1 << NAKOUTI)))) {
    while (!(UEINTX & (1 << TXINI))) ;
    (UEINTX &= ~(1 << TXINI));
  }

  while (!((UEINTX & (1 << NAKOUTI)))) ;
  (UEINTX &= ~(1 << NAKOUTI));
  (UEINTX &= ~(1 << RXOUTI));

}

void usb_get_configuration(void)
{
  (UEINTX &= ~(1 << RXSTPI));

  (UEDATX = (U8) usb_configuration_nb);
  (UEINTX &= ~(1 << TXINI), (UEINTX &= ~(1 << FIFOCON)));

  while (!(UEINTX & (1 << RXOUTI))) ;
  (UEINTX &= ~(1 << RXOUTI), (UEINTX &= ~(1 << FIFOCON)));
}

void usb_get_status(void)
{
  U8 wIndex;
  U8 dummy;

  dummy = (UEDATX);
  dummy = (UEDATX);
  wIndex = (UEDATX);

  switch (bmRequestType) {
  case ((1 << 7) | (0 << 5) | (0)):
    (UEINTX &= ~(1 << RXSTPI));
    (UEDATX = (U8) device_status);
    break;

  case ((1 << 7) | (0 << 5) | (1)):
    (UEINTX &= ~(1 << RXSTPI));
    (UEDATX = (U8) 0x00);
    break;

  case ((1 << 7) | (0 << 5) | (2)):
    (UEINTX &= ~(1 << RXSTPI));
    wIndex = wIndex & 0x7F;
    (UEDATX = (U8) endpoint_status[wIndex]);
    break;
  default:
    (UECONX |= (1 << STALLRQ));
    (UEINTX &= ~(1 << RXSTPI));
    return;
  }

  (UEDATX = (U8) 0x00);
  (UEINTX &= ~(1 << TXINI));

  while (!(UEINTX & (1 << RXOUTI))) ;
  (UEINTX &= ~(1 << RXOUTI), (UEINTX &= ~(1 << FIFOCON)));
}

void usb_set_feature(void)
{
  U8 wValue;
  U8 wIndex;
  U8 dummy;

  switch (bmRequestType) {
  case ((0 << 7) | (0 << 5) | (0)):
    wValue = (UEDATX);
    switch (wValue) {
    case 1:
      if ((wValue == 0x01) && (0 == 1)) {
        device_status |= 0x02;
        remote_wakeup_feature = 1;
        (UEINTX &= ~(1 << RXSTPI));
        (UEINTX &= ~(1 << TXINI));
      }
      else {
        (UECONX |= (1 << STALLRQ));
        (UEINTX &= ~(1 << RXSTPI));
      }
      break;

    default:
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
      break;
    }
    break;

  case ((0 << 7) | (0 << 5) | (1)):

    (UECONX |= (1 << STALLRQ));
    (UEINTX &= ~(1 << RXSTPI));
    break;

  case ((0 << 7) | (0 << 5) | (2)):
    wValue = (UEDATX);
    dummy = (UEDATX);

    if (wValue == 0x00) {
      wIndex = ((UEDATX) & 0x7F);

      if (wIndex == 0) {
        (UECONX |= (1 << STALLRQ));
        (UEINTX &= ~(1 << RXSTPI));
      }

      (UENUM = (U8) wIndex);
      if (((UECONX & (1 << EPEN)) ? (1 == 1) : (0 == 1))) {
        (UECONX |= (1 << STALLRQ));
        (UENUM = (U8) 0);
        endpoint_status[wIndex] = 0x01;
        (UEINTX &= ~(1 << RXSTPI));
        (UEINTX &= ~(1 << TXINI));
      }
      else {
        (UENUM = (U8) 0);
        (UECONX |= (1 << STALLRQ));
        (UEINTX &= ~(1 << RXSTPI));
      }
    }
    else {
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
    }
    break;

  default:
    (UECONX |= (1 << STALLRQ));
    (UEINTX &= ~(1 << RXSTPI));
    break;
  }
}

void usb_clear_feature(void)
{
  U8 wValue;
  U8 wIndex;
  U8 dummy;

  if (bmRequestType == ((0 << 7) | (0 << 5) | (0))) {
    wValue = (UEDATX);
    if ((wValue == 0x01) && (0 == 1)) {
      device_status &= ~0x02;
      remote_wakeup_feature = 0;
      (UEINTX &= ~(1 << RXSTPI));
      (UEINTX &= ~(1 << TXINI));
    }
    else {
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
    }
    return;
  }
  else if (bmRequestType == ((0 << 7) | (0 << 5) | (1))) {

    (UECONX |= (1 << STALLRQ));
    (UEINTX &= ~(1 << RXSTPI));
    return;
  }
  else if (bmRequestType == ((0 << 7) | (0 << 5) | (2))) {
    wValue = (UEDATX);
    dummy = (UEDATX);

    if (wValue == 0x00) {
      wIndex = ((UEDATX) & 0x7F);

      (UENUM = (U8) wIndex);
      if (((UECONX & (1 << EPEN)) ? (1 == 1) : (0 == 1))) {
        if (wIndex != 0) {
          (UECONX |= (1 << STALLRQC));
          (UERST = 1 << (U8) wIndex, UERST = 0);
          (UECONX |= (1 << RSTDT));
        }
        (UENUM = (U8) 0);
        endpoint_status[wIndex] = 0x00;
        (UEINTX &= ~(1 << RXSTPI));
        (UEINTX &= ~(1 << TXINI));
      }
      else {
        (UENUM = (U8) 0);
        (UECONX |= (1 << STALLRQ));
        (UEINTX &= ~(1 << RXSTPI));
        return;
      }
    }
    else {
      (UECONX |= (1 << STALLRQ));
      (UEINTX &= ~(1 << RXSTPI));
      return;
    }
  }
}

void usb_get_interface(void)
{
  (UEINTX &= ~(1 << RXSTPI));
  (UEINTX &= ~(1 << TXINI));

  while (!(UEINTX & (1 << RXOUTI))) ;
  (UEINTX &= ~(1 << RXOUTI), (UEINTX &= ~(1 << FIFOCON)));
}

void usb_set_interface(void)
{
  (UEINTX &= ~(1 << RXSTPI));
  (UEINTX &= ~(1 << TXINI));
  while (!(UEINTX & (1 << TXINI))) ;
}

void usb_generate_remote_wakeup(void)
{
  if ((PLLCSR & (1 << PLOCK)) == (0 == 1)) {
    PLLCSR = 1 << PINDIV;
    PLLCSR |= 1 << PLLE;
    while (!(PLLCSR & (1 << PLOCK))) ;
  }
  (USBCON &= ~(1 << FRZCLK));
  if (remote_wakeup_feature == 1) {
    (UDCON |= (1 << RMWKUP));
    remote_wakeup_feature = 0;
  }
}
