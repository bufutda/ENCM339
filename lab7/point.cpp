// Lab 7 Exercise D - Fall 2015
//  point.cpp

#include "point.h"
#include "cmath"

Point::Point(): x(-9999), y(-9999), id(9999)
{
    
}

Point::Point(double a, double b, int i):x(a), y(b), id(i)
{

}

void Point::setx(double value)
{
    x = value;
}


double Point::getx()const
{
    return x;
}


void Point::sety(double value)
{
    y = value;
}


double Point::gety()const
{
    return y;
}


void Point::setid(int i)
{
    id= i;
}


int Point::getid()const
{
    return id;
}


double Point::distance(const Point& other)
{
    double diffx = x - other.x;
    double diffy = y - other.y;
    return sqrt(diffx * diffx + diffy * diffy);
}