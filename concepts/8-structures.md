# Structures in C

Structures are a powerful feature in C that allow you to define complex data types by grouping different data types together. This can help you organize data efficiently and improve your program’s readability and maintainability.

## Table of Contents

1. [What are Structures?](#1-what-are-structures)
2. [Defining a Structure](#2-defining-a-structure)
3. [Accessing Structure Members](#3-accessing-structure-members)
4. [Nested Structures](#4-nested-structures)
5. [Structures and Pointers](#5-structures-and-pointers)
6. [Structures with Functions](#6-structures-with-functions)
7. [Conclusion](#7-conclusion)
8. [References](#8-references)

## 1. What are Structures?

In C, a `structure` is a user-defined data type that allows the grouping of variables of different types under a single name. It is particularly useful when you need to represent an entity that has multiple attributes.

**Key Points:**
- A structure can contain data of different types (int, float, char, etc.).
- It is defined using the `struct` keyword.
- Structure variables are treated as a whole but can access individual members via a dot operator (`.`).

## 2. Defining a Structure

To define a structure, use the `struct` keyword followed by the structure name and a list of members (variables of different data types).

**Syntax:**

```c
struct structure_name {
    data_type member1;
    data_type member2;
    // More members
};
```

**Example:**

```c
#include <stdio.h>

struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    struct Person person1; // Declare a structure variable

    // Assign values to structure members
    person1.age = 30;
    person1.height = 5.5;
    snprintf(person1.name, sizeof(person1.name), "Alice");

    // Access and print structure members
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f\n", person1.height);

    return 0;
}
```

## 3. Accessing Structure Members

To access members of a structure, use the dot operator (`.`) with a structure variable.

**Example:**

```c
struct Person person1;
person1.age = 30;
printf("Age: %d\n", person1.age);
```

If you are working with pointers to structures, use the arrow operator (`->`) to access members.

**Example:**

```c
struct Person *ptr = &person1;
ptr->age = 30;
printf("Age via pointer: %d\n", ptr->age);
```

## 4. Nested Structures

Structures in C can also contain other structures as members, which is known as a nested structure.

**Example:**

```c
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    int age;
    struct Date birthDate;  // Nested structure
};

int main() {
    struct Person person1;

    // Assign values to structure members
    person1.age = 30;
    snprintf(person1.name, sizeof(person1.name), "Alice");
    person1.birthDate.day = 15;
    person1.birthDate.month = 7;
    person1.birthDate.year = 1990;

    // Print nested structure members
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Birth Date: %d/%d/%d\n", person1.birthDate.day, person1.birthDate.month, person1.birthDate.year);

    return 0;
}
```

## 5. Structures and Pointers

When using pointers to structures, the memory is referenced via the pointer. This allows you to modify structure members dynamically and efficiently.

**Example:**

```c
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person person1 = {"John", 25};
    struct Person *ptr = &person1;

    // Access and modify members via pointer
    ptr->age = 30;
    snprintf(ptr->name, sizeof(ptr->name), "Jane");

    // Print modified data
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);

    return 0;
}
```

## 6. Structures with Functions

Structures can be passed to functions either by value or by reference (using pointers). Passing by reference avoids copying large structures and can improve performance.

**Pass by Value:**

```c
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void printPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    struct Person person1 = {"Alice", 30};
    printPerson(person1); // Pass by value
    return 0;
}
```

**Pass by Reference:**

```c
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void incrementAge(struct Person *p) {
    p->age++;
}

int main() {
    struct Person person1 = {"Alice", 30};
    incrementAge(&person1); // Pass by reference (pointer)
    printf("New Age: %d\n", person1.age);
    return 0;
}
```

## 7. Conclusion

Structures are essential in C programming for organizing data into more meaningful, complex types. By grouping different types under a single name, structures help make programs more readable, modular, and maintainable. Understanding how to define and use structures is crucial for any C programmer.

## 8. References

- The C Programming Language by Brian W. Kernighan and Dennis M. Ritchie (2nd Edition)
- ISO/IEC 9899:2018 - The C Programming Standard
- C Programming Tutorials and Examples - [GeeksforGeeks](https://www.geeksforgeeks.org/c-programming-language/)
