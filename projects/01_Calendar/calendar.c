#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

const int MAX_WIDTH = 28;
const char BORDER[] = "║";
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
  printf("\033[1;36m %s", BORDER);
}

void displayBottomBorder()
{
  printf("\033[1;36m");
  printf("\n%s\n", "╚═════════════════════════════╝");
}

void displayLeftBorder(bool hasSpace)
{
  printf("\033[1;36m%s", BORDER);
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

void displayDays(int day, int month, int year)
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
}

void displayCalendar()
{
  struct tm currentDate = getCurrentDate();
  int day = currentDate.tm_mday;
  int month = currentDate.tm_mon;
  int year = currentDate.tm_year + 1900;
  displayTopBorder();
  displayMonthAndYearHeader(month, year);
  displayInnerBorder();
  displayWeekHeader();
  displayDays(day, month, year);
  displayBottomBorder();
}

int main(int argc, char *argv[])
{
  displayCalendar();
  return 0;
}
