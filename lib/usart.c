#include "usart.h"

#include <avr/io.h>

void usart_init(void) {
    uint16_t ubrr = (uint8_t)((F_CPU / (16UL * BAUD)) - 1);
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)(ubrr);

    UCSR0B |= (1 << RXEN0); // Enable reciever
    UCSR0B |= (1 << TXEN0); // Enable transmitter

    // Set frame format: 8 data bits, 1 stop bit, no parity
    // UCSZ02 UCSZ01 UCSZ00
    //      0      1      1
    // 8 bits
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_send(byte data) {
    // Wait until the transmit buffer is empty
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
