// File LabString.cpp
// ENCM 339 Fall 2015 Lab 8

// This file contains member function definitions for the LabString class.

/*
  IMPORTANT: All member functions must respect the following memory
  management policies:

  Empty LabString objects must have lengthM == 0 and capM == 0, and a
  null pointer value for storageM.

  In non-empty objects, lengthM must be the number of characters up to
  but not including a terminating '\0' character.  storageM must point
  to an array of chars obtained with new[].  capM must be equal to the
  size of the array. Of course, for safe use of heap memory, it must
  be true that lengthM + 1 <= capM, so that there is room for a '\0'
  character in storageM[lengthM].
*/

#include <cassert>
#include "LabString.h"

LabString::LabString(const char *s)
  : storageM(0), lengthM(0), capM(0)
{
  size_t len = 0;
  while (s[len] != '\0')
    len++;
  if (len > 0) {
    storageM = new char[len + 1];
    for (size_t i = 0; i <= len; i++)
      storageM[i] = s[i];
    lengthM = len;
    capM = len + 1;
  }
}

LabString::LabString(const LabString& src)
  : lengthM(src.lengthM)
{
  capM = lengthM + 1;
  storageM = new char[capM];
  for (size_t i = 0; i <= lengthM; i++)
    storageM[i] = src.storageM[i];
}

LabString& LabString::operator=(const LabString& rhs)
{
  if (this == &rhs)
    return *this;

  lengthM = rhs.lengthM;
  if (lengthM == 0) {
    storageM = 0;
    capM = 0;
    return *this;
  }

  if (lengthM >= capM) {
    delete [ ] storageM;
    capM = lengthM + 1;
    storageM = new char[capM];
  }

  for (size_t i = 0; i <= lengthM; i++)
    storageM[i] = rhs.storageM[i];

  // point one

  return *this;
}

void LabString::push_back(char c)
{
  if (c == '\0')
    return;

  // Get bigger array if current array is full.
  if (capM < lengthM + 2) {
    if (capM == 0)
      grow_cap(4);
    else
      grow_cap(2 * capM);
  }

  // Copy c to end of string, update lengthM, and put '\0' in the right place.
  storageM[lengthM] = c;
  lengthM++;
  storageM[lengthM] = '\0';
}

// grow_cap is a helper function for push_back.  It is also suitable
// as a helper function for both versions of the append function.
// (But it is not recommended as a helper for insert.)
void LabString::grow_cap(size_t new_cap)
{
  assert(new_cap > capM);

  // Get a bigger array and copy chars out of the smaller array.
  char * new_storage = new char[new_cap];
  for (size_t i = 0; i < lengthM; i++)
    new_storage[i] = storageM[i];
  new_storage[lengthM] = '\0';

  // Get rid of the smaller array and update member variables of *this.
  delete [ ] storageM;
  storageM = new_storage;
  capM = new_cap;
}

LabString& LabString::insert(size_t pos, const char *s)
{
    int i = 0, j, k;

    while (s[i] != '\0')
        i++;
    if (i == 0)
        return *this;
    char* new_storage = new char[i + lengthM + 1];
    for (j = 0, k = 0; j <= lengthM; j++) {
        for (; j == pos && k < i; k++) {
            new_storage[j + k] = s[k];
        }
        if (storageM)
            new_storage[j + k] = storageM[j];
    }
    delete [ ] storageM;
    storageM = new_storage;
    lengthM += i;
    storageM[lengthM] = '\0';
    return *this;
}
