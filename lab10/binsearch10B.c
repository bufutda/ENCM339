// binsearch10B.c
// ENCM 339 Fall 2015 Lab 10 Exercise B

#include <stdio.h>
#include <assert.h>

int first_ge(const int *a, int lo, int hi, int key);
// REQUIRES: lo < hi
//    Array elements a[lo] .... a[hi-1] exist,
//    and are sorted from smallest to largest.
// PROMISES:
//    Return value is hi if all elements are < key.
//    Otherwise return value is the index of the
//    first element that is >= key.

int t1[] = { 10, 20, 30, 40, 50, 60, 70 };
int t2[] = { 0, 100, 100, 100, 140, 175, 200, 200 };

int main(void)
{
  int i, k;
  
  k = 30;
  i = first_ge(t1, 0, 7, k);
  printf("\nIndex of first element >= %d in t1 is %d.\n", k, i);
  printf("The value of that element is %d.\n", t1[i]);

  k = 180;
  i = first_ge(t2, 0, 8, k);
  printf("\nIndex of first element >= %d in t2 is %d.\n", k, i);
  printf("The value of that element is %d.\n", t2[i]);

  return 0;
}

int first_ge(const int *a, int lo, int hi, int key)
{
  assert (lo < hi);
  int result, mid;
  if (lo + 1 == hi)
    result = (key <= a[lo]) ? lo : lo + 1;
  else {
    mid = (lo + hi) / 2;
    if (key <= a[mid])
      result = first_ge(a, lo, mid, key);
    else
      result = first_ge(a, mid, hi, key);
  }

  // point one

  return result;
}
