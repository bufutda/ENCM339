// array-utils-4F.h
// ENCM 339 Fall 2015 Lab 4 Exercise F

int is_sorted(const int *a, int n);
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. 
// PROMISES
//   If n == 1, returns 1.
//   Returns 1 if all of a[0] <= a[1] ... a[n-2] <= a[n-1] are true.
//   Otherwise, returns 0.

int max_el(const int *a, int n);
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. 
// PROMISES: Returns the largest value among a[0] ... a[n-1].

int is_arith_seq(const int *a, int n);
// Decides whether array elements form an arithmetic sequence.
// In an arithmetic sequence, each pair of adjacent items differ
// by the same amount.  For example, 1, 4, 7, 10 is an arithmetic 
// sequence, but 1, 4, 6, 9 is not. 
//
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. 
// PROMISES
//    The return value is 1 if n == 1.
//    If n > 1, the return value is 1 if a[0] ... a[n-1] form
//    an arithmetic sequence.
// PROMISES
//    Otherwise, the return value is 0.
