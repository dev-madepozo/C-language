# Arrays in C

Arrays are a fundamental data structure in C that allow storing multiple values of the same data type in contiguous memory locations. Arrays provide an efficient way to manage large sets of data without having to declare individual variables for each element.

## Table of Contents

1. [Array Basics](#1-array-basics)
2. [Array Declaration and Initialization](#2-array-declaration-and-initialization)
3. [Array Access](#3-array-access)

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

- Declaration: Arrays are declared by specifying the data type of the elements, followed by the array name, and the size (number of elements).

```c
int arr[10]; // Declares an integer array of 10 elements
```

- Initialization: Arrays can be initialized at the time of declaration. If not initialized, elements in a static array are set to 0 by default (in some cases like global arrays).

  **Example 1:** Initializing with specific values

  ```c
  int arr[5] = {10, 20, 30, 40, 50};
  ```

  **Example 2:** Partial initialization

  ```c
  int arr[5] = {1, 2};  // The rest of the elements are set to 0
  ```

  **Example 3:** Array size can be automatically determined from the initializer


  ```c
  int arr[] = {1, 2, 3, 4, 5};  // Compiler determines size as 5
  ```

## 3. Array Access

Arrays in C are accessed by their index. The index starts at 0 for the first element and continues up to `size-1` for an array of `size` elements.

Syntax: `array_name[index]`

**Example:**

```c
int arr[3] = {10, 20, 30};
printf("%d", arr[0]);  // Outputs: 10
printf("%d", arr[1]);  // Outputs: 20
```
