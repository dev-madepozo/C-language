# Structures in C

Structures are a powerful feature in C that allow you to define complex data types by grouping different data types together. This can help you organize data efficiently and improve your program’s readability and maintainability.

## Table of Contents

1. [What are Structures?](#1-what-are-structures)
2. [Defining a Structure](#2-defining-a-structure)
3. [Accessing Structure Members](#3-accessing-structure-members)

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
