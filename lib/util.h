#ifndef UTIL_H
#define UTIL_H

#include <util/delay.h>
#include <avr/io.h>

#define delay(ms) _delay_ms(ms)

#define bit_set(sfr, bit) ((sfr) |= (uint8_t)_BV(bit))
#define bit_clear(sfr, bit) ((sfr) &= (uint8_t)~(_BV(bit)))
#define bit_toggle(sfr, bit) ((sfr) ^= (uint8_t)_BV(bit))

#endif
