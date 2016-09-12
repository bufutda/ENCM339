// line5B.h
// ENCM 339 Fall 2015 Lab 5 Exercise B

#ifndef LINE5B_H  // first part of include guard
#define LINE5B_H  // second part of include guard

#include "point5B.h"

// One way to define a line is to specify its end points ...
struct line {
  struct point end1;
  struct point end2;
};

int is_horizontal(const struct line *p);
// REQUIRES: p points to a line object.
// PROMISES:
//    Return value is 1 if both ends of the line object
//    have the same y-coordinate, 0 otherwise.

#endif  // end of include guard
