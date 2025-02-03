# Sqlite3 in C

SQLite3 is a C-language library that implements a small, fast, self-contained, high-reliability, full-featured SQL database engine. It is widely used due to its simplicity and ease of integration with C programs.

## Table of Contents

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