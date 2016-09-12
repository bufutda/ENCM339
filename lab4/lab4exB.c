// ENCM 339 Fall 2015 Lab 4 Exercise B

#include <stdio.h>

int main(void)
{
  int i;
  int y[ ] = { 100, 200, 300, 400, 500 };
  int *z;
    
  *y = 99;
  *(y + 2) = 55;
  y[1] = 11;
    
  z = y + 1;
    
  i = 2;
  printf("*(z + %d) + 1 is %d\n", i, *(z + i) + 1);
  printf("*(z - 1) + %d is %d\n", i, *(z - 1) + i);
  printf("*(&y[2] + %d) is %d\n", i, *(&y[2] + i) );
    
  // REMARK: The type produced by subtracting one pointer
  // from another is called prtdiff_t, which mighht not be the
  // same as int. The cast with (int) ensures that printf
  // gets an int it can print using %d.
  printf("z - y is %d\n", (int) (z - y));

  z--;
  printf("*z is %d\n", *z);
  printf("z - &y[2] is %d\n", (int) (z - &y[2]));
    
  return 0;
}
