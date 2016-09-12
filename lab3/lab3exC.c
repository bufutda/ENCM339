// ENCM 339 Fall 2015 Lab 3 Exercise C

// This program, as posted on D2L, is DEFECTIVE!

#include <stdio.h>

void time_diff(int earlier_h, int earlier_min, int later_h, int later_min,
	       int *diff_h, int *diff_min);
// Computes difference between two times in the same day. Assumes use of
// a 24-hour clock.

int a[2];

int main(void)
{
  int t1_h = 23, t1_min = 7, t2_h = 10, t2_min = 53;
  int p_h, p_min;

  printf("Difference in time between %02d:%02d and between %02d:%02d is ...\n",
	 t1_h, t1_min, t2_h, t2_min);
  time_diff(t2_h, t2_min, t1_h, t1_min, &p_h, &p_min);
  printf("... %d hour(s) and %d minute(s).\n", p_h, p_min);
  return 0;
}

void time_diff(int earlier_h, int earlier_min, int later_h, int later_min,
	       int *diff_h, int *diff_min)
{
  if (later_min >= earlier_min) {
    *diff_h = later_h - earlier_h;
    *diff_min = later_min - earlier_min;
  }
  else {
    *diff_h = later_h - earlier_h - 1;
    *diff_min = later_min + 60 - earlier_min;
  }
}
