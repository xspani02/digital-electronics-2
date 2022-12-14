
This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html

# Lab 7: Šimon Špánik

### Arduino Uno pinout

1. In the picture of the Arduino Uno board, mark the pins that can be used for the following functions/operations:
   * PWM generators from Timer0, Timer1, Timer2 -> PD3,PD5,PD6,PB1,PB2,PB3
   * analog channels for ADC -> PC0,PC1,PC2,PC3,PC4,PC5
   * UART pins -> PD0,PD1
   * I2C pins -> PC4,PC5
   * SPI pins -> PB2,PB3,PB4,PB5
   * external interrupt pins INT0, INT1 -> INT0: PD2;  INT1: PD3

   ![image](https://user-images.githubusercontent.com/99726477/201697111-ad980338-773e-486c-87d5-af701ac488e1.png)
### I2C communication

2. Draw a timing diagram of I2C signals when calling function `rtc_read_years()`. Let this function reads one byte-value from RTC DS3231 address `06h` (see RTC datasheet) in the range `00` to `99`. Specify when the SDA line is controlled by the Master device and when by the Slave device. Draw the whole request/receive process, from Start to Stop condition. The image can be drawn on a computer (by [WaveDrom](https://wavedrom.com/) for example) or by hand. Name all parts of timing diagram.

   ![image](https://user-images.githubusercontent.com/99726477/201714740-2c724516-1eca-44c8-bd10-c7857ec8b14f.png)

### Meteo station

Consider an application for temperature and humidity measurements. Use sensor DHT12, real time clock DS3231, LCD, and one LED. Every minute, the temperature, humidity, and time is requested from Slave devices and values are displayed on LCD screen. When the temperature is above the threshold, turn on the LED.

3. Draw a flowchart of `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) for such Meteo station. The image can be drawn on a computer or by hand. Use clear description of individual algorithm steps.

   ![image](https://user-images.githubusercontent.com/99726477/201715278-667a8822-0a16-48ed-832b-4a783a452eb8.png)
