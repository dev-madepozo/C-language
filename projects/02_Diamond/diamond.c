#include <stdio.h>
#include <stdlib.h>

int COLORS[] = {31, 32, 33, 34, 35, 36, 37};
size_t length = sizeof(COLORS) / sizeof(COLORS[0]);

int getRandomColor()
{
  int randomValue = rand() % length;
  return COLORS[randomValue];
}

void displayDiamond(int n)
{
  for (int i = 0; i < 2 * n - 1; i++)
  {
    int comp = i < n ? 2 * (n - i) - 1 : 2 * (i - n + 1) + 1;

    for (int j = 0; j < comp; j++)
    {
      printf(" ");
    }

    for (int k = 0; k < 2 * n - comp; k++)
    {
      int randomColor = getRandomColor();
      printf("\033[0;%dm%s", randomColor, "* ");
    }

    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  int n = 7;
  displayDiamond(n);
  return 0;
}
