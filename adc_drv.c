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
void init_adc(void)
{
  (ADCSRA |= (1 << ADEN));

  (ADMUX &= ~(1 << ADLAR));
  (ADCSRB &= ~(1 << 7));
  (ADMUX &= ~(1 << REFS1), ADMUX |= (1 << REFS0));
  (ADCSRA &= ~(1 << ADIE));
  (ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)), ADCSRA |= (2));
}
