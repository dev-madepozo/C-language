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

void displayTopBorder()
{
  printf("\033[1;36m");
  printf("\n%s\n", "╔═════════════════════════════╗");
}

void displayRightBorder() {
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

void displayWeekHeader() {
  displayLeftBorder(true);
  printf("\033[1;31mSun");
  printf("\033[1;36m");
  printf(" Mon Tue Wed Thu Fri Sat");
  displayRightBorder();
  printf("\n");
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
  displayBottomBorder();
}

int main(int argc, char *argv[])
{
  displayCalendar();
  return 0;
}
