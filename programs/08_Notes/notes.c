#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>

#define MAX_TEXT_LENGTH 140

typedef struct
{
  int id;
  char text[MAX_TEXT_LENGTH + 1];
  char created_at[20];
  char updated_at[20];
} Note;

int open_db(sqlite3 **db, char *db_name)
{
  int rc = sqlite3_open(db_name, db);
  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(*db));
    return rc;
  }

  return rc;
}

int create_table(sqlite3 *db)
{
  const char *sql = "CREATE TABLE IF NOT EXISTS notes ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "text TEXT NOT NULL CHECK (length(text) <= 140),"
                    "created_at TEXT NOT NULL,"
                    "updated_at TEXT NOT NULL);";
  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return 0;
}

int main(int argc, char *argv[])
{
  sqlite3 *db;
  int rc = open_db(&db, "notes.db");

  if (rc != SQLITE_OK)
  {
    return 1;
  }

  rc = create_table(db);

  if (rc != SQLITE_OK)
  {
    return 1;
  }

  return 0;
}
