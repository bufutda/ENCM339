/*
 *  avg1.c
 *  
 *  Author:  Steve Norman
 */

#include <stdio.h>

int main(void)
{
  int num_read;
  int sum = 0;
  int count = 0;

  printf("This program computes the average of a list of integers.\n\n");

  printf("Please enter the first integer in the list:\n");
  while (scanf("%d", &num_read) != EOF) {
    count++;
    sum += num_read;
    printf("Enter the next integer,");
    printf(" or type Ctrl+D to mark the end of the list:\n");
  }

  if (count > 0) {
    printf("\nThe list had %d integers.\n", count);
    printf("The average value was %g.\n", (double) sum / count);
  }
  else
    printf("\nNo numbers in list -- can't compute an average.\n");

  return 0;
}
