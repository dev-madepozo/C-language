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
  | `>=`     | Greater than or equal to | `x >= y` |

  **Example:**

  ```C
  int a = 10, b = 20;

  if (a < b) {
      printf("a is less than b\n"); // This will be printed
  }
  ```

- **1.3 Logical Operators**

  Logical operators are used to perform logical operations. They are commonly used with boolean (or integer) expressions.

  | Operator | Description | Example    |
  | :------: | :---------- | :--------: |
  | `&&`     | Logical AND | `x == y`   |
  | `\|\|`   | Logical OR  | `x \|\| y` |
  | `!`      | Logical NOT | `x != y`   |

  **Example:**
  
  ```C
  int a = 1, b = 0;

  if (a && !b) {
      printf("a is true and b is false\n"); // This will be printed
  }
  ```

- **1.4 Bitwise Operators**

  Bitwise operators are used to perform operations on individual bits of a number. These are mainly used for low-level programming.

  | Operator | Description | Example  |
  | :------: | :---------- | :------: |
  | `&`      | Bitwise AND | `a & b`  |
  | `\|`     | Bitwise OR  | `a \| b` |
  | `^`      | Bitwise XOR | `a ^ b`  |
  | `~`      | Bitwise NOT | `~a`     |
  | `<<`     | Left shift  | `a << 2` |
  | `>>`     | Right shift | `a >> 2` |

  **Example:**

  ```C
  int a = 5, b = 3; // a = 0101, b = 0011 (binary)
  int and_result = a & b;  // and_result = 1 (binary 0001)
  int or_result = a | b;   // or_result = 7 (binary 0111)
  int xor_result = a ^ b;  // xor_result = 6 (binary 0110)
  int not_result = ~a;     // not_result = -6 (two's complement)
  ```

