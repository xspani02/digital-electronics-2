# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

## Instructions

The goal of the project is cooperation in pairs, further study of the topic, design of own solutions, implementation, creation of project documentation and presentation of results. The division of roles and tasks within the team is up to their members.

* Students work on a project in the labs during the 10th and 11th weeks of the semester.

* Through the BUT e-learning, students submit a link to the GitHub repository, which contains the complete project in PlatfomIO and a descriptive README file. The submission deadline is the day before the next laboratory, i.e. in 2 weeks.

* The source code for the AVR must be written in C and/or Assembly and must be implementable on Arduino Uno board using toolchains from the semester. No other development tools are allowed.

## Recommended GitHub repository structure

   ```c
   YOUR_PROJECT        // PlatfomIO project
   ├── include         // Included files
   ├── lib             // Libraries
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```

## Recommended README.md file structure

### Team members

* Martin Šmelka
* Šimon Špánik

## Hardware description

Insert descriptive text and schematic(s) of your implementation.

With the help of specified hardware components and Arduino, we created an implementation where we use the Encoder and Joystick to control the LEDs in the shape of a cross and display the data on the LCD.

## Schematic

## Joystick 

# Description

Analog joystick KY-02 has two directions of movement and one switch.
The output voltage is from 0 to 5V. In the central position, there is 2.5V on the X axis and 2.5V on the Y axis.

# Function

It controls LEDs that are arranged in the shape of a cross. Using the Arduino's analog input, it reads the voltage on the VRx and VRy pins, where the conversion is via the Arduino's built-in ADC.



## Encoder

# Description

KY-040 is a rotary encoder that provides an output of how much it was turned and in which direction. The supply voltage is 5V and has 20 pulses per 360 degrees. It also includes a switch with a digital output.

# Function

Enconder in our project controls the blinking speed of the LEDs. It is driven in both directions. When pressed, the output is reset and the flashing is turned off.


## Digilent PmodCLP LCD module

# Description

16x2 character LCD display with 8-bit parallel data interface. Supply voltage is 5V. Its controlled by 10-bit instructions. From LSB to MSB are 8-bits of data and the next 2-bits are Read and Write operating bits.

# Function

The LCD displays the coordinates of XY axis, encoder blink rate value and joystick direction with its custom directional arrow characters

## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...
