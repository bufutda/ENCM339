// ENCM 339 Fall 2015 Exercise B part I
// An exercise to help you understand the use of pointer variables.
// Author: Steve Norman

#include <stdio.h>

int main(void)
{
  int red = 55;
  int orange = 66;
  int *yellow;
  int *green;

  yellow = &red;

  // point one

  printf("point one: value of red is %d; value of orange is %d.\n",
         red, orange);

  green = &orange;
  *yellow += 3;
  *green += 1;

  // point two

  printf("point two: value of red is %d; value of orange is %d.\n",
         red, orange);

  yellow = &orange;
  *yellow += 100;

  // point three

  printf("point three: value of red is %d; value of orange is %d.\n",
         red, orange);
  printf("point three: value of *yellow is %d; value of *green is %d.\n",
         *yellow, *green);

  green = &red;
  *green = *yellow;

  // point four

  printf("point four: value of red is %d; value of orange is %d.\n",
         red, orange);

  green = yellow;
  *green += 2000;

  // point five

  printf("point five: value of red is %d; value of orange is %p.\n",
         red, &orange);
  printf("point five: value of *yellow is %p; value of *green is %d.\n",
         yellow, *green);

  return 0;
}
