#ifndef USART_H
#define USART_H

typedef unsigned char byte;

void usart_init(void);

void usart_send(byte data);
void usart_send_bytes(const byte *arr);

byte usart_receive(void);

#endif
