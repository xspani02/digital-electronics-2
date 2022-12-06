/***********************************************************************
 * DE2-Project 1:
 * Martin Šmelka, Šimon Špánik
 * Use of Analog-to-digital conversion to transalte Joysitc movements to an array of LEDs and represend the position of said 
 * joystic with the possiblity of modulating the signal frequency and cause the LEDs to flicker. All of these functions are then
 * Represented on a LCD screen via UART and LCD libraries. 
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO, KY-040 Rotary encoder, KY-023 Joystick, 5 ressistors for LEDs, 5 LEDs arranged
 * in a cross pattern to represent the position of the Joystic.
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions
#include <twi.h>            // I2C/TWI library for AVR-GCC.
#include <uart.h>           // Interrupt UART library with receive/transmit circular buffers

#include "Arduino.h"
// Define LEDS for directional output
#define SERVO PB2


static uint8_t count = 0;

// Static VARIABLES for functions 


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Ininitialize display, set up pullup and nopull for JOYSTICK and ENCODER
 *           Prepare Custom Characters for use on the LCD
 *           Configure Analog-to-Digital Convertion unit
 *           Engage Timer at 4ms(functional for our purposes)
 *           Enable Global interrupts by setting the global interrupt mask
 **********************************************************************/
int main(void)
{
   
    GPIO_mode_output(&DDRB, SERVO);

    TCCR1A &= ~(1<<COM1A1 | 0<<COM1A0);
    TCCR1A &= ~(1<<COM1B1 | 0<<COM1B0);
    TCCR1A &= ~(1<<WGM11 | 0<<WGM10);
    TCCR1B &= ~(1<<WGM12 | 1<<WGM13); 
    TCCR1B &= ~(1<<CS12 | 1<<CS11 | 0<<CS10); 
    TIMSK1 |= (1<<TOIE1 | 1<<OCIE1A);
    
    
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVCC with external capacitor at AREF pin"
    ADMUX = ADMUX | (1<<REFS0);
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Engage Timer at 4ms(functional for our purposes)
  
    
  
    

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // sei Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop to keep operations running
    while (1)
    {

            /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    return 0;
}

   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: TIMER1_OVF_vect function where the timer operates and Encoder is set up
 * Purpose:  Start ADC conversion
 *           LCD Display set up
 *           Encoder set up
 **********************************************************************/



ISR(TIMER1_OVF_vect)
{
  OCR1A = 100;
  analogWrite(SERVO, 100);

} 




ISR(ADC_vect)
{
  


}