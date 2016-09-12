// ENCM 369 Fall 2015 Lab 1 Exercise B

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int j, k, input_count;
  printf("Please enter two integers, separated by a space:\n");
  input_count = scanf("%d %d", &j, &k);

  // If scanf didn't get two values, quit the program.
  if (input_count != 2) {
    printf("Sorry, that input was not valid.  I'm quitting!\n");
    exit(1);
  }

  // Echo the input.
  printf("The values read were %d for j and %d for k.\n", j, k);

  // Add code below this comment to complete the exercise ...

  if (j < 0 && k < 0)
      printf("Both j and k were negative.");
  else if (j < 0 && k >= 0)
      printf("j is negative but k is not.");
  else if (j >= 0 && k < 0)
      printf("k is negative but j is not.");
  else
      printf("Neither j nor k is negative.");

  return 0;
}
