// File use-LS-8C.cpp
// ENCM 339 Fall 2015 Lab 8 Exercise C

#include <iostream>
#include <cctype>

using std::cout; 
using std::endl;

#include "LabString.h"

void downcase(LabString& dest, const LabString& src)
{
  dest = src;
  for (size_t i = 0; i < src.length(); i++)
    dest.at(i) = std::tolower(src.at(i));
}

int main()
{
  LabString x;
  LabString y("qUuX");
  y.push_back('3');
  y.push_back('4');
  downcase(x, y);
  x.at(4) = x.at(5) = '2';
  cout << "x contains " << x.c_str() << endl;
  cout << "y contains " << y.c_str() << endl;

  // The next line will trigger a program crash.
  x.at(6) = '!';

  return 0;
}
