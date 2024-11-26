# Control Flow

Control flow in C refers to the order in which individual statements, instructions, or function calls are executed in a program. The ability to control the flow of execution is critical for developing algorithms and managing program behavior based on conditions, loops, and branching. C provides several mechanisms to control the flow of execution, including conditional statements, loops, and control statements like `break`, `continue`, and `return`.

## Table of Contents

1. [Conditional Statements](#1-conditional-statements)

Conditional statements allow a program to execute certain blocks of code based on whether a condition is true or false.

## 1. Conditional Statements

- **1.1 `if` Statement**
  \
  The `if` statement is used to evaluate a condition and execute a block of code only if the condition is true.
  \
  **Syntax:**

  ```c
  if (condition) {
    // Code to execute if condition is true
  }
  ```

  **Example:**

  ```c
  int a = 5;
  if (a > 0) {
    printf("a is positive\n");
  }
  ```

- **1.2 `if-else` Statement**
  \
  The `if-else` statement allows you to specify a block of code to execute when the condition is false.
  \
  **Syntax:**
  ```c
  if (condition) {
    // Code to execute if condition is true
  } else {
    // Code to execute if condition is false
  }
  ```

  **Example:**
  ```c
  int a = -3;
  if (a > 0) {
    printf("a is positive\n");
  } else {
    printf("a is not positive\n");
  }
  ```
