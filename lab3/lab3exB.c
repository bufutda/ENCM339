// ENCM 339 Fall 2015 Lab 3 Exercise B

#include <stdio.h>

double average(const int *a, int size_a);
// REQUIRES
//   size_a > 0.
//   Elements a[0], a[1], ..., a[size_a - 1] exist.
// PROMISES
//   Return value is average of a[0], a[1], ... a[size_a - 1].

void select_negatives(const int *source, int n_source,
                      int *dest, int *n_dest);
// REQUIRES
//   n_source >= 0.
//   Elements source[0], source[1], ..., source[n_source-1] exist.
//   Elements dest[0], dest[1], ..., dest[n_source-1] exist.
// PROMISES
//   *n_dest == number of negative values in source[0], ..., source[n_source-1].
//   dest[0], ..., dest[*n_dest-1] contain those negative values, in
//   the same order as in the source array.

int main(void)
{
  int a[] = { -10, 9, -17, 0, -15 };
  int size_a;
  int i;
  double avg;
  int negative[5];
  int n_negative;

  size_a = sizeof(a) / sizeof(a[0]);
  
  printf("a has %d elements:", size_a);
  for (i = 0; i < size_a; i++)
    printf("  %d", a[i]);
  printf("\n");

  avg = average(a, size_a);
  printf("\naverage element value: %g\n", avg);
  
  select_negatives(a, size_a, negative, &n_negative);
  printf("\nnegative elements from a:");
  for (i = 0; i < n_negative; i++)
    printf("  %d", negative[i]);
  printf("\n");

  return 0;
}

double average(const int *a, int size_a)
{
  double sum = 0.0;
  int i;

  for (i = 0; i < size_a; i++)
    sum += a[i];

  // point one  (NOTE: This is *outside* of the for loop.)

  return sum / size_a;
}

void select_negatives(const int *source, int n_source,
                      int *dest, int *n_dest)
{
  int i;

  *n_dest = 0;
  for (i = 0; i < n_source; i++)
    if (source[i] < 0) {
      dest[*n_dest] = source[i];
      (*n_dest)++;
    }

  // point two  (NOTE: This is *outside* of the for loop.)

  return;
}
