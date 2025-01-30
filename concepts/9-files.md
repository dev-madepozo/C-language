# Files in C

In C programming, working with files allows programs to store data permanently or retrieve it from external storage. Understanding file handling in C is essential for many applications, including data logging, configuration handling, and more. The C standard library provides a set of functions that allow for reading and writing files, as well as manipulating file pointers.

## Table of Contents

1. [Opening and Closing Files](#1-opening-and-closing-files)
2. [File Modes](#2-file-modes)
3. [Reading from Files](#3-reading-from-files)
4. [Writing to Files](#4-writing-to-files)
5. [File Positioning](#5-file-positioning)
7. [Conclusion](#7-conclusion)
8. [References](#8-references)

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

## 2. File Modes

  The `fopen()` function allows various modes to control the file access type. Common modes include:

  - `"r"`: Read mode. Opens the file for reading. The file must exist.
  - `"w"`: Write mode. Opens the file for writing. If the file doesn't exist, it is created; if it exists, its content is truncated.
  - `"a"`: Append mode. Opens the file for appending. If the file doesn't exist, it is created.
  - `"r+"`: Read/Write mode. Opens the file for both reading and writing. The file must exist.
  - `"w+"`: Write/Read mode. Opens the file for reading and writing. If the file exists, it is truncated; if not, it is created.
  - `"a+"`: Append/Read mode. Opens the file for reading and appending. If the file doesn't exist, it is created.

  **Example:**

  ```c
  FILE *file = fopen("data.txt", "w");  // Open for writing (create if not exists)
  if (file == NULL) {
      printf("Error opening file for writing.\n");
  }
  ```

## 3. Reading from Files

  To read from a file, C provides several functions, including `fgetc()`, `fgets()`, and `fread()`. These functions read one character, a line, or a block of data, respectively.

  - `fgetc()`: Reads a single character from a file.
  - `fgets()`: Reads a line of text from a file.
  - `fread()`: Reads a block of data into memory.

  **Example** (using `fgetc()`):

  ```c
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
  }

  char ch;
  while ((ch = fgetc(file)) != EOF) {
      printf("%c", ch);  // Print each character until EOF
  }

  fclose(file);
  ```

  **Example** (using `fgets()`):

  ```c
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
  }

  char buffer[256];
  while (fgets(buffer, sizeof(buffer), file)) {
      printf("%s", buffer);  // Print each line from the file
  }

  fclose(file);
  ```

## 4. Writing to Files

  To write to a file, C provides functions like `fputc()`, `fputs()`, and `fwrite()`.

  - `fputc()`: Writes a single character to a file.
  - `fputs()`: Writes a string to a file.
  - `fwrite()`: Writes a block of data to a file.

  **Example** (using fputc()):

  ```c
  FILE *file = fopen("output.txt", "w");
  if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
  }

  fputc('A', file);  // Write a single character
  fputc('\n', file);  // Write a newline

  fclose(file);
  ```

  **Example** (using fputs()):

  ```c
  FILE *file = fopen("output.txt", "w");
  if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
  }

  fputs("Hello, World!\n", file);  // Write a string

  fclose(file);
  ```

## 5. File Positioning

  File positioning refers to the location of the file pointer inside the file. You can manipulate the position of the pointer using the `fseek()`, `ftell()`, and `rewind()` functions.

  - `fseek(FILE *file, long offset, int whence)`: Moves the file pointer to a specified position.
  - `ftell(FILE *file)`: Returns the current position of the file pointer.
  - `rewind(FILE *file)`: Moves the file pointer to the beginning of the file.

  Example (using `fseek()` and `ftell()`):

  ```c
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
      printf("Error opening file.\n");
      return 1;
  }

  fseek(file, 10, SEEK_SET);  // Move the pointer to the 10th byte
  long pos = ftell(file);     // Get the current position
  printf("Current file position: %ld\n", pos);

  fclose(file);
  ```

## 7. Conclusion

  File handling in C is a powerful tool for managing persistent data. Whether you're reading from, writing to, or manipulating file content, understanding the functions provided by C's standard library helps you efficiently interact with external storage. Always ensure proper file closing and error checking to prevent memory leaks and data corruption.

## 8. References

  - C Programming Language by Brian W. Kernighan and Dennis M. Ritchie (2nd Edition)
  - ISO/IEC 9899:2018 - The C Programming Standard
  - C Standard Library Documentation: File I/O