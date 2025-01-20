# Arrays in C

Arrays are a fundamental data structure in C that allow storing multiple values of the same data type in contiguous memory locations. Arrays provide an efficient way to manage large sets of data without having to declare individual variables for each element.

## Table of Contents

1. [Array Basics](#1-array-basics)
2. [Array Declaration and Initialization](#2-array-declaration-and-initialization)
3. [Array Access](#3-array-access)
4. [Types of Arrays](#4-types-of-arrays)

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

## 4. Types of Arrays

- 4.1 One-dimensional Arrays

  A one-dimensional array is the simplest form of an array. It is a list of elements of the same data type.

  **Example:**

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  ```

- 4.2 Two-dimensional Arrays

  A two-dimensional array is essentially an array of arrays. It is often used to represent matrices or grids.

  **Example:**

  ```c
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  ```

- 4.3 Multidimensional Arrays

  You can define arrays with more than two dimensions. Each additional dimension adds a level of complexity for organizing and accessing the data.

  **Example:**

  ```c
  int arr[2][3][4];  // A 3D array with dimensions 2x3x4
  ````

## 5. Common Operations on Arrays

- 5.1 Array Traversal

  To traverse (or loop through) an array, you can use a loop to access each element in the array.

  **Example:**

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
      printf("%d ", arr[i]);  // Outputs: 1 2 3 4 5
  }
  ```

- 5.2 Copying Arrays

  Arrays in C cannot be directly copied using assignment. You need to use a loop to copy elements from one array to another.

  **Example:**

  ```c
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5];
  for (int i = 0; i < 5; i++) {
      arr2[i] = arr1[i];
  }
  ```

- 5.3 Finding the Length of an Array

  In C, arrays do not store their length, so you need to either track it manually or use the `sizeof` operator to calculate it.

  **Example:**

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  int length = sizeof(arr) / sizeof(arr[0]);  // Length = 5
  printf("Length of array: %d\n", length);
  ```

- 5.4 Summing Array Elements

  A common operation is to sum the elements of an array. This can be done with a simple loop.

  **Example:**

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  int sum = 0;
  for (int i = 0; i < 5; i++) {
      sum += arr[i];  // Sum becomes 15
  }
  printf("Sum of elements: %d\n", sum);  // Outputs: 15
  ```

- 5.5 Reversing an Array

  Reversing an array can be done by swapping elements from the start with elements from the end.

  **Example:**

  ```c
  int arr[5] = {1, 2, 3, 4, 5};
  int temp, start = 0, end = 4;
  while (start < end) {
      temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
  }
  ```

