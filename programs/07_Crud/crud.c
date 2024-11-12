#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

int createTable(sqlite3 *db)
{
  const char *create_table_sql =
      "CREATE TABLE IF NOT EXISTS todos ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "task TEXT NOT NULL,"
      "status INTEGET DEFAULT 0"
      ");";

  char *err_msg = 0;
  int rc = sqlite3_exec(db, create_table_sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return SQLITE_OK;
}

int createTodo(sqlite3 *db, const char *task)
{
  const char *insert_sql = "INSERT INTO todos (task, status) VALUES (?, 0);";
  sqlite3_stmt *stmt;

  int rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, 0);

  if (rc != SQLITE_OK)
  {
    printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    return rc;
  }

  sqlite3_bind_text(stmt, 1, task, -1, SQLITE_STATIC);

  rc = sqlite3_step(stmt);

  if (rc != SQLITE_DONE)
  {
    printf("Execution failed: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return rc;
  }

  sqlite3_finalize(stmt);
  printf("TODO item added: %s\n", task);
  return SQLITE_OK;
}

int listTodos(sqlite3 *db)
{
  const char *select_sql = "SELECT id, task, status FROM todos;";
  sqlite3_stmt *stmt;

  int rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, 0);

  if (rc != SQLITE_OK)
  {
    printf("Failed to prepare statement %s\n", sqlite3_errmsg(db));
  }

  printf("ID | Task | Status\n");
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    const char *task = (const char *)sqlite3_column_text(stmt, 1);
    int status = sqlite3_column_int(stmt, 2);

    printf("%d | %s | %s\n", id, task, status == 0 ? "Not Completed" : "Completed");
  }

  if (rc != SQLITE_DONE)
  {
    printf("Execution failed: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  return SQLITE_OK;
}

int deleteTodoItem(sqlite3 *db, int todoId)
{
  const char *delete_sql = "DELETE FROM todos WHERE id = ?;";
  sqlite3_stmt *stmt;

  int rc = sqlite3_prepare_v2(db, delete_sql, -1, &stmt, 0);

  if (rc != SQLITE_OK)
  {
    printf("Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    return rc;
  }

  sqlite3_bind_int(stmt, 1, todoId);

  rc = sqlite3_step(stmt);

  if (rc != SQLITE_DONE)
  {
    printf("Execution failed: %s\n", sqlite3_errmsg(db));
    sqlite3_finalize(stmt);
    return rc;
  }

  sqlite3_finalize(stmt);
  printf("TODO item with ID %d deleted successfully.\n", todoId);
  return SQLITE_OK;
}

int main(int argc, char *argv[])
{
  sqlite3 *db;
  int rc = sqlite3_open("todos.db", &db);

  if (rc)
  {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
  }

  // Create table if not exists

  rc = createTable(db);
  if (rc != SQLITE_OK)
    return rc;

  int choice;
  char task[256];
  int id, status;

  while (1)
  {
    printf("\nTODO Application\n");
    printf("1. Add TODO item\n");
    printf("2. List TODO items\n");
    printf("3. Update TODO item\n");
    printf("4. Delete TODO item\n");
    printf("5. Exit\n");
    printf("Enter you choise: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter TODO task: ");
      getchar();
      fgets(task, sizeof(task), stdin);
      task[strcspn(task, "\n")] = '\0';
      printf("%s", task);
      createTodo(db, task);
      break;
    case 2:
      listTodos(db);
      break;
    case 4:
      printf("Enter TODO ID to delete: ");
      scanf("%d", &id);
      deleteTodoItem(db, id);
      break;
    case 5:
      sqlite3_close(db);
      printf("Existing progran.\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
}
