# Functions in C

Functions are a fundamental part of C programming. They allow you to organize your code into reusable blocks, making it more modular, easier to read, and maintain. Functions are used to perform specific tasks or computations and can be called from various places within the program.

## Table of Contents

1. [What is a Function?](#1-what-is-a-function)
2. [Function Declaration (Prototypes)](#2-function-declaration-prototypes)
3. [Function Definition](#3-function-definition)
4. [Function Call](#4-function-call)
5. [Return Type](#5-return-type)
6. [Passing Arguments to Functions](#6-passing-arguments-to-functions)
7. [Function Overloading](#7-function-overloading-not-supported-in-c)

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

## 4. Function Call

  To execute the code inside a function, you need to call it from another function, usually `main()`. A function call consists of the function name followed by a list of arguments in parentheses (if the function takes parameters).

  **Syntax:**

  ```c
  function_name(argument1, argument2, ...);
  ```

  **Example:+*
  ```c
  int main() {
    int result = add(10, 20);  // Calling the add function
    printf("The sum is: %d\n", result);
    return 0;
  }
  ```

  In this case, `add(10, 20)` is the function call, and it passes the values `10` and `20` as arguments to the add function.

## 5. Return Type

  The return type specifies the type of value the function will return to the caller. If the function does not return a value, the return type is specified as `void`.

- **5.1 Functions with Return Values**

  If the function returns a value, you need to specify the return type, and use the `return` statement to return the value.

  **Example:**

  ```c
  int multiply(int x, int y) {
    return x * y;  // Returns the product of x and y
  }
  ```

- **5.2 Functions with No Return Value**

  If a function does not return a value, you use the `void` keyword as the return type.

  **Example:**

  ```c
  void printMessage() {
    printf("Hello, World!\n");
  }
  ```

- **5.3 Using return in Functions**

  The `return` statement exits a function and optionally returns a value to the caller. If the function is of type `void`, the `return` statement is used without any return value.

  **Examples:**

  ```c
  // Returning a value
  int square(int n) {
    return n * n; // Return the square of n
  }

  // Using return in a void function
  void printMessage() {
    printf("Function execution completed.\n");
    return;  // End of the function (optional for void functions)
  }
  ```

## 6. Passing Arguments to Functions

  There are two ways to pass arguments to functions in C:

  * **Pass by Value**: The actual value of the argument is passed to the function.
  * **Pass by Reference** (using pointers): The memory address of the argument is passed, allowing the function to modify the original value.

- **6.1 Pass by Value**

  In pass by value, the function gets a copy of the argument value, and any changes made to the parameter inside the function do not affect the original argument.

  **Example:**

  ```c
  void changeValue(int a) {
    a = 10;  // This change will not affect the original variable
  }

  int main() {
      int x = 5;
      changeValue(x);
      printf("x = %d\n", x);  // Output: x = 5 (unchanged)
      return 0;
  }

  ```

- **6.2 Pass by Reference**

  In pass by reference, the function receives the memory address (pointer) of the argument, so any changes made to the parameter will affect the original argument.

  **Example:**

  ```c
  void changeValue(int *a) {
    *a = 10;  // Dereferencing pointer to change the original variable
  }

  int main() {
      int x = 5;
      changeValue(&x);  // Pass the address of x
      printf("x = %d\n", x);  // Output: x = 10
      return 0;
  }
  ```

  In this example, `changeValue(&x)` passes the address of `x` to the function. The function modifies the original value of `x` via the pointer `a`.

## 7. Function Overloading (Not Supported in C)

  C does not support function overloading, which is a feature present in languages like C++ where you can have multiple functions with the same name but different parameter types. In C, all functions must have unique names.
