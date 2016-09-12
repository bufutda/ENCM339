/*
 *  avg2.c
 *  
 *  Author:  Steve Norman
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num_for_list;
  int sum = 0;
  int count = 0;
  int scan_count;

  printf("This program computes the average of a list of integers.\n\n");

  printf("Please enter the first integer in the list:\n");
  while (1) {
    scan_count = scanf("%d", &num_for_list);

    if (scan_count != 1)
      break;

    count++;
    sum += num_for_list;
    printf("Enter the next integer,");
    printf(" or type Ctrl+D to mark the end of the list:\n");
  }

  if (scan_count == 0) {
    printf("\nFailure to convert input to an int.  Program terminated.\n");
    exit(1);
  }

  if (count > 0) {
    printf("\nThe list had %d integers.\n", count);
    printf("The average value was %g.\n", (double) sum / count);
  }
  else
    printf("\nNo numbers in list -- can't compute an average.\n");

  return 0;
}
