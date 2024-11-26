# Control Flow

Control flow in C refers to the order in which individual statements, instructions, or function calls are executed in a program. The ability to control the flow of execution is critical for developing algorithms and managing program behavior based on conditions, loops, and branching. C provides several mechanisms to control the flow of execution, including conditional statements, loops, and control statements like `break`, `continue`, and `return`.

## Table of Contents

1. [Conditional Statements](#1-conditional-statements)
2. [Looping Statements](#2-looping-statements)

## 1. Conditional Statements

Conditional statements allow a program to execute certain blocks of code based on whether a condition is true or false.

- **1.1 `if` Statement**

  The `if` statement is used to evaluate a condition and execute a block of code only if the condition is true.

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

  The `if-else` statement allows you to specify a block of code to execute when the condition is false.

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

- **1.3 `if-else if-else` Statement**

  The `if-else if-else` statement allows you to check multiple conditions sequentially.

  **Syntax:**

  ```c
  if (condition1) {
    // Code to execute if condition1 is true
  } else if (condition2) {
    // Code to execute if condition2 is true
  } else {
    // Code to execute if no condition is true
  }
  ```

  **Example:**

  ```c
  int a = 0;
  if (a > 0) {
    printf("a is positive\n");
  } else if (a < 0) {
    printf("a is negative\n");
  } else {
    printf("a is zero\n");
  }
  ```

- **1.4 `switch` Statement**

  The `switch` statement is used when you have multiple conditions based on the value of a single variable. It is an alternative to multiple `if-else` conditions when checking for equality.

  **Syntax:**

  ```c
  switch (expression) {
    case constant1:
      // Code to execute if expression == constant1
      break;
    case constant2:
      // Code to execute if expression == constant2
      break;
    default:
      // Code to execute if expression does not match any case
  }
  ```

  **Example:**

  ```c
  int day = 3;
  switch (day) {
    case 1:
      printf("Monday\n");
      break;
    case 2:
      printf("Tuesday\n");
      break;
    case 3:
      printf("Wednesday\n");
      break;
    default:
      printf("Invalid day\n");
  }
  ```

## 2. Looping Statements

Loops are used to repeatedly execute a block of code as long as a specified condition is true. C provides three types of loops: `for`, `while`, and `do-while`.

- **2.1 `for`Loop**

  The `for` loop is used when you know in advance how many times the loop should execute. It has three parts: initialization, condition, and increment/decrement.

  **Syntax:**

  ```c
  for (initialization; condition; increment/decrement) {
    // Code to execute while condition is true
  }
  ```

  **Example:**

  ```c
  for (int i = 0; i < 5; i++) {
    printf("%d\n", i);  // Prints 0, 1, 2, 3, 4
  }
  ```

- **2.2 `while`Loop**

  The `while` loop repeatedly executes a block of code as long as the condition is true. It checks the condition before each iteration.

  **Syntax:**

  ```c
  while (condition) {
    // Code to execute while condition is true
  }
  ```

  **Example:**

  ```c
  int i = 0;
  while (i < 5) {
    printf("%d\n", i);  // Prints 0, 1, 2, 3, 4
    i++;
  }
  ```

- **2.3 `do-while`Loop**

  The `do-while` loop is similar to the `while` loop, except that it guarantees that the block of code will execute at least once, as the condition is checked after the code block is executed.

  **Syntax:**

  ```c
  do {
    // Code to execute
  } while (condition);
  ```

  **Example:**

  ```c
  int i = 0;
  do {
    printf("%d\n", i);  // Prints 0, 1, 2, 3, 4
    i++;
  } while (i < 5);
  ```

