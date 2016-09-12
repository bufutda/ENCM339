// ThreeVec.cpp
// Provides definitions for member functions of class ThreeVec and
// related non-member functions.

// Written by S. Norman for ENCM 339 Fall 2015 Lab 8 Exercise F

#include "ThreeVec.hpp"
#include <iostream>

// BEGINNING of definitions for member functions of ThreeVec.

bool ThreeVec::is_zero() const
{
  return (xM == 0.0 && yM == 0.0 && zM == 0.0);
}

ThreeVec ThreeVec::operator -() const
{
  ThreeVec result;
  result.xM = -xM;

  // point one

  result.yM = -yM;
  result.zM = -zM;
  return result;
}

// END of definitions for member functions of ThreeVec.

// BEGINNING of definitions for non-member functions related to ThreeVec.

double dot(const ThreeVec& u, const ThreeVec& v)
{
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

ThreeVec operator +(const ThreeVec& lhs, const ThreeVec& rhs)
{
  ThreeVec result;
  result.x() = lhs.x() + rhs.x();
  result.y() = lhs.y() + rhs.y();

  // point two

  result.z() = lhs.z() + rhs.z();
  return result;
}

ThreeVec operator *(double lhs, const ThreeVec& rhs)
{
  ThreeVec result;

  // point three

  result.x() = lhs * rhs.x();
  result.y() = lhs * rhs.y();
  result.z() = lhs * rhs.z();
  return result;
}

ThreeVec operator *(const ThreeVec& lhs, double rhs)
{
  ThreeVec result;
  result.x() = rhs * lhs.x();
  result.y() = rhs * lhs.y();
  result.z() = rhs * lhs.z();
  return result;
}

std::ostream& operator <<(std::ostream& stream, const ThreeVec& v)
{
  stream << '[' << v.x() << ", " << v.y() << ", " << v.z() << ']';
  return stream;
}

// END of definitions for non-member functions related to ThreeVec.
