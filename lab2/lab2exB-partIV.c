// ENCM 339 Fall 2015 Exercise B part IV
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

void run(int c, int *d);
void fly(int *a, int *b);

int main(void)
{
  int i = 200, j = 300;
  int *p;
  p = &j;
  fly(p, &i);
  printf("i, j values: %d, %d.\n", i, j);

  return 0;
}

void run(int c, int *d)
{
  // Hint: d must point to an int variable. In other words,
  // d contains the address of an int variable.

  // point one

  *d = c + 5;

  // point two

  return;
}

void fly(int *a, int *b)
{
  *a += 40;
  *b += 50;
  
  // Note: The next call passes the value of the int pointed by a 
  // but passes the address in b on to swim.
  run(*a, b);
}

