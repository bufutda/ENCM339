// findmax10C.cpp
// ENCM 369 Fall 2015 Lab 10 Exercise C

#include <iostream>
#include <cassert>

double find_max(const double *a, int lo, int hi);
// REQUIRES:
//   lo < hi. Array elements a[lo] ... a[hi-1] exist.
// PROMISES:
//   Return value is largest element value from a[lo] ... a[hi-1].

int main()
{
  double x[ ] = { 0.5, 3.5, -1.0, 7.5, 2.5, 6.0, 4.5 };
  double max;
  max = find_max(x, 0, 7);
  std::cout << "Largest element is " << max << '.' << std::endl;
  return 0;
}

double find_max(const double *a, int lo, int hi)
{
  double result, left, right;
  int mid;

  // point one

  assert(lo < hi);
  if (lo + 1 == hi)  // Base case: only one element.
    result = a[lo];
  else {
    mid = (lo + hi) / 2;
    left = find_max(a, lo, mid);
    right = find_max(a, mid, hi);
    result = (left > right) ? left : right;
  }
  return result;
}
