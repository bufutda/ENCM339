// main5B.c
// ENCM 339 Fall 2015 Lab 5 Exercise B

#include <stdio.h>

#include "point5B.h"
#include "line5B.h"

void report(struct line a_line);
// PROMISES: Prints a message on stdout to indicate whether the line
//   represented by a_line is horizontal. Message includes the
//   coordinates of the end points of the line.

int main(void)
{
  struct line my_line;
  struct point p1 = { 5, 10 }, p2 = { 8, 10 }, p3 = { 8, 11 };
  my_line.end1 = p1;
  my_line.end2 = p2;
  report(my_line);
  my_line.end2 = p3;
  report(my_line);
  return 0;
}

void report(struct line a_line)
{
  const char* empty_or_not = "not ";
  if (is_horizontal(&a_line))
    empty_or_not = "";
  printf("The line from (%d, %d) to (%d, %d) is %shorizontal.\n",
	 a_line.end1.x, a_line.end1.y, a_line.end2.x, a_line.end2.y, 
	 empty_or_not);
}