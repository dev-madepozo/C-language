#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[30];
  int year;
  char difficulty[10];
  int ranking;
} Framework;

char tableHeaders[4][15] = {"Framework", "Year", "Difficulty", "Ranking"};
const char *padding = "                              ";

void displayBorder(int columnsWidth[4])
{
  printf("+");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < columnsWidth[i] + 2; j++)
    {
      printf("-");
    }
    printf("+");
  }
  printf("\n");
}

void displayHeader(int columnsWidth[4])
{
  displayBorder(columnsWidth);
  for (int x = 0; x < 4; x++)
  {
    printf("| %s", tableHeaders[x]);
    if (columnsWidth[x] > strlen(tableHeaders[x]))
    {
      for (int y = 0; y < columnsWidth[x] - strlen(tableHeaders[x]); y++)
      {
        printf(" ");
      }
    }
    printf(" ");
  }
  printf("| \n");
  displayBorder(columnsWidth);
}

void displayBody(Framework *frameworks, size_t length, int columnsWidth[4])
{
  for (int i = 0; i < length; i++)
  {
    int col1Padding = columnsWidth[0] - strlen(frameworks[i].name);
    int col3Padding = columnsWidth[2] - strlen(frameworks[i].difficulty);
    printf("| %s%*.*s ", frameworks[i].name, col1Padding, col1Padding, padding);
    printf("| %d ", frameworks[i].year);
    printf("| %s%*.*s ", frameworks[i].difficulty, col3Padding, col3Padding, padding);
    printf("| %-*d ", columnsWidth[3], frameworks[i].ranking);
    printf("|\n");
  }
  displayBorder(columnsWidth);
}

void createTable(Framework *frameworks, size_t length)
{
  int nameColumnWidth = 0;
  int yearColumnWidth = 4;
  int difficultyColumnWidth = 10;
  int rankingColumnWidth = 7;

  for (int i = 0; i < length; i++)
  {
    int nameLength = strlen(frameworks[i].name);
    int difficultyLength = strlen(frameworks[i].difficulty);
    nameColumnWidth = nameLength > nameColumnWidth ? nameLength : nameColumnWidth;
    difficultyColumnWidth = difficultyLength > difficultyColumnWidth ? difficultyLength : difficultyColumnWidth;
  }

  int columnsWidth[4] = {nameColumnWidth, yearColumnWidth, difficultyColumnWidth, rankingColumnWidth};

  displayHeader(columnsWidth);
  displayBody(frameworks, length, columnsWidth);
  printf("%zu rows in set (0.00 sec)\n", length);
}

int main(int argc, char *argv[])
{
  Framework frameworks[10] = {
      {"React", 2013, "Moderate", 1},
      {"Angular", 2010, "Moderate", 2},
      {"Vue", 2014, "Easy", 3},
      {"Ember", 2011, "Moderate", 4},
      {"Svelte", 2016, "Easy", 5},
      {"NextJS", 2016, "Moderate", 6},
      {"NuxtJS", 2016, "Moderate", 7},
      {"BackboneJS", 2010, "Moderate", 8},
      {"jQuery", 2006, "Easy", 9},
      {"D3", 2011, "Moderate", 10},
  };

  size_t length = sizeof(frameworks) / sizeof(frameworks[0]);
  createTable(frameworks, length);

  return 0;
}
