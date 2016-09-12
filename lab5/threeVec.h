// threeVec.h
// ENCM 339 Fall 2015 Lab 5 Exercise D

#ifndef THREEVEC_H
#define THREEVEC_H

struct threeVec {
  double x;
  double y;
  double z;
};

typedef struct threeVec threeVec_t;

// ATTENTION:
//
//    Some of these functions receive data as values of struct types,
//    and others get input data via pointers.  Some functions communicate
//    results via return values, while others use pointers to write
//    results.
//
//    That kind of inconsistency in related interfaces should generally
//    be avoided.  It's present in this exercise because it makes students
//    decide carefully where . is needed and where -> is needed.

threeVec_t add_3v(threeVec_t u, threeVec_t v);
// PROMISES: Return value is vector sum of u and v.

void scalar_mult(double k, const threeVec_t *src, threeVec_t *dest);
// REQUIRES: src and dest point to threeVec_t objects.
// PROMISES: *dest contains the result of scalar multiplication
//   of k and *src.

double dot_product(const threeVec_t *pu, const threeVec_t *pv);
// REQUIRES: pu and pv point to threeVec_t objects.
// PROMISES: Return value is the dot product of the two vectors.

threeVec_t cross_product(const threeVec_t *pu, const threeVec_t *pv);
// REQUIRES: pu and pv point to threeVec_t objects.
// PROMISES: Return value is vector crossproduct of pu and pv

void array_sum(const threeVec_t *a, int n, threeVec_t *result);
// REQUIRES:
//   n >= 0
//   If n > 0, array elements a[0] ... a[n-1] exist.
//   result points to a threeVec_t object.
// PROMISES:
//   If n == 0, all members of *result have value 0.0.
//   Otherwise, *result contains the sum of the vectors
//   v[0] ... v[n-1].

#endif // #ifndef THREEVEC_H
