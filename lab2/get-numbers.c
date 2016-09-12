// get-numbers.c
//
// Author: Steve Norman

#include <stdio.h>
#include <stdlib.h>

int get_int_or_die(void);
// REQUIRES:
//    User has been prompted to enter an int.
// PROMISES:
//    Function tries to read an int using scanf and "%d"
//    On success, that int is echoed to the user,
//    and the int is the function return value.
//    On failure, and error message is printed and
//    exit is called with an argument of 1.

double get_double_or_die(void);
// Like get_int_or_die, but tries to read a double using "%lf".

int main(void)
{
  int i;
  double j;
  printf("Testing get_int_or_die.  Please enter a line of text ...\n");
  i = get_int_or_die();
  printf("get int_or_die returned a value of %d.\n", i);
  printf("Testing get_double_or_die. Please enter a line of text ...\n");
  j = get_double_or_die();
  printf("get_double_or_die returned a value of %lf.\n", j);

  return 0;
}

int get_int_or_die(void)
{
  int result;
  if (1 != scanf("%d", &result)) {
    printf("I could not read an int. I am quitting.\n");
    exit(1);
  }
  printf("I read an int value of %d.\n", result);
  return result;
}
double get_double_or_die(void)
{
    double result;
    if (1 != scanf("%lf", &result)) {
        printf("I could not read a double. I am quitting.\n");
        exit(1);
    }
    printf("I read a double value of %lf.\n", result);
    return result;
}
