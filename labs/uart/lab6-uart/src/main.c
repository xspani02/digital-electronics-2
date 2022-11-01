/***********************************************************************
 * 
 * Use USART unit and transmit data between ATmega328P and computer.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif

#ifndef UART_RX_BUFFER_SIZE
# define UART_RX_BUFFER_SIZE 128
#endif

#ifndef UART_TX_BUFFER_SIZE
# define UART_TX_BUFFER_SIZE 128
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>
#include <string.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and transmit UART data four times 
 *           per second.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize UART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));
    
    // Configure 16-bit Timer/Counter1 to transmit UART data
    // Set prescaler to 262 ms and enable overflow interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Put strings to ringbuffer for transmitting via UART
    uart_puts("Print \tone line... ");
    uart_puts("done\r\n");

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Transmit UART data four times per second.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Transmit UART string(s)
    uint8_t value;
    uint8_t length;
    uint8_t i;
    uint8_t parn;
    
    uint8_t parity;
    char string[8];
    char par[1];
    

    value = uart_getc();

    //uart_puts("Paris\r\n");
    if(value != '\0') {
      
      


      uart_putc(value);
      uart_puts("\t");
      itoa(value, string, 10);
      uart_puts(string);
      uart_puts("\t");
      itoa(value, string, 16);
      uart_puts(string);
      uart_puts("\t");
      itoa(value, string, 2);

      length = strlen(string);

      for(i=length; i>1; i-1) {

        if(string[i] == '1') {

          parn++;
        }
      }

      if (parn/2 == 0) {

        parity = 0;
        itoa(parity, par, 10);
      }
      else {

        parity = 1;
        itoa(parity, par, 10);


      }

      uart_puts(string);
      uart_puts(par);
      uart_puts("\r\n");


    }


}