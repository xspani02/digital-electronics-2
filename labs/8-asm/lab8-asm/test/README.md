
This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html
# Lab 8: INSERT_YOUR_FIRSTNAME INSERT_YOUR_LASTNAME

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-- | :-: |
   | `add r24, r0` | `0000_1101_1000_0000` | 0D80 |  |
   | `com r26` |  |  |  |
   | `eor r26, r27` |  |  |  |
   | `mul r22, r20` | `1001_1111_0110_0100` | 9F44 |  |
   | `ret` | `1001_0101_0000_1000` | 9508 |  |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 0 1 3 7 14 13 11 6 12 9 2 5 10 4 8 | 15 |
   | 4, 2 | 0 1 3 6 12 8 | 6 |
   | 4, 1 | 0 1 2 5 10 4 9 3 6 13 11 7 14 12 8 | 15 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()
