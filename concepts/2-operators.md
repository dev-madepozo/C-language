# Operators in C

In C programming, operators are symbols used to perform operations on variables and values. C provides a rich set of operators for performing mathematical, logical, relational, and bitwise operations. Operators in C can be classified into several categories based on their functionality.

## Table of Contents

1. [Types of Operators](#1-types-of-operators)


## 1. Types of Operators

- **1.1 Arithmetic Operators**
  These operators are used to perform basic arithmetic calculations.

  | Operator | Description    | Example |
  | :------: | :------------- | :-----: |
  | `+`      | Addition       | `x + y` |
  | `-`      | Subtraction    | `x - y` |
  | `*`      | Multiplication | `x * y` |
  | `/`      | Division       | `x / y` |
  | `%`      | Modulo         | `x % y` |

  **Example:**

  ```C
  int a = 10, b = 5;
  int sum = a + b;     // sum = 15
  int diff = a - b;    // diff = 5
  int product = a * b; // product = 50
  int quotient = a / b; // quotient = 2
  int remainder = a % b; // remainder = 0
  ```

- **1.2 Relational Operators**
  Relational operators are used to compare two values or variables. They return a boolean result (`true` or `false`)

  | Operator | Description              | Example  |
  | :------: | :----------------------- | :------: |
  | `==`     | Equal to                 | `x == y` |
  | `!=`     | Not equal to             | `x != y` |
  | `<`      | Less than                | `x < y`  |
  | `<=`     | Less than or equal to    | `x <= y` |
  | `>`      | Greater than             | `x > y`  |
  | `>=`     | Greater than or equal to | `x > y`  |

  **Example:**

  ```C
  int a = 10, b = 20;

  if (a < b) {
      printf("a is less than b\n"); // This will be printed
  }
  ```