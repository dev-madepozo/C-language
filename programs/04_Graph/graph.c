#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[30];
  float percentage;
} Language;

void displayGraph(Language *languages, size_t length)
{
  int width = 0;

  for (int i = 0; i < length; i++)
  {
    if (width < strlen(languages[i].name))
    {
      width = strlen(languages[i].name);
    }
  }

  for (int j = 0; j < length; j++)
  {
    char *name = languages[j].name;
    float percentage = languages[j].percentage;
    int rightPadding = width - strlen(name);

    printf("%*s", width + 1, "");
    printf("┌");
    for (int x = 0; x < percentage; x++)
    {
      printf("─");
    }
    printf("┐\n");
    printf("%s", languages[j].name);
    printf("%*s", (int)(width - strlen(name)), "");
    printf(" │");
    printf("%*s", (int)percentage, "");
    printf("│ %.2f%c\n", percentage, '%');
    printf("%*s", width + 1, "");
    printf("└");
    for (int x = 0; x < percentage; x++)
    {
      printf("─");
    }
    printf("┘\n");
  }
}

int main(int argc, char *argv[])
{
  Language languages[10] = {
      {"JavaScript", 20},
      {"Python", 15},
      {"Java", 10},
      {"C#", 8},
      {"C/C++", 7},
      {"Php", 6},
      {"TypeScript", 5},
      {"Ruby", 3},
      {"Switf", 3},
      {"Go", 3},
  };

  printf("\nMost demanded Programming Languages in 2024\n");
  printf("───────────────────────────────────────────\n\n");

  size_t length = sizeof(languages) / sizeof(languages[0]);
  displayGraph(languages, length);

  return 0;
}
