// ENCM 339 Fall 2015 Lab 3 Exercise A

// IMPORTANT REMARK
//
//   For the most part in ENCM 339 we'll avoid using array syntax
//   to declare function parameters, because doing so is misleading
//   about types.  In other words, this is preferred ...
//
//       void foo(int *a, int n);
//
//   ... and this is not recommended ...
//
//       void foo(int a[], int n);
//
//   But in this exercise we'll use array syntax, just to emphasize
//   the fact that with a function parameter, asking for an array
//   type gets you a pointer type.

#include <stdio.h>

void bad_copy(double dest[], double src[]);

void good_copy(double dest[], const double src[], size_t n);

double bad_sum_array(const double arg[4]);

int main(void)
{
  double alice[ ] = { 1.5, -2.5, 3.5, -4.5 };
  double bob[4];
  double sum_bob;

  // printf("%lf %lf %lf %lf %zu\n%p %p\n", bob[0], bob[1], bob[2], bob[3], sizeof(bob[0]), &alice[0], &bob[0]);

  printf("The number of elements in the array alice is %zu.\n",
	 sizeof(alice) / sizeof(double));

  // point one

  bad_copy(bob, alice);
  // printf("%lf %lf %lf %lf\n", bob[0], bob[1], bob[2], bob[3]);
  good_copy(bob, alice, 4);
  printf("%lf %lf %lf %lf %zu\n%p %p\n", bob[0], bob[1], bob[2], bob[3], sizeof(bob[0]), &alice[0], &bob[0]);

  sum_bob = bad_sum_array(bob);
  printf("This program thinks that the sum of the "
	 "elements in bob is %f.\n", sum_bob);
  return 0;
}

void bad_copy(double dest[], double src[])
{
  // If you don't know C well, you might think this
  // function copies an array.  IT DOES NOT!
  printf("src: %lf (%p)\tdest: %lf (%p)\n", *src, src, *dest, dest);
  dest = src;
  printf("src: %lf (%p)\tdest: %lf (%p)\n", *src, src, *dest, dest);
  // point two

  return;
}

void good_copy(double dest[], const double src[], size_t n)
{
  size_t i;
  for (i = 0; i < n; i++)
    dest[i] = src[i];

  printf("%zu\n",i);
  // point three

  return;
}

double bad_sum_array(const double arg[4])
{
  // ATTENTION: Putting 4 between the square brackets beside
  // arg does *nothing* to change the type of arg--the type of
  // arg is pointer-to-const-double.  This style is even worse
  // than declaring a function parameter with empty square brackets!

  size_t element_count, i;
  double sum = 0.0;

  // DEFECTIVE attempt to find the number of array elements ...
  element_count = sizeof(arg) / sizeof(double);

  for (i = 0; i < element_count; i++)
    sum += arg[i];

  // point four
  printf("%zu %zu %lf\n", element_count, i, sum);
  return sum;
}
