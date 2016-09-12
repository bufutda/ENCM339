//  h-min-s.c

//  Started by:   Steve Norman
//
//  Completed by: Mitchell Sawatzky
//   Lab section: B02
//          Date: Tuesday Sept 22, 2015

#include <stdio.h>
#include <stdlib.h>

#define SEC_PER_HOUR 3600
#define SEC_PER_MIN 60

void s2hms(int total_s, int *h, int *min, int *s);
//
// Converts a number of seconds into hours, minutes, and seconds.
// For example, converts 3678s into 1h, 1min, 18s.
// REQUIRES:
//   total_s >= 0. Pointer arguments all point to appropriate variables.
// PROMISES:
//   Hour result is in *h.
//   Minutes result is in *min.
//   Seconds result is in *s.

int main(void)
{
  int s_in, h_out, min_out, s_out, scan_count;

  printf("Enter a time interval as an integer number of seconds: ");
  scan_count = scanf("%d", &s_in);
  if (scan_count != 1) {
    printf("Unable to convert your input to an int.\n");
    exit(1);
  }
  if (s_in < 0) {
    printf("I can't work with a negative number of seconds!.\n");
    exit(1);
  }
  printf("Doing conversion for input of %d seconds ... \n", s_in);

  // MAKE A CALL TO s2hms HERE.
  s2hms(s_in, &h_out, &min_out, &s_out);

  printf("That is equivalent to %d hours(s), %d minutes(s), %d second(s).\n",
	 h_out, min_out, s_out);

  return 0;
}

// WRITE A DEFINITION FOR s2hms HERE.
// Hints:
//    1. Use SEC_PER_HOUR and SEC_PER_MIN as defined above.
//    2. / for integer division and % for integer remainder are useful here.

void s2hms(int total_s, int *h, int *min, int *s)
{
    *h = total_s / SEC_PER_HOUR;
    *min = total_s % SEC_PER_HOUR / SEC_PER_MIN;
    *s = total_s % SEC_PER_HOUR % SEC_PER_MIN;
    return;
}
