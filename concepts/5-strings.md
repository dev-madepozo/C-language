# Strings in C

Strings are sequences of characters, usually terminated by a null character `(\0)`. Unlike many other programming languages, C does not have a dedicated string data type. Instead, strings are implemented as arrays of characters. Understanding how to manipulate strings in C is essential for working with text data.

## Table of Contents

1. [String Basics](#1-string-basics)
2. [String Declaration and Initialization](#2-string-declaration-and-initialization)
3. [String Access](#3-string-access)
4. [Common String Functions](#4-common-string-functions)

## 1. String Basics

  - **Definition**: A string in C is an array of characters, followed by a null terminator `(\0)`, marking the end of the string. This is essential because C does not track string length automatically.

  - **Size**: The size of a string is determined by the number of characters before the null terminator. Unlike arrays, the length of a string must be calculated manually or using built-in functions.

  `Key Concept`: In C, strings are zero-indexed, meaning the first character is at index 0.

  **Example:**

  ```c
  char str[] = "Hello, World!";
  ```

  Here, `str` is a string of 13 characters, and the null terminator `\0` is automatically added by the compiler, making the full string size 14 characters.


## 2. String Declaration and Initialization

  - **Declaration**: Strings can be declared using either character arrays or pointers.

  ```c
  char str[20];  // Array to hold a string with a maximum of 19 characters (plus null terminator)
  ```

  - **Initialization**: A string can be initialized using a string literal. If not initialized explicitly, the array elements contain garbage values unless the array is static or global.

  **Example 1:** Initializing with a string literal

  ```c
  char str[] = "Hello";  // Automatically includes the null terminator
  ```

  **Example 2:** Partial initialization

  ```c
  char str[10] = "Hi";  // Remaining characters are filled with null characters ('\0')
  ```

  **Example 3:** String size can be determined automatically from the initializer

  ```c
  char str[] = "World";  // The size of str is automatically set to 6
  ```

## 3. String Access

  Strings are arrays of characters, so individual characters can be accessed using array indexing or pointers.

  - **Access via Indexing**: You can access individual characters of a string using array indexing. The first character is accessed at index `0`.

  **Example:**

  ```c
  char str[] = "Hello";
  printf("%c\n", str[0]);  // Outputs: H
  printf("%c\n", str[1]);  // Outputs: e
  ```

  - **Access via Pointers**: Strings are often manipulated using pointers. The string name itself is a pointer to the first character.

  **Example:**

  ```c
  char *str = "Hello";
  printf("%c\n", *(str + 1));  // Outputs: e
  ```

## 4. Common String Functions

  The C standard library provides several useful functions for string manipulation, which are defined in `<string.h>`.

  - **strlen()**: Returns the length of the string (not including the null terminator).

    ```c
    size_t len = strlen("Hello, World!");  // len = 13
    ```

  - **strcpy()**: Copies one string into another. The destination array must be large enough to hold the source string and the null terminator.

    ```c
    char dest[20];
    strcpy(dest, "Hello, World!");
    ```

  - **strcat()**: Appends one string to another. Ensure the destination array is large enough.

    ```c
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);  // str1 now contains "Hello, World!"
    ```

  - **strcmp()**: Compares two strings lexicographically.

    ```c
    int result = strcmp("apple", "banana");  // result < 0 because "apple" is lexicographically smaller
    ```
  
  - **strchr()**: Finds the first occurrence of a character in a string.

    ```c
    char *ptr = strchr("Hello, World!", 'o');  // ptr points to the first 'o'
    ```

  - **strstr()**: Finds the first occurrence of a substring in a string.

    ```c
    char *ptr = strstr("Hello, World!", "World");  // ptr points to "World!"
    ```
