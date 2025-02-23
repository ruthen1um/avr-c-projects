#include "util.h"

_Bool is_set(volatile uint8_t *byte, uint8_t bit) {
    return (1 << bit) & (*byte << bit);
}

_Bool is_unset(volatile uint8_t *byte, uint8_t bit) {
    return !is_set(byte, bit);
}

void set_bit(volatile uint8_t *byte, uint8_t bit) {
    *byte |= (uint8_t)(1 << bit);
}

void unset_bit(volatile uint8_t *byte, uint8_t bit) {
    *byte &= (uint8_t)(~(1 << bit));
}

void toggle_bit(volatile uint8_t *byte, uint8_t bit) {
    *byte ^= (uint8_t)(1 << bit);
}

void set_pin_mode(PinMode mode, volatile uint8_t *ddr, uint8_t pin) {
    /*
       DDRn bit set - pin set to write mode
       DDRn bit unset - pin set to read mode
    */
    switch (mode) {
        case PIN_READ:
            // *ddr &= (uint8_t)(~(1 << pin));
            unset_bit(ddr, pin);
            break;
        case PIN_WRITE:
            // *ddr |= (uint8_t)(1 << pin);
            set_bit(ddr, pin);
            break;
    }
}

PinMode get_pin_mode(volatile uint8_t *ddr, uint8_t pin) {
    return is_set(ddr, pin) ? PIN_WRITE : PIN_READ;
}
