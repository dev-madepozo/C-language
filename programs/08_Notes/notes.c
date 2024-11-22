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

void get_current_time(char *buffer)
{
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
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

  return SQLITE_OK;
}

int create_note(sqlite3 *db, Note *note)
{
  char sql[512];
  snprintf(
      sql,
      sizeof(sql),
      "INSERT INTO notes (text, created_at, updated_at) VALUES ('%s', '%s', '%s');",
      note->text, note->created_at, note->updated_at);
  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return SQLITE_OK;
}

static int display_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  printf("\033[0;32m");
  printf("{\n");
  for (int i = 0; i < argc; i++)
  {
    printf("    \"%s\": \"%s\",\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("},\n");
  printf("\033[0m");
  return 0;
}

int read_notes(sqlite3 *db)
{
  char *sql = "SELECT * FROM notes";
  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, display_callback, 0, &err_msg);

  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return SQLITE_OK;
}

int find_note_by_id(sqlite3 *db, int id)
{
  char sql[128];
  snprintf(sql, sizeof(sql), "SELECT * FROM notes WHERE id = %d", id);
  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, display_callback, 0, &err_msg);
  if (rc != SQLITE_OK)
  {
    return rc;
  }

  return SQLITE_OK;
}

int update_note(sqlite3 *db, int id, char *new_text)
{
  char sql[512];
  char updated_at[20];

  get_current_time(updated_at);
  snprintf(sql, sizeof(sql), "UPDATE notes SET text = '%s', updated_at = '%s' WHERE id = %d;", new_text, updated_at, id);

  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return SQLITE_OK;
}

int delete_note(sqlite3 *db, int id)
{
  char sql[128];
  snprintf(sql, sizeof(sql), "DELETE FROM notes WHERE id = %d", id);
  char *err_msg = 0;
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if (rc != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
    return rc;
  }

  return SQLITE_OK;
}

void display_menu()
{
  printf("┌─────────────────────────────┐\n");
  printf("│     Notes Application       │\n");
  printf("├─────────────────────────────┤\n");
  printf("│ 1. Add a new Note           │\n");
  printf("│ 2. List all Notes           │\n");
  printf("│ 3. Find a Note by id        │\n");
  printf("│ 4. Update a Note            │\n");
  printf("│ 5. Delete a Note            │\n");
  printf("│ 6. Exit                     │\n");
  printf("└─────────────────────────────┘\n");
  printf("Enter an option: ");
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

  int option;
  int id;
  char note_text[MAX_TEXT_LENGTH + 2];

  while (1)
  {
    display_menu();
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("Enter a Note text (max 140 characters):\n");
      getchar();
      fgets(note_text, sizeof(note_text), stdin);
      int length = strlen(note_text);

      if (length > MAX_TEXT_LENGTH && note_text[MAX_TEXT_LENGTH] != '\n')
      {
        printf("Note text exceeds 140 characters.\n");
      }
      else
      {
        if (note_text[length - 1] == '\n')
        {
          note_text[length - 1] = '\0';
        }

        Note note;
        strcpy(note.text, note_text);
        get_current_time(note.created_at);
        strcpy(note.updated_at, note.created_at);
        rc = create_note(db, &note);

        if (rc != SQLITE_OK)
        {
          return 1;
        }

        printf("\033[0;32m");
        printf("The Note was created successfully\n");
        printf("\033[0m");
      }

      break;
    case 2:
      printf("All Notes:\n");
      printf("----------------------------\n");
      read_notes(db);
      break;
    case 3:
      printf("Enter the Note id to find: ");
      scanf("%d", &id);
      rc = find_note_by_id(db, id);
      break;
    case 4:
      printf("Enter the Note id to update: ");
      scanf("%d", &id);
      printf("Enter a Note text (max 140 characters):\n");
      getchar();
      fgets(note_text, sizeof(note_text), stdin);
      length = strlen(note_text);

      if (length > MAX_TEXT_LENGTH && note_text[MAX_TEXT_LENGTH] != '\n')
      {
        printf("Note text exceeds 140 characters.\n");
      }
      else
      {
        if (note_text[length - 1] == '\n')
        {
          note_text[length - 1] = '\0';
        }

        rc = update_note(db, id, note_text);

        if (rc != SQLITE_OK)
        {
          return 1;
        }

        printf("\033[0;32m");
        printf("The Note was updated successfully\n");
        printf("\033[0m");
      }
      break;
    case 5:
      printf("Enter the Note id to delete: ");
      scanf("%d", &id);
      int rc = delete_note(db, id);

      if (rc != SQLITE_OK)
      {
        return 1;
      }

      printf("\033[0;32m");
      printf("The Note with ID = %d was deleted successfully\n", id);
      printf("\033[0m");
      break;
    case 6:
      sqlite3_close(db);
      printf("Exiting progran.\n");
      return 0;
    default:
      printf("Invalid option. Please try again.\n");
    }
  }

  return 0;
}
