// File LabVector.h
// ENCM 339 Fall 2015 Lab Exercise E

#ifndef LABVECTOR_H
#define LABVECTOR_H

#include <cassert>
#include <cstddef>
using std::size_t;

typedef int ElType;
const ElType DefaultEl = 0;

class LabVector {
public:
  LabVector() : storeM(0), end_validM(0), end_storeM(0) { }
  // Default constructor initializes vector as empty.

  LabVector(size_t count, const ElType& el_val = DefaultEl);
  // PROMISES: size() == count.
  //   Elements 0 to size()-1 are all equal to el_val.

  LabVector(const ElType *begin, const ElType *end);
  // REQUIRES: begin points to an array element, such that
  //   *begin, *(begin+1), ..., *(end-1) are all elements of the
  //   same array.
  // PROMISES:
  //   size() = end - begin.
  //   Vector elements 0 ... size()-1 are initialized using values of
  //   *begin, *(begin+1), ..., *(end-1)

  LabVector(const LabVector& src);  
  LabVector& operator=(const LabVector& rhs);
  ~LabVector() { delete [ ] storeM; }

  bool class_invariant() const;
  // PROMISES:
  //   Return value is true if object appears to be complying with
  //   class memory management policy.
  // NOTE:
  //   A return value of false indicates that one or more member
  //   function definitions are defective and need to be fixed.

  size_t size() const { return end_validM - storeM; }
  size_t capacity() const { return end_storeM - storeM; }
  const ElType& at(size_t i) const { assert (i < size()); return storeM[i]; }
  
  ElType& at(size_t i) { assert (i < size()); return storeM[i]; }

  void push_back(const ElType& el_val);
  // PROMISES: Size of vector is increased by one element.
  //   Last element of vector is equal to el_val.

  void resize(size_t new_size, const ElType& extra_val = DefaultEl);
  // PROMISES: size() is changed to new_size.
  //   If new_size <= previous size, values of elements 0 to new_size-1
  //   are preserved. Tf new_size > previous size, values of elements 0 to 
  //   (previous size)-1 are preserved, and elements (previous size) to
  //   new_size-1 are equal to extra_val.

private:
  ElType *storeM;
  ElType *end_validM;
  ElType *end_storeM;
};

#endif
