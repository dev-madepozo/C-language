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

struct tm getCurrentTime()
{
  time_t currentTime = time(NULL);
  return *localtime(&currentTime);
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
  year -= month < 2;
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
  int totalSpaces = MAX_WIDTH - length - 5;
  displayLeftBorder(true);
  printf("< %s >%*d", monthName, totalSpaces, year);
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

bool isCurrentDate(int currentDate[], int day, int month, int year)
{
  return day == currentDate[0] && month == currentDate[1] && year == currentDate[2];
}

void displayDays(int month, int year, int currentDate[])
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

  for (int i = 1; i <= numberOfDays; i++)
  {
    if (isCurrentDate(currentDate, i, month, year))
    {
      printf("\033[1;33m%4d", i);
    }
    else if (col == 0)
    {
      printf("\033[1;31m%4d", i);
    }
    else
    {
      printf("\033[1;36m%4d", i);
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

void displayCalendar(int currentDate[], int month, int year)
{
  displayTopBorder();
  displayMonthAndYearHeader(month, year);
  displayInnerBorder();
  displayWeekHeader();
  displayDays(month, year, currentDate);
  displayBottomBorder();
}

void displayMenu()
{
  printf("\nP => Previous | T => Today | N => Next | Q => To Close\nPress: ");
}

int main(int argc, char *argv[])
{
  struct tm currentTime = getCurrentTime();

  int current_day = currentTime.tm_mday;
  int current_month = currentTime.tm_mon;
  int current_year = currentTime.tm_year + 1900;
  int month = current_month;
  int year = current_year;
  char option;
  int currentDate[] = {current_day, current_month, current_year};

  displayCalendar(currentDate, month, year);
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

    displayCalendar(currentDate, month, year);
    displayMenu();
    scanf("%c", &option);
    system("clear");
  }

  return 0;
}
