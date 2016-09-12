// File check-insert-8D.cpp
// ENCM 339 Fall 2015 Lab 8 Exercise D

#include <iostream>
#include <cctype>
#include <cstring>
#include <cassert>

using std::cout; using std::endl;
using std::strlen; using std::strcmp;

#include "LabString.h"

// A couple of long strings we'll use to check results against ...

const char check1[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
//                               1         2         3         4         5
//                     0123456789012345678901234567890123456789012345678901

const char check2[] =
  "British Columbia, Alberta, Saskatchewan, Manitoba, Ontario";
//           1         2         3         4         5
// 012345678901234567890123456789012345678901234567890123456789

int main()
{
  cout << "Quick demo of LabString::insert(const char*) ..." << endl;
  LabString hex("0123456789abcdef");
  hex.insert(10, " plus ");
  cout << "  EXPECTED STRING: \"0123456789 plus abcdef\"" << endl;
  cout << "  ACTUAL STRING:   \"" << hex.c_str() << '\"' << endl;
  cout << "  EXPECTED LENGTH: " << strlen("0123456789 plus abcdef") << endl;
  cout << "  ACTUAL LENGTH:   " << hex.length() << endl;

  cout << "\nStarting more extensive tests ..." << endl;
  LabString s1;
  LabString s2;

  // Insert empty string to empty string.
  s1.insert(0, "");
  assert(s1.length() == 0);
  assert(strcmp(s1.c_str(), "") == 0);

  // Insert non-empty string to empty string.
  s1.insert(0, "AaB");
  assert(s1.length() == 3);
  assert(strcmp(s1.c_str(), "AaB") == 0);

  // Insert empty string at start of non-empty string.
  s1.insert(0, "");
  assert(s1.length() == 3);
  assert(strcmp(s1.c_str(), "AaB") == 0);

  // Insert empty string at end of non-empty string.
  s1.insert(3, "");
  assert(s1.length() == 3);
  assert(strcmp(s1.c_str(), "AaB") == 0);

  // Get started inserting things to s2.
  s2.push_back('A');
  s2.insert(1, "b");
  s2.insert(1, "l");
  assert(s2.length() == 3);
  assert(strcmp(s2.c_str(), "Alb") == 0);

  // Now interleave append calls on s1 and s2. That might expose
  // defects involving writes outside of allocated arrays in the heap.

  s2.insert(s2.length(), "erta, ");
  s1.insert(3, "IiJjKkLlMmNPpQ");
  s2.insert(0, "British Columbia, ");
  s1.insert(3, "bCcDdEeFfGgHh");
  s2.insert(s2.length(), "Ontario");
  s1.insert(27, "nOo");
  s2.insert(27, "Saskatchewan, ");
  s1.insert(33, "qRrSsTtUuVvWwXxYyZz");
  s2.insert(41, "Manitoba, ");

  assert(strcmp(s1.c_str(), check1) == 0);
  assert(s1.length() == strlen(check1));
  assert(strcmp(s2.c_str(), check2) == 0);
  assert(s2.length() == strlen(check2));

  cout << "Yay!  If no assertions failed, all tests were passed!" << endl;
  return 0;
}
