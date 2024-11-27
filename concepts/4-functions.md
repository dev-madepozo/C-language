# Functions in C

Functions are a fundamental part of C programming. They allow you to organize your code into reusable blocks, making it more modular, easier to read, and maintain. Functions are used to perform specific tasks or computations and can be called from various places within the program.

## Table of Contents

1. [What is a Function?](#1-what-is-a-function)
2. [Function Declaration (Prototypes)](#2-function-declaration-prototypes)
3. [Function Definition](#3-function-definition)

## 1. What is a Function?

  A function in C is a block of code that performs a specific task. Functions can take input in the form of parameters, perform operations, and return a result. Functions help break down complex problems into smaller, manageable chunks.

  Functions in C can be categorized into two types:

  - **Standard Library Functions:** Provided by the C Standard Library (e.g., printf, scanf).
  - **User-defined Functions:** Created by the programmer to perform specific tasks.

## 2. Function Declaration (Prototypes)

  Before using a function, you can optionally declare its prototype, which tells the compiler about the function's name, return type, and parameters (if any). This is often done at the beginning of the program, before `main()`.

  **Syntax:**

  ```c
  return_type function_name(parameter1_type parameter1, parameter2_type parameter2, ...);
  ```

  **Example:**

  ```c
  int add(int a, int b);  // Function prototype
  ```

  The prototype ensures that the function is used correctly (i.e., with the right types of arguments and return type). If you don’t declare a function prototype, the compiler will assume the function's return type is `int` and it will try to infer the parameters (which can lead to errors).


## 3. Function Definition

  The function definition is where the actual code of the function resides. It consists of the return type, function name, parameters, and the body of the function that performs the desired task.

  **Syntax:**

  ```c
  return_type function_name(parameter1_type parameter1, parameter2_type parameter2, ...) {
    // Function body: code to perform the task
    return return_value;  // Optional, depending on the return type
  }
  ```

  **Example:**

  ```c
  #include <stdio.h>

  // Function definition
  int add(int a, int b) {
    return a + b;
  }

  int main() {
    int result = add(3, 4); // Function call
    printf("The result is: %d\n", result);  // Output: 7
    return 0;
  }
  ```

  In this example:

  - `add` is a user-defined function that takes two integers as parameters (`a` and `b`) and returns their sum.
  - The `main` function call `add(3, 4)` and stores the result in the variable `result`.

