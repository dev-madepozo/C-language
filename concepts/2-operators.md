# Operators in C

In C programming, operators are symbols used to perform operations on variables and values. C provides a rich set of operators for performing mathematical, logical, relational, and bitwise operations. Operators in C can be classified into several categories based on their functionality.

## Table of Contents

1. [Types of Operators](#1-types-of-operators)
2. [Operator Precedence and Associativity](#2-operator-precedence-and-associativity)
3. [Summary](#3-summary)
4. [References](#4-references)

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
  int a = 5, b = 3;        // a = 0101, b = 0011 (binary)
  int and_result = a & b;  // and_result = 1 (binary 0001)
  int or_result = a | b;   // or_result = 7 (binary 0111)
  int xor_result = a ^ b;  // xor_result = 6 (binary 0110)
  int not_result = ~a;     // not_result = -6 (two's complement)
  ```

- **1.5 Assignment Operators**

  Assignment operators are used to assign values to variables. They combine assignment with other operations.

  | Operator | Description         | Example  |
  | :------: | :------------------ | :------: |
  | `=`      | Simple assignment   | `a = b`  |
  | `+=`     | Add and assign      | `a += b` |
  | `-=`     | Subtract and assign | `a -= b` |
  | `*=`     | Multiply and assign | `a *= b` |
  | `/=`     | Divide and assign   | `a /= b` |
  | `%=`     | Modulo and assign   | `a %= b` |

  **Example:**

  ```C
  int a = 5, b = 3;
  a += b;  // a = a + b -> a = 8
  a *= 2;  // a = a * 2 -> a = 16
  ```

- **1.6 Unary Operators**

  Unary operators are applied to a single operand. They can perform operations such as incrementing, decrementing, and negating.

  | Operator | Description | Example        |
  | :------: | :---------- | :------------: |
  | `++`     | Increment   | `a++` or `++a` |
  | `--`     | Decrement   | `a--` or `--a` |
  | `+`      | Unary plus  | `+a`           |
  | `-`      | Unary minus | `-a`           |
  | `!`      | Logical NOT | `!a`           |
  | `~`      | Bitwise NOT | `~a`           |

  **Example:**

  ```C
  int a = 5;
  a++;   // a = 6 (post-increment)
  ++a;   // a = 7 (pre-increment)
  a--;   // a = 6 (post-decrement)
  --a;   // a = 5 (pre-decrement)
  ```

- **1.7 Conditional (Ternary) Operator**

  The conditional operator (also known as the ternary operator) is a shorthand for an `if-else` statement.

  | Operator | Description           | Example                     |
  | :------: | :-------------------- | :-------------------------: |
  | `? :`    | Conditional (ternary) | `condition ? expr1 : expr2` |

  **Example:**

  ```C
  int a = 10, b = 20;
  int max = (a > b) ? a : b; // max will be 20
  ```

- **1.8 Comma Operator**

  The comma operator allows you to evaluate multiple expressions, but only the result of the last expression is returned.

  | Operator | Description    | Example               |
  | :------: | :------------- | :-------------------: |
  | `,`      | Comma operator | `expr1, expr2, expr3` |

  **Example:**

  ```C
  int a = 5, b = 10;
  int result = (a++, b++, a + b); // a is incremented to 6, b to 11, result = 17
  ```

## 2. Operator Precedence and Associativity

  Operator precedence determines the order in which operators are evaluated in an expression. Operators with higher precedence are evaluated first. If two operators have the same precedence, associativity defines the order of evaluation.

- **2.1 Precedence Table (from highest to lowest)**

  | Operator Type	| Operators                                                            |
  | :------------ | :------------------------------------------------------------------- |
  | Postfix       | `expr++`, `expr--`                                                   |
  | Prefix        | `++expr`, `--expr`, `+`, `-`, `!`, `~`, `sizeof`, `&`, `*`, `sizeof` |
  | Arithmetic    | `*`, `/`, `%`                                                        |
  | Relational    | `<`, `<=`, `>`, `>=`                                                 |
  | Equality      | `==`, `!=`                                                           |
  | Bitwise       | `&`, `^`, `\|`                                                       |
  | Logical       | `&&`, `\|\|`                                                         |
  | Conditional   | `? :`                                                                |
  | Assignment    | `=`, `+=`, `-=`, `*=`, `/=`, `%=`                                    |
  | Comma         | `,`                                                                  |

- **2.2 Associativity**

  - Most operators have left-to-right associativity, meaning they are evaluated from left to right.
  - Assignment (`=`), conditional (`? :`), and increment/decrement (`++`, `--`) operators have right-to-left associativity.

## 3. Summary

In C, operators are crucial to performing various tasks such as arithmetic calculations, comparisons, logical tests, and bit manipulation. Understanding the different types of operators and their precedence is essential for writing efficient and correct C programs.

#### Key Takeaways:

- Arithmetic operators allow you to perform mathematical operations.
- Relational and logical operators are used for comparisons and logical operations.
- Bitwise operators help manipulate data at the bit level.
- Assignment operators enable the modification of variables.
- Unary and ternary operators simplify code for single operand or conditional operations.

## 4. References:
- C Programming Language by Brian W. Kernighan and Dennis M. Ritchie (2nd Edition)
- ISO/IEC 9899:2018 - The C Programming Standard
