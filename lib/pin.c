#include "pin.h"
#include "util.h"

#include <avr/io.h>

void pin_set_mode(PinMode mode, volatile uint8_t *ddr, uint8_t pin) {
    switch (mode) {
        case PIN_READ:
            bit_clear(*ddr, pin);
            break;
        case PIN_WRITE:
            bit_set(*ddr, pin);
            break;
    }
}

PinMode pin_get_mode(volatile uint8_t *ddr, uint8_t pin) {
    return bit_is_set(ddr, pin) ? PIN_WRITE : PIN_READ;
}
