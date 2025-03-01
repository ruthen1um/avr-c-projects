#ifndef USART_H
#define USART_H

#ifndef __AVR_ATmega328P__
    #error "USART library is only compatible with ATmega328P-based boards."
#endif

typedef unsigned char byte;

void usart_init(void);

void usart_send(byte data);
void usart_send_bytes(const byte *arr);

byte usart_receive(void);

#endif
