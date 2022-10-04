/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5
#define LED_RED PB0
#define PUSHBUTTON PD7   // PB5 is AVR pin where green on-board LED 
                        // is connected
#define SHORT_DELAY 250 // Delay in milliseconds
#ifndef F_CPU
#define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops


// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
//#include "Arduino.h"
//#define PB5 13
//#define PB2 10           // In Arduino world, PB5 is called "13"
// -----
#include <gpio.h>

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uint8_t led_value = 0;
      // Local variable to keep LED status

    // Set pin where on-board LED is connected as output
    //pinMode(LED_GREEN, OUTPUT);
    //pinMode(LED_RED, OUTPUT);
    //DDRB = DDRB | (1<<LED_GREEN);
    //DDRB = DDRB | (1<<LED_RED);
    GPIO_mode_output(&DDRB, LED_GREEN);
    GPIO_mode_output(&DDRB, LED_RED);
    GPIO_mode_input_pullup(&DDRD, PUSHBUTTON);
  
    if(GPIO_read(&PIND, PUSHBUTTON) == 0){// Infinite loop
       while (1)
       {
        // Turn ON/OFF on-board LED
        //digitalWrite(LED_GREEN, led_value);
        //digitalWrite(LED_RED, led_value);

        // Pause several milliseconds
           
         
        // Change LED value
            _delay_ms(SHORT_DELAY);
            if (led_value == 0) {
                  led_value = 1;
                  GPIO_write_high(&PORTB, LED_GREEN);
                  GPIO_write_high(&PORTB, LED_RED);
               //PORTB = PORTB | (1<<LED_GREEN);
               //PORTB = PORTB | (1<<LED_RED);
            } 
            else {
                  led_value = 0;
               //PORTB = PORTB & ~(1<<LED_GREEN);
               //PORTB = PORTB & ~(1<<LED_RED);
                  GPIO_write_low(&PORTB, LED_GREEN);
                  GPIO_write_low(&PORTB, LED_RED);

            }
         
         
      }
    }
    // Will never reach this
    return 0;
}