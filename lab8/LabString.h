// File LabString.h
// ENCM 339 Fall 2015 Lab 8

#ifndef LABSTRING_H
#define LABSTRING_H

#include <cstddef>
#include <cstdlib>
#include <iostream>

using std::size_t;

class LabString {
public:
  LabString() : storageM(0), lengthM(0), capM(0)
  { }
  // PROMISES: Initializes object to be empty (that is, zero-length).

  LabString(const char *s);
  // REQUIRES: s points to start of '\0'-terminated C string.
  // PROMISES: Initializes object by copying the C string.

  LabString(const LabString& src);
  LabString& operator=(const LabString& rhs);
  ~LabString() { delete [ ] storageM; }

  size_t length() const { return lengthM; } 
  // PROMISES: Returns number of characters in front of '\0'.

  const char& at(size_t i) const { range_check(i); return storageM[i]; }
  // REQUIRES: i < length()
  // PROMISES: Access to char at position i in string is provided.

  const char *c_str() const { return (lengthM == 0) ? "" : storageM; }
  // PROMISES: Returns pointer suitable for use as an argument to
  //   functions that expect to work with a C-style string.

  char& at(size_t i) { range_check(i); return storageM[i]; }
  // REQUIRES: i < length()
  // PROMISES: Access to char at position i in string is provided.

  void push_back(char c);
  // PROMISES: 
  //   If c != '\0', increases lengthM of string by 1 by adding c to
  //   the end.  If c == '\0', does nothing.

  LabString& append(const char *s);
  // REQUIRES: s points to start of '\0'-terminated C string.
  // PROMISES: Lengthens string object by copying the C string to
  //   the end of the object's sequence of chars. Returns reference
  //   to *this to support expressions like x.append("foo").append("bar").

  LabString& append(const LabString& src);
  // PROMISES: Has same effect as append(src.c_str() ).

  LabString& insert(size_t pos, const char *s);
  // REQUIRES: pos <= length()
  //   s points to start of '\0'-terminated C string.
  // PROMISES: Lengthens string object by inserting all the non-'\0'
  //   chars from the C string into the object's sequence of chars,
  //   starting at position pos.  Returns reference to *this.

  LabString& insert(size_t pos, const LabString& src);
  // REQUIRES: pos <= length()
  // PROMISES: Has same effect as insert(pos, src.c_str() ).

private:
  void grow_cap(size_t new_cap);
  void range_check(size_t index) const {
    if (index >= lengthM) {
      std::cerr << "bad index of " << index 
		<< " used in LabString with length " << lengthM << std::endl;
      std::abort();
    }
  }
  char *storageM;
  size_t lengthM;
  size_t capM;
};
#endif
