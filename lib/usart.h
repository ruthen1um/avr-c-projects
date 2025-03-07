#ifndef USART_H
#define USART_H

#ifndef __AVR_ATmega328P__
    #error "USART library is only compatible with ATmega328P"
#endif

typedef unsigned char byte;

void usart_init(void);

void usart_send_byte(byte data);
void usart_send_bytes(const byte *arr, unsigned int n);

byte usart_receive(void);

#endif
