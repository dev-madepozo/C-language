#include <stdio.h>

void displayBoard() {
  int board[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  };

  int positions[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf(" %d ", positions[i][j]);
      if (j < 2) {
        printf("│");
      }
    }

    printf("\t");

    for (int k = 0; k < 3; k++) {
      if (board[i][k] == 1) {
        printf("\033[0;31m X ");
      } else if (board[i][k] == 2) {
        printf("\033[0;34, O ");
      } else {
        printf("   ");
      }
      printf("\033[0m");

      if (k < 2) {
        printf("│");
      }
    }

    if (i < 2) {
      printf("\n───┼───┼───");
      printf("\t");
      printf("───┼───┼───\n");
    }
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  displayBoard();
  return 0;
}