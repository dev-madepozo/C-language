# Arrays in C

Arrays are a fundamental data structure in C that allow storing multiple values of the same data type in contiguous memory locations. Arrays provide an efficient way to manage large sets of data without having to declare individual variables for each element.

## Table of Contents

1. [Array Basics](#1-array-basics)
2. [Array Declaration and Initialization](#2-array-declaration-and-initialization)

## 1. Array Basics

- Definition: An array is a collection of elements of the same data type stored in contiguous memory locations. Arrays allow for efficient data management and retrieval.

- Size: The size of an array is defined at the time of declaration and cannot be changed dynamically unless using dynamic memory allocation (e.g., with malloc).

Key Concept: In C, arrays are zero-indexed, meaning the first element of an array is accessed with index 0.

**Example:**

```c
int numbers[5] = {1, 2, 3, 4, 5};
```
Here, numbers is an array of 5 integers, and the values are stored as `numbers[0] = 1`, `numbers[1] = 2`, ..., `numbers[4] = 5`.

## 2. Array Declaration and Initialization
