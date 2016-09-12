// ENCM 339 Fall 2015 Lab 3 Exercise D

#include <stdio.h>

void display_array(const char* label, const double* x, size_t n);
// REQUIRES
//    label points to the beginning of a string.
//    Elements x[0], ... x[n-1] exist.
// PROMISES
//    label is printed, followed by values of  x[0], ... x[n], all on
//    one line, using %4.2f format for the doubles. If n == 0, the line
//    of output points out that fact.

void reverse(double* x, size_t n);
// REQUIRES
//     n > 0.
//     Array elements x[0] ... x[n - 1] exist.
// PROMISES
//     Order of elements x[0] ... x[n - 1] has been reversed.
//     (So the new x[0] value is the old x[n - 1] value, and so on.)

void append(double* dest, size_t cap, size_t dest_count,
	    const double* src, size_t src_count);
// Append a list of numbers in the src array to a list of
// numbers in the dest array, without overflowing the dest array.
// REQUIRES
//   cap > 0.  cap indicates the capacity of the dest array.
//   dest_count <= cap.  dest_count indicates how many elements
//   of the dest_array should be preserved.
//   Elements src[0] ... src[src_count-1] exist.
// PROMISES
//   Elements have been copied to the dest array, such that
//   dest[dest_count] == src[0], and so on, until either
//   all of src[0] ... src[src_count-1] have been copied or
//   dest[cap-1] has been updated, whichever happened first.

// In Step 3, add a function prototype and function interface comment
// for max_element here.
double max_element(const double* x, size_t n);
//REQUIRES
//    n > 0
//    Array elements x[0] ... x[n-1] exit.
//    Array elements are all of type double.
//PROMISES
//    Returns the value of the element in array x with the maximum
//    value.

int main(void)
{
  double test1[ ] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double test2[ ] = {-0.5, -1.0, -1.5, -2.0, -2.5, -3.0};

  printf("Some quick checks of display_array ...\n");
  display_array("  all of test1:", test1, 5);
  display_array("  none of test1:", test1, 0);
  display_array("  last 3 elements of test1:", &test1[2], 3);
  display_array("  all of test2:", test2, 6);

  printf("\nTwo tests of reverse ...\n");
  reverse(test1, 5);
  display_array("  test1 after reversing:", test1, 5);
  reverse(test2, 6);
  display_array("  test2 after reversing:", test2, 6);

  // In testing append, we'll give the destination arrays 11 elements,
  // then pretend that their capacities are only 10 elements.  That
  // way we can check to make sure that the value of element 10
  // hasn't been changed from the 0.0 it gets initialized to.
  printf("\nTwo tests of append ...\n");
  double test3[11] = {1.0, 2.0, 3.0, 4.0};
  double test3src[ ] = {5.0, 6.0, 7.0};
  append(test3, 10, 4, test3src, 3);
  display_array("  test3 after append:", test3, 11);
  double test4[11] = {1.1, 2.1, 3.1, 4.1, 5.1};
  double test4src[ ] = {6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1};
  append(test4, 10, 5, test4src, 7);
  display_array("  test4 after append:", test4, 11);

  // In Step 3, add some tests for max_element here.
  printf("\nFour tests of max_element ...\n");
  double test5[5] = {-6.9, -2.0, -3.0, -1.0, -4.0};
  display_array("  test5 src: ", test5, 5);
  printf("  test5 max: %lf\n", max_element(test5, 5));
  double test6[6] = {1.1, 2.2, 3.3, 5.5, 100.7, 8.0};
  display_array("  test6 src: ", test6, 6);
  printf("  test6 max: %lf\n", max_element(test6, 6));
  double test7[7] = {13.37, 4.2, -5.0, -6.0, 10.0, -10.0, 0.0};
  display_array("  test7 src: ", test7, 7);
  printf("  test7 max: %lf\n", max_element(test7, 7));
  double test8[8] = {13.37, 4.2, -5.0, -6.0, 10.0, -10.0, 0.0, 42.0};
  display_array("  test8 src: ", test8, 8);
  printf("  test8 max: %lf\n", max_element(test8, 8));

  return 0;
}

void display_array(const char* label, const double * x, size_t n)
{
  size_t i ;
  printf("%s", label);
  if (n == 0)
    printf("  [no contents to print]\n");
  else {
    for(i = 0; i < n ; i++)
      printf(" %4.2f", x[i] );
    printf("\n");
  }
}

void reverse(double* x, size_t n)
{
  int i;
  double swapValue;
  for (i = 0; i < n/2; i++) {
    swapValue = x[i];
	x[i] = x[n-1-i];
	x[n-1-i] = swapValue;
  }
  return;
}

void append(double* dest, size_t cap, size_t dest_count,
	      const double* src, size_t src_count)
{
  int i;
  for (i = 0; i + dest_count < cap && i < src_count; i++) {
    dest[dest_count + i] = src[i];
  }
  return;
}

// In Coding Step 3, add a function definition max_element here.
double max_element(const double* x, size_t n)
{
  double max = x[0];
  int i;
  for (i = 0; i < n; i++) {
    if (max < x[i])
      max = x[i];
  }
  return max;
}
