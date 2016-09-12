// ENCM 339 Fall 2015 Lab 1 Exercise C

#include <stdio.h>

int is_leap_in_GB(int year);
// Returns 1 if year is leap in Britain, and 0 otherwise.
// (Return value doesn't necessarily sense if year is earlier than
// the adoption of AD year numbering in Britain!)

void call_is_leap(int year);
// Prints year embedded in a message about whether year was leap in Britain.

int main(void)
{
  call_is_leap(1700);
  call_is_leap(1701);
  call_is_leap(1704);
  call_is_leap(1800);
  call_is_leap(1812);
  call_is_leap(1815);
  call_is_leap(2000);
  call_is_leap(2015);
  call_is_leap(2016);
  call_is_leap(2100);
  call_is_leap(2102);
  call_is_leap(2196);

  return 0;
}

int is_leap_in_GB(int year)
{
  if ((!(year%4)&&year%100)||!(year%400))
    return 1;
  else
    return 0;
}

void call_is_leap(int year)
{
  printf("The year %d was, is, or will be ", year);
  if (!is_leap_in_GB(year))
    printf("non-");
  printf("leap in Britain.\n");
}
