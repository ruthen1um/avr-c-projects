#ifndef UTIL_H
#define UTIL_H

#include <util/delay.h>

#define delay(ms) _delay_ms(ms)

typedef enum PinMode {
    PIN_READ,
    PIN_WRITE
} PinMode;

_Bool is_set(volatile uint8_t *byte, uint8_t bit);
_Bool is_unset(volatile uint8_t *byte, uint8_t bit);

void set_bit(volatile uint8_t *byte, uint8_t bit);
void unset_bit(volatile uint8_t *byte, uint8_t bit);

void toggle_bit(volatile uint8_t *byte, uint8_t bit);

void set_pin_mode(PinMode mode, volatile uint8_t *ddr, uint8_t pin);
PinMode get_pin_mode(volatile uint8_t *ddr, uint8_t pin);

#endif
