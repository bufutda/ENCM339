//  ENCM 339 Fall 2015 Lab 1 Exercise D

#include <stdio.h>

int the_function(int k);

int main(void)
{
  printf("the_function(5) returns %d.\n", the_function(5));
  printf("the_function(15) returns %d.\n", the_function(15));
  printf("the_function(25) returns %d.\n", the_function(25));
  return 0;
}

int the_function(int k)
{
  if (k > 10)
    return 1;
  if (k > 20)
    return 2;
  return 3;
}
