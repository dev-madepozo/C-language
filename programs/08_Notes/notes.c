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

int main(int argc, char *argv[])
{
  return 0;
}
