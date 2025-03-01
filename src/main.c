#include "usart.h"
#include <stdio.h>

int main(void) {
    char string[10];

    usart_init();
    while (1) {
        byte x = usart_receive();
        snprintf(string, 10, "Got: %c\n", x);
        usart_send_bytes((byte*)string);
    }
}
