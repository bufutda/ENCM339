// File: Lab-ExD.h
// Lab 6 - Exercise D, Fall 2015

#ifndef STRING_STRUCT
#define STRING_STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* The purpose of this exercise is to practice dynamic allocation of c-strings
 * on the memory. Also showing you a tiny step towards concept of data
 * abstraction that is a bigger topic taught later in this course (in C++).
 */

typedef struct String{
    // Must be pointing to a memory space on the heap or being set to NULL
    char* dynamic_storage;
    // Represents the length of a c-string being pointed by dynamic_storage.
    unsigned long length;
} String;


void create_empty_string (String *str);
/*
 * REQUIRES:
 * str->dynamic_storage must be a NULL pointer or pointing to a valid c-string
 * dynamically allocated on the heap.

 * PROMISES:
 * using library function realloc resizes the block of the memory
 * of str->dynamic_storage to 1 byte, places a '\0' in that element, sets data
 * member length to zero.
 */
void String_cpy(String *dest, const char* src);
/* REQUIRES:
 *  dest points to a String instance with a valid c-string (terminated with a '\0'),
 *  and with a correct length that represents the length of the valid c-string.
 *  src points to a valid c-string terminated with a '\0'.

 * PROMISES:
 * replaces the c-string and its length in the destination object (pointed by dest)
 * with the c-string and its length in the array that src points to.
 */
void String_copy(String *dest, const String* src);
/* REQUIRES:
 * dest and src point to two String instances with valid c-strings (terminated
 * with a '\0'), and correct corresponding length.
 * PROMISES:
 * replaces the string and its length in the destination object (pointed by dest)
 * with the string and length in the source object (pointed by src).
 */

void String_append(String *dest, const String* source);
/* REQUIRES:
 * dest and source point to two String instances with valid c-strings (terminated
 * with a '\0'), and correct corresponding length.

 * PROMISES:
 * Dynamically manages the memory and appends the c-string in the source
 * ( pointed by source->dynamic_storage), to the end of c-string in the dest
 * ( pointed by dest->dynamic_storage). Also, updates the value of dest->length
 * accordingly.

 * EXAMPLE:
 * if dest->dynamic_storage points to "ABCD" on the heap (which its length is 4),
 * and source->dynamic_storage points to "xyz" on the heap (which its length is 3),
 * after a call to this function dest->dynamic_storage should be pointing to
 * "ABCDxyz" on the heap and its length must be 7.
 */

void String_truncate(String *dest, int new_length);
/* REQUIRES:
 * dest points to a String instance with a valid c-string termiated with a '\0'.
 * new_length is greater than or equal zero.
 *
 * PROMISES:
 * truncates the dynamic_storage in an object of String from an existing length
 * to a new_length: By dynamically reducing the size of existing space on the heap
 * to the new_length plus one for '\0'.
 * If new_length >= dest->length does nothing.
 */

void display_String(const String* s);
/* REQUIRES:
 * s pointing to an instance of String with a valid c-string (terminated with a
 * '\0').

 * PROMISES:
 * displays the c-string that str->dynamic_storage points at, and its length.
 */
#endif
