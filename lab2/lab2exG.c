/* * * * * * * * * * * * * * * * * * * * * * * *
 * Title: lab2exF.c                            *
 * Name: Mitchell Sawatzky                     *
 * UCID: 10146721                              *
 * Class: ENCM 339-T01/B02                     *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>

void get_input(double *km_in, int *hours_in, int *minutes_in);
// REQUIRES:
//     All three arguments as addresses of appropriate variables
// PROMISES:
//     Function will prompt for user inputs and fill each argument
//     with the appropriate values.

int get_int_or_die(void);
// REQUIRES:
//    User has been prompted to enter an int.
// PROMISES:
//    Function tries to read an int using scanf and "%d"
//    On success, that int is echoed to the user,
//    and the int is the function return value.
//    On failure, and error message is printed and
//    exit is called with an argument of 1.

double get_double_or_die(void);
// Like get_int_or_die, but tries to read a double using "%lf".

int main(void)
{
    int hours, mins, total_seconds;
    double dist;

    get_input(&dist, &hours, &mins);

    if (hours <= 0) {
        printf("Cannot compute a 0 or negative time!\n");
        exit(1);
    }
    if (mins <= 0) {
        printf("Cannot compute a 0 or negative time!\n");
        exit(1);
    }

    printf("Distance travelled: %lf km.\n", dist);
    printf("Time of travel: %d hour(s), %d minute(s).\n", hours, mins);
    printf("Average speed, in different units ...\n");

    total_seconds = 3600*hours + 60*mins;
    printf("\t%lf km/h.\n", (dist * 3600.0) / total_seconds);
    printf("\t%lf m/s.\n", (dist * 1000.0) / total_seconds);
    printf("\t%lf mph.\n", (dist * 1000.0 * 3600.0) / (5280.0 * 0.3048 * total_seconds));

    return 0;
}

void get_input(double *km_in, int *hours_in, int *minutes_in)
{
    printf("Please enter a distance in km, using type double.\n");
    *km_in = get_double_or_die();
    printf("Please enter number of hours, using type int.\n");
    *hours_in = get_int_or_die();
    printf("Please enter a number of minutes, using type int.\n");
    *minutes_in = get_int_or_die();

    return;
}

int get_int_or_die(void)
{
  int result;
  if (1 != scanf("%d", &result)) {
    printf("I could not read an int. I am quitting.\n");
    exit(1);
  }
  printf("I read an int value of %d.\n", result);
  return result;
}

double get_double_or_die(void)
{
    double result;
    if (1 != scanf("%lf", &result)) {
        printf("I could not read a double. I am quitting.\n");
        exit(1);
    }
    printf("I read a double value of %lf.\n", result);
    return result;
}
