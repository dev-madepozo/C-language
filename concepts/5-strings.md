# Strings in C

In C, a string is a sequence of characters terminated by a null character (\0). Unlike languages like Python or Java, C does not have a dedicated string type. Instead, strings are typically represented as arrays of characters.

## Table of Contents

## 1. Overview of Strings in C

  - **String Representation:** A string in C is an array of characters, followed by a null terminator (`'\0'`), which marks the end of the string.

    ```c
    char str[] = "Hello, World!";
    // Equivalent to:
    // char str[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    ```

  - **String Length:** The length of a string is the number of characters before the null terminator. To determine this length, you can use the strlen() function.

## 2. Basic String Operations

  - **Declaring and Initializing Strings:**

    String literals: A string can be initialized with a string literal.

    ```c
    char str[] = "Hello, World!";  // String with automatic null termination
    ```

    Pointers to strings:

    ```c
    char *str = "Hello, World!";   // Points to a string literal
    ```

  - **Accessing Characters:**

    Since strings are just arrays of characters, you can access individual characters using array indexing or pointers.

    ```c
    char str[] = "Hello";
    char c = str[1];  // Accesses 'e'
    ```

## 3. Common String Functions

  The C standard library provides a set of functions for string manipulation, declared in the `<string.h>` header.

  - `strlen()`: Returns the length of a string (not including the null terminator).

    ```c
    size_t len = strlen("Hello");  // len = 5
    ```
  
  - `strcpy()`: Copies one string to another.

    ```c
    char dest[20];
    strcpy(dest, "Hello, World!");
    ```
  
  - `strcat()`: Concatenates (appends) one string to another.

    ```c
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);  // str1 now contains "Hello, World!"
    ```