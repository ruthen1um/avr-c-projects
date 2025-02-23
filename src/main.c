#include "util.h"
#include "usart.h"

int main(void) {
    usart_init();

    while (1) {
        for (byte i = 0; i <= 255; ++i) {
            usart_send(i);
            delay(200);
        }
    }
}
