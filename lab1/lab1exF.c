// ENCM 369 Fall 2015 Lab 1 Exercise F

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int max;
  int scan_count;
  int column;
  int row;

  printf("How many rows would you like in your times table?\n");
  printf("Enter a number between 1 and 15.\n");
  scan_count = scanf("%d", &max);

  // If scanf couldn't read an int at all, print an error message and quit.
  if (scan_count == 0)
  {
      printf("Error: Invalid Input");
      exit(1);
  }

  // If scanf got an out-of-range number, print the number within
  // an error message and quit.
  if ((1 >= max) || (max >= 15))
  {
      printf("Error: %d is out of range!", max);
      exit(1);
  }


  printf("Here is your table ...\n\n");

  // Print the header row of the table.
  // Note that %4d prints an int using a *minimum* of 4 characters,
  // which will help to get input lined up in columns.
  printf("   X");
  for (column = 1; column <= max; column++)
    printf("%4d", column);
  printf("\n");

  // Print all the other rows of the table, using a nested loop.
  for (row = 1; row <= max; row++)
  {
    printf("   %d", row);
    for (column = 1; column <= max; column++)
      printf("%4d", row * column);
    printf("\n");
  }

  return 0;
}
