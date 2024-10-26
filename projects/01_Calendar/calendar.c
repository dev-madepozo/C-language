#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int MAX_WIDTH = 28;
char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"};

struct tm getCurrentDate()
{
  time_t currentTime = time(NULL);
  struct tm currentDate = *localtime(&currentTime);
  return currentDate;
}

int getNumberOfDays(int month, int year)
{
  switch (month)
  {
  case 0:
  case 2:
  case 4:
  case 6:
  case 7:
  case 9:
  case 11:
    return 31;
  case 3:
  case 5:
  case 8:
  case 10:
    return 30;
  default:
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 29 : 28;
  }
}

int getFirstDayNumber(int day, int month, int year)
{
  static int t[] = {0, 3, 2, 5, 0, 3,
                    5, 1, 4, 6, 2, 4};
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + t[month] + day) % 7;
}

void displayTopBorder()
{
  printf("\033[1;36m");
  printf("\n%s\n", "╔═════════════════════════════╗");
}

void displayRightBorder()
{
  printf("\033[1;36m %s", "║");
}

void displayBottomBorder()
{
  printf("\033[1;36m");
  printf("\n%s\n", "╚═════════════════════════════╝");
}

void displayLeftBorder(bool hasSpace)
{
  printf("\033[1;36m%s", "║");
  if (hasSpace)
  {
    printf(" ");
  }
}

void displayInnerBorder()
{
  printf("\033[1;36m");
  printf("\n%s\n", "╠═════════════════════════════╣");
}

void displayMonthAndYearHeader(int monthNumber, int year)
{
  char *monthName = months[monthNumber];
  int length = strlen(monthName);
  int totalSpaces = MAX_WIDTH - length - 1;
  displayLeftBorder(true);
  printf("%s%*d", monthName, totalSpaces, year);
  displayRightBorder();
}

void displayWeekHeader()
{
  displayLeftBorder(true);
  printf("\033[1;31mSun");
  printf("\033[1;36m");
  printf(" Mon Tue Wed Thu Fri Sat");
  displayRightBorder();
  printf("\n");
}

void displayDays(int month, int year)
{
  int firstDayNumber = getFirstDayNumber(1, month, year);
  int col;
  int rows = 1;

  displayLeftBorder(false);

  for (col = 0; col < firstDayNumber; col++)
  {
    printf("    ");
  }

  int numberOfDays = getNumberOfDays(month, year);

  for (int y = 1; y <= numberOfDays; y++)
  {
    if (col == 0)
    {
      printf("\033[1;31m%4d", y);
    }
    else
    {
      printf("\033[1;36m%4d", y);
    }

    if (++col > 6)
    {
      col = 0;
      rows++;
      displayRightBorder();
      printf("\n");
      displayLeftBorder(false);
    }
  }

  if (col <= 6)
  {
    while (col++ <= 6)
    {
      printf("    ");
    }
    displayRightBorder();
  }

  if (rows < 6)
  {
    printf("\n║                             ║");
  }
}

void displayCalendar(int month, int year)
{
  displayTopBorder();
  displayMonthAndYearHeader(month, year);
  displayInnerBorder();
  displayWeekHeader();
  displayDays(month, year);
  displayBottomBorder();
}

void displayMenu()
{
  printf("\nP => Previous | T => Today | N => Next | Q => To Close\nPress: ");
}

int main(int argc, char *argv[])
{
  struct tm currentDate = getCurrentDate();

  int current_day = currentDate.tm_mday;
  int current_month = currentDate.tm_mon;
  int current_year = currentDate.tm_year + 1900;
  int month = current_month;
  int year = current_year;
  char option;

  displayCalendar(month, year);
  displayMenu();
  scanf("%c", &option);

  while (true)
  {
    if (option >= 'A' && option <= 'Z')
    {
      option += 32;
    }

    if (option == 'q')
    {
      break;
    }
    else if (option == 'p')
    {
      if (--month < 0)
      {
        month = 11;
        year--;
      }
    }
    else if (option == 'n')
    {
      if (++month > 11)
      {
        month = 0;
        year++;
      }
    }
    else if (option == 't')
    {
      month = current_month;
      year = current_year;
    }

    displayCalendar(month, year);
    displayMenu();
    scanf("%c", &option);
    system("clear");
  }

  return 0;
}
