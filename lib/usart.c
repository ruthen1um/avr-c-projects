#include "usart.h"
#include "util.h"

#include <avr/io.h>

#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

void usart_init(void) {
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)(UBRR_VALUE);

    bit_set(UCSR0B, RXEN0);
    bit_set(UCSR0B, TXEN0);

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

void usart_send(byte data) {
    loop_until_bit_is_set(UCSR0A, UDRE0);
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void usart_send_bytes(const byte *arr) {
    while (*arr) {
        usart_send(*arr++);
    }
}

byte usart_receive(void) {
    // Wait until data is received
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}
