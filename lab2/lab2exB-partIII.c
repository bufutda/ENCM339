// ENCM 339 Fall 2015 Exercise B part III
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

int foo(int a0, int *a1);

int main(void)
{
  int i, j, k;
  i = 2000;
  j = 300;
  k = 20;
  
  // point one

  printf("In main before call to foo, values are %d, %d, %d.\n",
	 i, j, k);

  k = foo(i, &j);

  // point three

  printf("In main after call to foo, values are %d, %d, %d.\n",
	 i, j, k);

  return 0;
}

int foo(int a0, int *a1)
{
  *a1 += 5;
  a0 += 60; // Think: Does this or does it not affect i in main?

  // point two

  return a0 + 3;
}
