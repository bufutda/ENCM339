// ptr2ptr2.c
// ENCM 339 Fall 2015 Lab 9 Exercise B, Part 1


#include <stdio.h>
#include <stdlib.h>

int glob[3] = { 0, 42 };

void foo(int **z, int n)
{
  int i;
  for (i = 0; i < n; i++)
    z[i][0] = 10 * (i + 1);
  z[1][2] = 22;
  (*z)[2] = 33;
  *z[2] = 44;
  *(*(z + 2) + 3) = 55;

  // point one
}

int main(void)
{
  int loc[4];
  int *x = malloc(5 * sizeof(*x));
  int *y[3];
  y[0] = glob;
  y[1] = loc;
  y[2] = x;
  foo(y, 3);
  return 0;
}
