# Files in C

In C programming, working with files allows programs to store data permanently or retrieve it from external storage. Understanding file handling in C is essential for many applications, including data logging, configuration handling, and more. The C standard library provides a set of functions that allow for reading and writing files, as well as manipulating file pointers.

## Table of Contents

1. [Opening and Closing Files](#1-opening-and-closing-files)


## 1. Opening and Closing Files

In C, you open a file using the `fopen()` function, which returns a pointer to a `FILE` structure. This pointer is then used to perform file operations. After finishing file operations, you should close the file using `fclose()` to free up resources.

- **Open a File**

  The `fopen()` function takes two arguments:

  1. The file name.
  2. The mode in which the file is to be opened (e.g., reading, writing).

  **Example:**

  ```c
  FILE *file = fopen("example.txt", "r");  // Open for reading
  if (file == NULL) {
      printf("Error opening file.\n");
  }
  ```

- **Closing a File**

  After operations on a file are done, use `fclose()` to close it and release the resources.

  **Example:**

  ```c
  fclose(file);
  ```
