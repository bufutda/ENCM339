// demo8F.cpp
// Demonstrates some of the functionality of class ThreeVec.

// Written by S. Norman for ENCM 339 Fall 2015 Lab 8 Exercise F

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "ThreeVec.hpp"

ThreeVec projection(const ThreeVec& u, const ThreeVec& v);
// REQUIRES: !v.is_zero()
// PROMISES: Return value is the projection of u on to v.

int main()
{
  ThreeVec c;
  ThreeVec a(0.5, 1.0, 1.0);
  ThreeVec b(1.25, 1.0, 0.0);

  assert(c.is_zero());
  assert(!a.is_zero());
  assert(!b.is_zero());
  cout << "ThreeVec::is_zero seems to do the right thing!" << endl;

  b.z() = 1.5;

  cout << "a is " << a << " and b is " << b << endl;

  c = -a;
  cout << "Negation of a is " << c << endl;

  c = a + b;
  cout << "Sum of a and b is " << c << endl;
  
  c = 0.5 * a;
  cout << "0.5 * a is " << c << endl;

  c = b * 2.0;
  cout << "b * 2.0 is " << c << endl;

  c = projection(b, a);
  cout << "Projection of b on to a is  " << c << endl;

  return 0;
}

ThreeVec projection(const ThreeVec& u, const ThreeVec& v)
{
  assert(!v.is_zero());

  return (dot(u, v) / dot(v, v)) * v;
}
