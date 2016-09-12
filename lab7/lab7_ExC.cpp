// File lab7_ExC.cpp
// ENCM 339 LAB7 - EXERCISE C

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

#include "lab7_time.h"

void print(const Time& t);
// REQUIRES: t refers to an object of class Time with valid values.
// PROMISES: displays the time values in an object of class Time:
//           hours:minutes:seconds.

int main(void) {

    Time t1;
    print(t1);       // Must print: 00:00:00

    Time t2(7832);
    print(t2);       // Must print: 02:10:32

    t1.increment_by_n(7832);
    t1.increment_by_n(0);
    print(t1);       // Must print: 02:10:32

    t1.increment_by_n(60);
    print(t1);      // Must print: 02:11:32

    t1.decrement_by_n(60);
    print(t1);      // Must print: 02:10:32

    t1.decrement_by_n (-60);
    print(t1);      // Must print: 02:10:32

    t2.set_time(3719);
    print(t2);       // Must print: 01:01:59

    Time t3 = t1.add(t2);
    print(t3);       // Must print: 03:12:31

    t3.decrement_by_n(500000);
    print(t3);       // Must print: 00:00:00
    t3.increment_by_n(50000);
    print(t3);       // Must print: 13:53:20

    t3.increment_by_n(-50000);
    print(t3);       // Must print: 13:53:20

    t2.set_time(0);
    print(t2);       // Must print: 00:00:00

    t2.set_time(-10);
    print(t2);       // Must print: 00:00:00

    return 0;
}


void print(const Time& t)
{
    cout << setw(2) << setfill('0') << t.get_hour() << ":"
    << setw(2) << t.get_minute() << ":" << setw(2) << t.get_second() << endl;
}
