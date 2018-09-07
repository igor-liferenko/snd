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
void init_adc(void);
const PROGMEM U16 temperature_code[] =
  { 0x3B4, 0x3B0, 0x3AB, 0x3A6, 0x3A0, 0x39A, 0x394, 0x38E, 0x388, 0x381,
0x37A, 0x373,
  0x36B, 0x363, 0x35B, 0x353, 0x34A, 0x341, 0x338, 0x32F, 0x325, 0x31B,
    0x311, 0x307,
  0x2FC, 0x2F1, 0x2E6, 0x2DB, 0x2D0, 0x2C4, 0x2B8, 0x2AC, 0x2A0, 0x294,
    0x288, 0x27C,
  0x26F, 0x263, 0x256, 0x24A, 0x23D, 0x231, 0x225, 0x218, 0x20C, 0x200,
    0x1F3, 0x1E7,
  0x1DB, 0x1CF, 0x1C4, 0x1B8, 0x1AC, 0x1A1, 0x196, 0x18B, 0x180, 0x176,
    0x16B, 0x161,
  0x157, 0x14D, 0x144, 0x13A, 0x131, 0x128, 0x11F, 0x117, 0x10F, 0x106,
    0xFE, 0xF7,
  0xEF, 0xE8, 0xE1, 0xDA, 0xD3, 0xCD, 0xC7, 0xC0, 0xBA, 0xB5, 0xAF, 0xAA,
    0xA4, 0x9F,
  0x9A, 0x96, 0x91, 0x8C, 0x88, 0x84, 0x80, 0x7C, 0x78, 0x74, 0x71, 0x6D,
    0x6A, 0x67,
  0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x53, 0x50, 0x4E, 0x4C, 0x49, 0x47,
    0x45, 0x43,
  0x41, 0x3F, 0x3D, 0x3C, 0x3A, 0x38
};

U16 Get_adc_mic_val(void)
{
  (((ADMUX &=
     ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) |
       (1 << MUX0)), ADCSRB &= ~(1 << MUX5)), ADMUX |=
    (0x21 &
     ((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) |
      (1 << MUX0))), ADCSRB |= (0x21 >> 5) << MUX5), (ADCSRA |=
                                                      (1 << ADSC)));
  while (!((ADCSRA & (1 << ADIF)) ? (1 == 1) : (0 == 1))) ;
  return (U16) (ADCL + ((U16) (ADCH << 8)));
}

U16 Get_adc_temp_val(void)
{
  (((ADMUX &=
     ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) |
       (1 << MUX0)), ADCSRB &= ~(1 << MUX5)), ADMUX |=
    (0x00 &
     ((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) |
      (1 << MUX0))), ADCSRB |= (0x00 >> 5) << MUX5), (ADCSRA |=
                                                      (1 << ADSC)));
  while (!((ADCSRA & (1 << ADIF)) ? (1 == 1) : (0 == 1))) ;
  return (U16) (ADCL + ((U16) (ADCH << 8)));
}

S16 Read_temperature(void)
{
  U16 adc_code;
  S8 index = 0;
  adc_code = Get_adc_temp_val();
  if (adc_code > pgm_read_word_near(&temperature_code)) {
    return (S16) (-20);
  }
  else {
    while (pgm_read_word_near(&temperature_code[index++]) > adc_code) ;
    return (S16) (index - 1 - 20);
  }

}
