
This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html

# Lab 1: Šimon Špánik

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);
    uint8_t led_value = HIGH;
    
    // LONG_DELAY is 1500 ms
    // SHORT DELAY is 500 ms,   ratio dot/comma = 1/3
    // LED is connected in active high way
    
    // Infinite loop
    while (1)
    {
        // Generate a lettre `A` Morse code

        // WRITE YOUR CODE HERE
        digitalWrite(LED_GREEN, led_value);
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_GREEN, !led_value);        
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_GREEN, led_value);
        _delay_ms(LONG_DELAY);
        digitalWrite(LED_GREEN, !led_value);
        _delay_ms(SHORT_DELAY);

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

  ![image](https://user-images.githubusercontent.com/99726477/193290337-a14aae13-fbe7-410e-af89-db4ffb681f91.png)

