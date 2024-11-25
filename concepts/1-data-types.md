# Data Types in C

In the C programming language, data types define the type of data a variable can hold. Understanding data types is fundamental to effective programming, as it determines the size, layout, and the operations that can be performed on the data.

## 1. Basic Data Types

- 1.1 `char`(Character)
  * **Description:** Used to store single characters or small integers (usually 1byte).
  * **Size:** 1 byte (8 bits).
  * **Range:**
    * `singed char`: Typically ranges from -128 to 127.
    * `unsigned char`: Ranges from 0 to 255.

  ##### Example:

  ```C
  char letter = 'M';
  signed char signed_letter = -10;
  unsigned char unsigned_letter = 255;
  ```

- 1.2 `int`: (Integer)
  * **Description:** Used to store integer values (whole numbers without a fractional component).
  * **Size:** 4 bytes on modern architectures, but it depends on the system.
  * **Range:**
    * `signed int`: Typically ranges from -2,147,483,648 to 2,147,483,647 (for 4 bytes).
    * `unsigned int`: Ranges from 0 to 4,294,967,295 (for 4 bytes).
  
  ##### Example:

  ```C
  int num = 10;
  unsigned int positive_num = 20;
  ```

- 1.3 `float` (Floating-Point)
  * **Description:** Used to store decimal numbers (single precision floating-point).
  * **Size:** Typically 4 bytes.
  * **Range:** Approximately 1.5 × 10⁻⁴⁵ to 3.4 × 10³⁸.

  ##### Example:

  ```C
  float pi = 3.14159;
  ```

- 1.4 `double` (Double Precision Floating-Point)
  * **Description:** Used to store larger decimal numbers (double precision floating-point).
  * **Size:** Typically 8 bytes
  * **Range:** Approximately 5.0 × 10⁻³²⁴ to 1.7 × 10³⁰⁸.

  ##### Example:

  ```C
  double pi_accurate = 3.141592653589793;
  ```

- 1.5 `void`
  * **Description:** Used to indicate an absence of type. It is mainly used in function return types or pointers that do not refer to any specific data type.

  ##### Example:

  ```C
  void print_message() {
    printf("Hello, World!\n");
  }
  ```


## 2. Derived Data Types

- 2.1 Pointers
  * **Description:** A pointer holds the memory address of another variable. Pointers are essential for dynamic memory management and implementing data structures like linked lists.

  ##### Example:

  ```C
  int num = 29;
  int *ptr = &num; // <- POinter to an integer
  ```

- 2.2 Arrays
  * **Description:** An array is a collection of elements of the same type, arranged in contiguous memory locations.

  ##### Example:

  ```C
  int arr[5] = {1, 2, 3, 4, 5},
  ```

- 2.3 Structures (`struct`)
  * **Description:** A structure is a user-defined data type that groups variables of different types together.

  ###### Example:

  ```C
  struct Person {
    char name[50];
    int age;
    float height;
  }

  struct Person person1 = {"Alice", 30, 5.5}
  ```

- 2.4 Unions
  * **Description:** A union is similar to a structure but only one member can hold a value at any given time. The memory allocated is shared between all members.

  ##### Example:

  ```C
  union Data {
    int i;
    float f;
    char str[20];
  };

  union Data data;
  data.i = 10; // Only 'i' holds a value at this point
  ```

## 3. Type Modifiers

C provides several type modifiers that can be used in conjunction with basic data types to modify their size and range.

- 3.1 `signed`
  * Specifies that the variable can hold both positive and negative values (default for most types).

  ##### Example:

  ```C
  signed int num = -10;
  ```

- 3.2 `unsigned`
  * Specifies that the variable can only hold non-negative values (i.e., zero and positive numbers).

  ##### Example:

  ```C
  unsigned int num = 10;
  ```

- 3.3 `long`
  * Specifies that the variable is of long size, typically 4 or 8 bytes.

  ##### Example:

  ```C
  long num = 10000000L;
  ```

- 3.4 `short`
  * Specifies that the variable is of short size, typically 2 bytes.

  ##### Example:

  ```C
  short num = 100;
  ```
- 3.5 `long long`
  * Specifies an even larger integer type, typically 8 bytes.

  ##### Example:

  ```C
  long long num = 100000000000LL;
  ```

## 4. Type Size and Limits

In C, the exact size of a data type can vary depending on the platform (architecture, compiler, etc.). However, the C standard provides some guidelines about the minimum sizes and ranges.

- 4.1 `sizeof` Operator
  * The `sizeof`operator can be used to determine the size of a data type or variable.

  ##### Example:

  ```C
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of double: %zu bytes\n", sizeof(double));
  ```
- 4.2 Limits of Data Types
  * C provides the `limits.h` and `float.h` headers that define the limits for integer and floating-point types.

  ##### Example:

  ```C
  #include <limits.h>
  printf("Maximum value of int: %d\n", INT_MAX);
  printf("Minimum value of int: %d\n", INT_MIN);
  ```