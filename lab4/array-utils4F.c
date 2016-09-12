// array-utils-4F.c
// ENCM 339 Fall 2015 Lab 4 Exercise F

// ATTENTION: The definitions given below for is_sorted and max_el
// are DEFECTIVE!

#include <assert.h>

#include "array-utils4F.h"

int is_sorted(const int *a, int n)
{
  assert (n >= 1);

  if (n == 1)
    return 1;

  int k, result;
  for (k = 0; k < n - 1; k++) {
    if (a[k] <= a[k + 1])
      result = 1;
    else {
      result = 0;
      break;
    }
  }
  return result;
}

int max_el(const int *a, int n)
{
  assert(n >= 1);

  int result = a[0], i;
  for (i = 1; i < n; i++)
    if (a[i] > result)
      result = a[i];
  return result;
}

int is_arith_seq(const int *a, int n)
{
    assert (n >= 1);

    if (n == 1)
        return 1;

    int i, sum = a[1]-a[0];
    for (i=1; i < n; i++) {
        if (a[i]-a[i-1] != sum)
            return 0;
    }
    return 1;
}

#ifdef UNIT_TESTS
#include <stdio.h>

// This macro works for variables declared to be arrays. (DON'T try to
// use for function parameters declared to be arrays!)
#define COUNT(x) (sizeof(x)/sizeof(x[0]))

void test_is_sorted(const char *tag, const int *a, int n, int expected_rv);
void test_max_el(const char *tag, const int *a, int n, int expected_rv);
void test_is_arith_seq(const char *tag, const int *a, int n, int expected_rv);

int main(void)
{
  int test_01[] = { 10, 20, 30, 40, 50 };
  int test_02[] = { 10, 10, 10, 10 };
  int test_03[] = { 10, 20, 30, 40, 35 };
  int test_04[] = { 10, 20, 30, 25, 40 };
  int test_05[] = { 10, 5, 15, 25 };
  test_is_sorted("test_01", test_01, COUNT(test_01), 1);
  test_is_sorted("test_02", test_02, COUNT(test_02), 1);
  test_is_sorted("test_03", test_03, COUNT(test_03), 0);
  test_is_sorted("test_04", test_04, COUNT(test_04), 0);
  test_is_sorted("test_05", test_05, COUNT(test_05), 0);
  fputc('\n', stdout);

  int test_06[] = { 100, 1, 2, 3 };
  int test_07[] = { 1, 2, 100, 3 };
  int test_08[] = { 1, 2, 3, 100 };
  int test_09[] = { -1, -2, -3, -4 };
  int test_10[] = { -8, -7, -6, -7, -8 };
  test_max_el("test_06", test_06, COUNT(test_06), 100);
  test_max_el("test_07", test_07, COUNT(test_07), 100);
  test_max_el("test_08", test_08, COUNT(test_08), 100);
  test_max_el("test_09", test_09, COUNT(test_09), -1);
  test_max_el("test_10", test_10, COUNT(test_10), -6);
  fputc('\n', stdout);

  int test_11[] = { 4, 3, 2, 1 };
  int test_12[] = { 1, 2, 3, 4 };
  int test_13[] = { 1, 2, 3, 100 };
  int test_14[] = { -1, -2, -3, -4 };
  int test_15[] = { 2, 4, 6, 8, 10 };
  test_is_arith_seq("test_11", test_11, COUNT(test_11), 1);
  test_is_arith_seq("test_12", test_12, COUNT(test_12), 1);
  test_is_arith_seq("test_13", test_13, COUNT(test_13), 0);
  test_is_arith_seq("test_14", test_14, COUNT(test_14), 1);
  test_is_arith_seq("test_15", test_15, COUNT(test_15), 1);
  fputc('\n', stdout);

  return 0;
}

void test_is_sorted(const char *tag, const int *a, int n, int expected_rv)
{
  printf("Testing is_sorted for case with tag \"%s\":", tag);
  if (expected_rv == is_sorted(a, n))
    printf(" Pass.\n");
  else
    printf(" FAIL!\n");
}

void test_max_el(const char *tag, const int *a, int n, int expected_rv)
{
  printf("Testing max_el for case with tag \"%s\":", tag);
  if (expected_rv == max_el(a, n))
    printf(" Pass.\n");
  else
    printf(" FAIL!\n");
}

void test_is_arith_seq(const char *tag, const int *a, int n, int expected_rv)
{
    printf("Testing is_arith_seq for case with tag \"%s\":", tag);
    if (expected_rv == is_arith_seq(a, n))
        printf(" Pass.\n");
    else
        printf(" FAIL!\n");
}

#endif // #ifdef UNIT_TESTS
