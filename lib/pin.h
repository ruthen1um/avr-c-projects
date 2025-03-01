#ifndef PIN_H
#define PIN_H

#include <stdint.h>

typedef enum PinMode {
    PIN_READ,
    PIN_WRITE
} PinMode;

void pin_set_mode(PinMode mode, volatile uint8_t *ddr, uint8_t pin);
PinMode pin_get_mode(volatile uint8_t *ddr, uint8_t pin);

#endif
