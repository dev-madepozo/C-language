#include <stdio.h>

void pole(int n)
{
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j <= n; j++) {
      printf(" ");
    }
    printf("\033[1;32m* * * *\n");
  }
}

void triangle(int n, int initial) {
  for (int i = initial; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }

    for (int k = 0; k <= i; k++) {
      if (k > 0 && k < i && k % 2 == 1 &&  i % 3 == 0) {
        printf("\033[1;31m🔴");
      } else {
        printf("\033[1;32m* ");
      }
      printf("\033[0m");
    }
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  triangle(12, 0);
  triangle(12, 4);
  pole(8);
  return 0;
}
