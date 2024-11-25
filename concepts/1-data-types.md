# Data Types in C

In the C programming language, data types define the type of data a variable can hold. Understanding data types is fundamental to effective programming, as it determines the size, layout, and the operations that can be performed on the data.

## 1. Basic Data Types

- 1.1 `char`(Character)

  * **Description:** Used to store single characters or small integers (usually 1byte).
  * **Size:** 1 byte (8 bits).
  * Range:
    * `singed char`: Typically ranges from -128 to 127.
    * `unsigned char`: Ranges from 0 to 255.

  #### Example

  ``` c
  char letter = 'M';
  signed char signed_letter = -10;
  unsigned char unsigned_letter = 255;
  ```
