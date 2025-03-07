#include <util/delay.h>
#include "usart.h"

int main(void) {
    usart_init();

    for (;;) {
        usart_send_byte('A');
        _delay_ms(1000);  // Send 'A' every second
    }
}
