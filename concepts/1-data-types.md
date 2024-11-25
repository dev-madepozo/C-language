# Data Types in C

In the C programming language, data types define the type of data a variable can hold. Understanding data types is fundamental to effective programming, as it determines the size, layout, and the operations that can be performed on the data.

## 1. Basic Data Types

- 1.1 `char`(Character)
  * **Description:** Used to store single characters or small integers (usually 1byte).
  * **Size:** 1 byte (8 bits).
  * **Range:**
    * `singed char`: Typically ranges from -128 to 127.
    * `unsigned char`: Ranges from 0 to 255.

  #### Example

  ``` C
  char letter = 'M';
  signed char signed_letter = -10;
  unsigned char unsigned_letter = 255;
  ```

- 1.2 `int`: (Integer)
  * **Description:** Used to store integer values (whole numbers without a fractional component).
  * **Size:**  4 bytes on modern architectures, but it depends on the system.
  * **Range:**
    * `signed int`: Typically ranges from -2,147,483,648 to 2,147,483,647 (for 4 bytes).
    * `unsigned int`: Ranges from 0 to 4,294,967,295 (for 4 bytes).
  
  #### Example

  ``` C
  int num = 10;
  unsigned int positive_num = 20;
  ```

