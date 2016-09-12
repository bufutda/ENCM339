// File LabVector.cpp
// ENCM 339 Fall 2015 Lab Exercise E

/*
  Memory management policy for LabVector objects ...

  For empty vectors the pointers storeM, end_validM and end_storeM
  must all be null. This will ensure that size() and capacity() calls
  will both produce 0 by subtracting null from null.

  For non-empty vectors, storeM points at element 0 of allocated
  storage, end_validM points just past the end of storage of
  valid elements, and end_storeM points just past the and of
  allocated storage.  This is illustrated below with an example
  of a vector with size() == 2 and capacity() == 4.

                +----+         +----+
         storeM | *--+-------->| 11 |
                +----+         +----+
                               | 22 |
                +----+         +----+
     end_validM | *--+-------->| ?? |
                +----+         +----+
                               | ?? |
                +----+         +----+
     end_storeM | *--+-------->
                +----+

  Note that pointer subtraction will simply and quickly produce correct
  results for calls to size() and capacity().
*/

// INSTRUCTIONS to students:
//    There are three function definitions missing from this file.
//    Your job is to code them correctly, respecting the documentation
//    given in LabVector.h and also the memory management policy given
//    above.

#include <cassert>
using namespace std;
#include "LabVector.h"

LabVector::LabVector(size_t count, const ElType& el_val)
  : storeM(0), end_validM(0), end_storeM(0)
{
  if (count == 0)
    return;

  storeM = new ElType[count];
  end_storeM = end_validM = storeM + count;
  for (size_t i = 0; i < count; i++)
    storeM[i] = el_val;
}


LabVector::LabVector(const ElType *begin, const ElType *end)
  : storeM(0), end_validM(0), end_storeM(0)
{
  assert(begin <= end);
  if (begin == end)
    return;

  size_t count = end - begin;
  storeM = new ElType[count];
  end_storeM = end_validM = storeM + count;
  for (size_t i = 0; i < count; i++)
      storeM[i] = begin[i];
}


// Add definition for copy constructor here.
LabVector::LabVector(const LabVector& src)
{
    size_t i, count = src.capacity();
    storeM = new ElType[count];
    end_storeM = storeM + count;
    for (i = 0; i < src.size(); i++)
        storeM[i] = src.storeM[i];
    end_validM = storeM + i;
}

// Add definition for copy assignment operator here.
LabVector& LabVector::operator=(const LabVector& rhs)
{
    if (this == &rhs)
        return *this;
    delete [ ] storeM;
    size_t i, count = rhs.end_storeM - rhs.storeM;
    storeM = new ElType[count];
    end_storeM = storeM + count;
    for (i = 0; i < rhs.end_validM - rhs.storeM; i++)
        storeM[i] = rhs.storeM[i];
    end_validM = &storeM[i];
    return *this;
}

bool LabVector::class_invariant() const
{
  // Definitive check for an empty vector ...
  bool empty_and_good =
    (storeM == 0) && (end_validM == 0) && (end_storeM == 0);
  if (empty_and_good)
    return true;

  // This is not definitive; the value might be true even if the
  // pointers aren't exactly right ...
  bool non_empty_probably_good =
    (storeM < end_validM) && (end_validM <= end_storeM);
  return non_empty_probably_good;
}


void LabVector::push_back(const ElType& el_val)
{
  // Need a bigger array if current array is full.
  if (end_validM == end_storeM) {
    size_t old_size = size();
    size_t new_cap = (capacity() == 0) ? 2 : 2 * capacity();
    ElType *new_store = new ElType[new_cap];
    for (size_t i = 0; i < size(); i++)
      new_store[i] = storeM[i];
    delete [ ] storeM;
    storeM = new_store;
    end_validM = new_store + old_size;
    end_storeM = new_store + new_cap;
  }
  *end_validM = el_val;
  end_validM++;
}

// Add definition for resize here.
void LabVector::resize(size_t new_size, const ElType& extra_val)
{
    if (new_size == 0)
        storeM = end_validM = end_storeM = 0;
    else {
        ElType* new_store = new ElType[new_size];
        size_t count = size(), i;
        for (i = 0; i < new_size; i++) {
            new_store[i] = (i < count ? storeM[i] : extra_val);
        }
        end_storeM = end_validM = new_store + i;
        delete [ ] storeM;
        storeM = new_store;
    }
}
