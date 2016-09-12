// macro5A.c
// ENCM 339 Fall 2015 Lab 5 Exercise A

#include <stdio.h>

// This macro is *supposed* to provide a 3-input logical OR function.
// The result is *supposed* to be 1 if the values of one or more of
// x, y, and z are true.
#define OR3(x, y, z) (x) || (y) || (z)

int main(void)
{
  printf("test 1 result: %d (expect 0)\n", OR3(0, 0, 0));  
  printf("test 2 result: %d (expect 1)\n", OR3(0, 0, 1));
  printf("test 3 result: %d (expect 1)\n", OR3(0, 1, 1));  
  printf("test 4 result: %d (expect 1)\n", OR3(1, 1, 1));
  printf("test 5 result: %d (expect 0)\n", OR3(1, 1, 1) && 0);
  printf("test 6 result: %d (expect 1)\n", 1 && OR3(0, 0, 1));
  printf("test 7 result: %d (expect 0)\n", !OR3(0, 1, 1));
  return 0;
}
