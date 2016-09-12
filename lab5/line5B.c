// line5B.c
// ENCM 339 Fall 2015 Lab 5 Exercise B

#include "point5B.h"
#include "line5B.h"

int is_horizontal(const struct line *p)
{
  if (p->end1.y == p->end2.y)
    return 1;
  else
    return 0;
}