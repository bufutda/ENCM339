// ENCM 369 Fall 2015 Lab 1 Exercise C

#include <stdio.h>

int alpha(int a);
int beta(int b);
int delta(int d1, int d2);

int main(void)
{
  int mx = 5, my = 42, mz = 10;
  mz = mz + delta(my + 3, mx + 1);
  printf("mz has a value of %d\n", mz);
  return 0;
}

int alpha(int a)
{
  int r;
  r = a * 10;

  // point one

  return r;
}

int beta(int b)
{
  int s;
  s = b % 8;

  // point two

  return s;
}

int delta(int d1, int d2)
{
  int v1, v2;
  v1 = alpha(d2);
  v2 = beta(d1);
  return v1 + v2;
}
