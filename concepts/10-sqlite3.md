# Sqlite3 in C

SQLite3 is a C-language library that implements a small, fast, self-contained, high-reliability, full-featured SQL database engine. It is widely used due to its simplicity and ease of integration with C programs.

## Table of Contents

1. [Introduction to SQLite3](#1-introduction-to-sqlite3)
2. [SQLite3 Data Types](#2-sqlite3-data-types)
3. [SQLite3 Functions](#3-sqlite3-functions)
4. [Working with SQLite3 Databases](#4-working-with-sqlite3-databases)
5. [Prepared Statements](#5-prepared-statements)

## 1. Introduction to SQLite3

  SQLite3 is an embedded SQL database engine. Unlike many other SQL database management systems, SQLite is not a client-server database engine but rather an embedded, self-contained, file-based database that integrates into your application. This makes it ideal for local storage, mobile apps, and small applications.

  To start using SQLite3 in C, you'll need to include the `sqlite3.h` header and link against the SQLite3 library.

  **Example:**

  ```c
  #include <sqlite3.h>

  int main() {
      sqlite3 *db;
      int rc = sqlite3_open("example.db", &db);
      if (rc) {
          printf("Can't open database: %s\n", sqlite3_errmsg(db));
      } else {
          printf("Opened database successfully\n");
      }
      sqlite3_close(db);
      return 0;
  }
  ```

## 2. SQLite3 Data Types

  SQLite3 uses dynamic typing, which means it doesn't strictly enforce data types as in other databases. For instance, you can insert a string value into a column that is defined as an integer type. However, SQLite3 does have a set of common data types.

  - **INTEGER**: Used for integer values. Can store values of any integer size.
  - **REAL**: Used for floating-point numbers.
  - **TEXT**: Used for strings (UTF-8, UTF-16, or UTF-32).
  - **BLOB**: Used for storing binary data (e.g., images, files).
  
  SQLite3’s data types are more flexible than strict SQL implementations. It allows you to store any type of value in any column, but it does have "preferred" types for certain operations.

  **Example:**

  ```c
  sqlite3_stmt *stmt;
  const char *sql = "INSERT INTO users (id, name, age) VALUES (?, ?, ?)";
  sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  // Bind data to the placeholders
  sqlite3_bind_int(stmt, 1, 1);            // INTEGER
  sqlite3_bind_text(stmt, 2, "Alice", -1, SQLITE_STATIC); // TEXT
  sqlite3_bind_int(stmt, 3, 30);           // INTEGER

  // Execute the query
  sqlite3_step(stmt);

  // Finalize the statement
  sqlite3_finalize(stmt);
  ```

## 3. SQLite3 Functions

  SQLite3 provides several functions to interact with the database. These functions include opening and closing databases, preparing SQL statements, executing queries, and handling errors.

  Key Functions:
  
  - `sqlite3_open()`: Opens a database file.
  - `sqlite3_close()`: Closes a database connection.
  - `sqlite3_exec()`: Executes an SQL statement that does not return data (e.g., INSERT, UPDATE).
  - `sqlite3_prepare_v2()`: Prepares a statement for execution.
  - `sqlite3_step()`: Executes a prepared statement.
  - `sqlite3_errmsg()`: Retrieves the last error message.

  **Example:**

  ```c
  sqlite3 *db;
  char *errMsg = 0;
  int rc = sqlite3_open("test.db", &db);
  if (rc) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
  } else {
      fprintf(stderr, "Opened database successfully\n");
  }

  // Example SQL query
  const char *sql = "SELECT * FROM users";
  rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

  if (rc != SQLITE_OK) {
      fprintf(stderr, "SQL error: %s\n", errMsg);
      sqlite3_free(errMsg);
  } else {
      fprintf(stdout, "Operation completed successfully\n");
  }

  sqlite3_close(db);
  ```

## 4. Working with SQLite3 Databases

  To work with SQLite3 databases, you'll need to open the database, run SQL queries (using either direct SQL or prepared statements), and close the database after you're done.

  **Opening a Database**
  
  You can open a SQLite3 database using `sqlite3_open()`. If the database does not exist, it will be created.

  ```c
  sqlite3 *db;
  int rc = sqlite3_open("example.db", &db);
  if (rc) {
      printf("Can't open database: %s\n", sqlite3_errmsg(db));
  } else {
      printf("Opened database successfully\n");
  }
  ```

  **Closing a Database**
  
  After you're done, you should close the database connection to free up resources.

  ```c
  sqlite3_close(db);
  ```

## 5. Prepared Statements

  Prepared statements are used to execute SQL queries in a more efficient and secure manner. They help avoid SQL injection and improve performance by reusing the query plan.

  **Example:**

  ```c
  sqlite3_stmt *stmt;
  const char *sql = "SELECT name, age FROM users WHERE id = ?";
  sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  // Bind an integer to the prepared statement
  sqlite3_bind_int(stmt, 1, 1); // Bind id = 1

  // Execute the statement
  int rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
      printf("Name: %s, Age: %d\n", sqlite3_column_text(stmt, 0), sqlite3_column_int(stmt, 1));
  }

  // Finalize the statement
  sqlite3_finalize(stmt);
  ```
