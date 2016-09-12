// ENCM 339 LAB7 - EXERCISE D

//  lab7_ExD.cpp

#include <iostream>
#include <iomanip>
using namespace std;

#include "point.h"
#define SIZE 10

void display_point_object(const Point& x);
// REQUIRES: x refers to an object of point
// PROMISES: display the id, and the x and y coordinates of a Point object
//           with the format: Point id: < x, y>. For example:
//           Point 100: <45.000000, 30.000000>

void populate_point_array(Point* arr, int n);
// REQUIRES: arr points to the elments of an array of Points.
//           Elemenats arr[0] ... arr [n-1] exists.
// PROMISES: Populates the elements of the arr with randomly generated values,
//           using rand library function.

Point average(const Point *arr, int n);
// REQUIRES: n > 0
//           arr points to the elments of an array of Points.
//           Elemenats arr[0] ... arr [n-1] exists.
// PROMISES: returns a Point object that its x and y coordiates are equal to the
//           calculated average value of x and y coordinate of the points in arr.
//           The returned object's id will remain the default id value of the
//           Point objects (9999).


int main(void)
{
    Point alpha;
    Point beta (45.00, 30.00, 100);
    Point gamma[SIZE];

    display_point_object(alpha);

    display_point_object(beta);

    display_point_object(gamma[0]);
    display_point_object(gamma[9]);

    populate_point_array(gamma, SIZE);

    cout << "\nArray of points, gamma, contains: \n";

    for(int i = 0; i < SIZE; i++)
        display_point_object(gamma[i]);

    // STUDENTS: WHEN READY TO TEST YOUR FUNCTION AVERAGE, CHANGE #if 0 to #if 1
#if 1
    Point delta = average(gamma, SIZE);
    cout << "\nThe point with the average of points in array gamma is:";
    display_point_object(delta);
#endif

    return 0;
}


void display_point_object(const Point& x)
{
    cout << fixed << setprecision(2);
    cout << "\nPoint " << x.getid() << ": <"  << x.getx() << ", "
    <<  x.gety() << ">\n";
}


void populate_point_array(Point* array, int n)
{
    for( int i = 0; i < n; i++)
    {
        // set the points' data members to some arbirary values...
        array[i].setx((i + 1) * 5);
        array[i].sety((i + 1) * 2);
        array[i].setid(i+101);
    }
}
Point average(const Point *arr, int n)
{
// REQUIRES: n > 0
//           arr points to the elments of an array of Points.
//           Elemenats arr[0] ... arr [n-1] exists.
// PROMISES: returns a Point object that its x and y coordiates are equal to the
//           calculated average value of x and y coordinate of the points in arr.
//           The returned object's id will remain the default id value of the
//           Point objects (9999).
    Point local;
    double xA = 0,  yA = 0;
    for (int i = 0; i < n; i++) {
        xA += arr[i].getx();
        yA += arr[i].gety();
    }
    local.setx(xA / (double)n);
    local.sety(yA / (double)n);
    return local;
/*
    Point local(0,0,9999);
    for (int i = 0; i < n; i++) {
        local.setx(local.getx() + arr[i].getx());
        local.sety(local.gety() + arr[i].gety());
    }
    local.setx(local.getx() / (double)n);
    local.sety(local.gety() / (double)n);
    return local;
*/
}
