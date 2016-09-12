// main5D.c
// ENCM 339 Fall 2015 Lab 5 Exercise D

// A small program to do quick checks of the functions
// in the threeVec module.

#include <stdio.h>
#include "threeVec.h"

void print_3v(const threeVec_t *pv, int with_newline)
{
  printf("[%g, %g, %g]", pv->x, pv->y, pv->z);
  if (with_newline)
    fputc('\n', stdout);
}

int main(void)
{
  threeVec_t a = { 1.0, 2.0, 4.0 }, b = { 1.25, -0.5, 0.375 };
  threeVec_t c;

  // A quick check of add_3v ...
  c = add_3v(a, b);
  printf("Sum of ");
  print_3v(&a, 0);
  printf(" and ");
  print_3v(&b, 0);
  printf(" is  ");
  print_3v(&c, 1);


  // A quick check of scalar_mult ...
  // (Call function to multiply -0.5 times a, putting the result in c,
  // and print a message showing the result.)
  scalar_mult(-0.5, &a, &c);
  printf("Scalar mult of %lf and ", -0.5);
  print_3v(&a, 0);
  printf(" is ");
  print_3v(&c, 1);


  // A quick check of dot_product ...
  // (Call function to find dot product of a and b, putting the result
  // in a variable of type double, and print a message showing the
  // result.)
  double d = dot_product(&a, &b);
  printf("Dot product of ");
  print_3v(&a, 0);
  printf(" and ");
  print_3v(&b, 0);
  printf(" is  ");
  printf("%lf\n", d);

  // A quick check of cross_product ...
  // (Call function to find cross product of a and b, putting the
  // result in c, and print a message showing the result.)
  c = cross_product(&a, &b);
  printf("Cross Product of ");
  print_3v(&a, 0);
  printf(" and ");
  print_3v(&b, 0);
  printf(" is  ");
  print_3v(&c, 1);

  // Set up an array of vectors, and display its contents.
  threeVec_t my_arr[ ] = {
     { 1.0, 2.0, 3.0 },
     { 0.1, 0.2, 0.3 },
     { 0.01, 0.02, 0.03 },
     { 0.001, 0.002, 0.003 },
   };
  size_t my_arr_count = sizeof(my_arr) / sizeof(threeVec_t);
  printf("\nAn array of %zu 3-vectors ...\n", my_arr_count);
  size_t i;
  for (i = 0; i < my_arr_count; i++) {
    printf("  ");
    print_3v(&my_arr[i], 1);
  }


  // A quick check of array_sum ...
  // (Call function to find sum of vectors in my_arr, putting the
  // result in c, and print a message showing the result.)
  array_sum(my_arr, my_arr_count, &c);
  printf("The vector sum of the vectors in my_arr is ");
  print_3v(&c, 1);

  // Second check of array_sum ... make sure it does the correct
  // thing when the parameter n == 0.
  array_sum(my_arr, 0, &c);
  printf("The vector sum of a 0-length array is ");
  print_3v(&c, 1);


  return 0;
}
