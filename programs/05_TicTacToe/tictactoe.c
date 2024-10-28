#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

int positions[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

bool gameOver = false;

void displayBoard()
{
  printf("\n      Tic Tac Toe Game\n\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (positions[i][j] != -1)
      {
        printf(" %d ", positions[i][j]);
      }
      else
      {
        printf("   ");
      }

      if (j < 2)
      {
        printf("│");
      }
    }

    printf("\t");

    for (int k = 0; k < 3; k++)
    {
      if (board[i][k] == 1)
      {
        printf("\033[0;31m X ");
      }
      else if (board[i][k] == 2)
      {
        printf("\033[0;34m O ");
      }
      else
      {
        printf("   ");
      }
      printf("\033[0m");

      if (k < 2)
      {
        printf("│");
      }
    }

    if (i < 2)
    {
      printf("\n───┼───┼───");
      printf("\t");
      printf("───┼───┼───\n");
    }
  }

  printf("\n");
}

bool isValidMove(int move, char turn)
{
  if (move < 1 || move > 9)
  {
    return false;
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (positions[i][j] == move)
      {
        positions[i][j] = -1;
        board[i][j] = turn == 'X' ? 1 : 2;
        return true;
      }
    }
  }

  return false;
}

void checkWinner(char turn)
{
  int availableSpaces = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (positions[i][j] != -1)
      {
        availableSpaces++;
      }
    }
  }

  if (
      (board[0][0] != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
      (board[1][0] != 0 && board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
      (board[2][0] != 0 && board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
      (board[0][0] != 0 && board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
      (board[0][1] != 0 && board[0][1] == board[1][1] && board[1][1] == board[1][2]) ||
      (board[0][2] != 0 && board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
      (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
      (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]))
  {
    printf("%c WINS!\n", turn);
    gameOver = true;
    return;
  }

  if (availableSpaces == 0)
  {
    printf("\nGame over: DRAW!\n");
    gameOver = true;
  }
}

int main(int argc, char *argv[])
{
  char turn = 'X';
  int position;

  displayBoard();

  printf("\n%c is your turn: ", turn);
  scanf("%d", &position);

  while (1)
  {
    if (isValidMove(position, turn))
    {
      printf("\n");
      displayBoard();
      checkWinner(turn);
      turn = turn == 'X' ? 'O' : 'X';

      if (gameOver)
      {
        break;
      }
    }

    printf("\n%c is your turn: ", turn);
    scanf("%d", &position);
    system("clear");
  }

  return 0;
}
