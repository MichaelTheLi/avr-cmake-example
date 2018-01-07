/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#ifndef DEBUG_BUILD
    #define DEBUG_BUILD false
    #include <util/delay.h>
#endif
#include <avr/sleep.h>

/*
 * This demonstrate how to use the avr_mcu_section.h file
 * The macro adds a section to the ELF file with useful
 * information for the simulator
 */
//#include "avr/avr_mcu_section.h"
//AVR_MCU(F_CPU, "atmega8");

void delay_ms(char n) {
#ifndef DEBUG_BUILD
    for(char i = 0; i < n; i++){
        _delay_ms(30);  /* max is 262.14 ms / F_CPU in MHz */
    }
#endif
}

int main(void)
{
    DDRD = 1 << 4;           /* make the LED pin an output */
    for(;;){
        char i;
        for(i = 0; i < 10; i++){
            delay_ms(30);  /* max is 262.14 ms / F_CPU in MHz */
        }
        PORTD ^= 1 << 4;    /* toggle the LED */

        // this quits the simulator, since interupts are off
        // this is a "feature" that allows running tests cases and exit
//        sleep_cpu();
    }

    return 0;               /* never reached */
}
