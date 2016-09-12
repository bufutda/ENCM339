/*
 *  use-scanf.c
 *
 *
 *  This program lets you examine the behaviour of simple scanf calls
 *  in response to input errors.
 *
 *   Author:  S. Norman
 */

#include <stdio.h>

int main(void)
{
  int i = 333;
  double d = 1234.5;
  int scan_count;

  printf("Please enter an integer: \n");
  scan_count = scanf("%d", &i);
  printf("scan_count is %d and i is %d\n", scan_count, i);

  printf("Please enter a double: \n");
  scan_count = scanf("%lf", &d);
  printf("scan_count is %d and d is %f\n",  scan_count, d);

  return 0;
}
