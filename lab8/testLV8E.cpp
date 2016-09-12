// File testLV8E.h
// ENCM 339 Fall 2015 Lab Exercise E

// INSTRUCTIONS to students:
//
//   You can use the main function in this file to test the functions
//   you write in LabVector.cpp.
//
//   For example, after you code the copy constructor, you can move the
//        #if 0
//   so that it appears just before the line
//        v6 = v6 = v5 = v4;
//   When you have all of your functions ready for test, you can take
//   out the #if 0 and #endif altogether.
//
//   REMINDER: Testing can increase your confidence that your code is
//   correct, but it can't *prove* that code is defect-free!  Don't
//   assume that your functions are perfect simply because they pass
//   all the tests in main!

#include <iostream>
using std::cout; using std::endl;

#include <cassert>

#include "LabVector.h"

void display(const LabVector& v);
// PROMISES: Displays element values on a single line, separated by spaces.

int main()
{
  LabVector v1;
  cout << "default constructor ..." << endl;
  assert(v1.class_invariant());
  cout << "  EXPECT:" << endl << "  ACTUAL:";
  display(v1);

  for (int i = -4; i < 5; i++)
    v1.push_back(i * 10);
  cout << "push_back ..." << endl;
  assert(v1.class_invariant());
  cout << "  EXPECT: -40 -30 -20 -10 0 10 20 30 40" << endl << "  ACTUAL:";
  display(v1);

  LabVector v2(4, 65);
  cout << "initialization with 4 copies of 65 ..." << endl;
  assert(v2.class_invariant());
  cout << "  EXPECT: 65 65 65 65" << endl << "  ACTUAL:";
  display(v2);

  int x[ ] = { 0, 1, 4, 9, 16 };
  LabVector v3(x, x + sizeof(x) / sizeof(int));
  cout << "initialization from built-in array ... " << endl;
  assert(v3.class_invariant());
  cout << "  EXPECT: 0 1 4 9 16" << endl << "  ACTUAL:";
  display(v3);


  // Check copy initialization.
  LabVector v4(v1);
  v1.at(0) = -88;
  v1.push_back(-99);
  cout << "copy constructor source, after updates ..." << endl;
  assert(v1.class_invariant());
  cout << "  EXPECT: -88 -30 -20 -10 0 10 20 30 40 -99" << endl << "  ACTUAL:";
  display(v1);
  cout << "copy constructor destination ..." << endl;
  assert(v4.class_invariant());
  cout << "  EXPECT: -40 -30 -20 -10 0 10 20 30 40" << endl << "  ACTUAL:";
  display(v4);

  //  Check copy assignment.
  LabVector v5;
  v5.push_back(42);
  LabVector v6;
  v6 = v6 = v5 = v4;
  v4.at(0) = -77;
  cout << "copy assignment operator, v4 after update ..." << endl;
  assert(v4.class_invariant());
  cout << "  EXPECT: -77 -30 -20 -10 0 10 20 30 40" << endl << "  ACTUAL:";
  display(v4);
  cout << "copy assignment operator, v5 result ..." << endl;
  assert(v5.class_invariant());
  cout << "  EXPECT: -40 -30 -20 -10 0 10 20 30 40" << endl << "  ACTUAL:";
  display(v5);
  cout << "copy assignment operator, v6 result ..." << endl;
  assert(v6.class_invariant());
  cout << "  EXPECT: -40 -30 -20 -10 0 10 20 30 40" << endl << "  ACTUAL:";
  display(v6);

  // Check resize.
  cout << "resize ..." << endl;
  v1.resize(4);
  assert(v1.class_invariant());
  cout << "  EXPECT: -88 -30 -20 -10" << endl << "  ACTUAL:";
  display(v1);
  v1.resize(9);
  assert(v1.class_invariant());
  cout << "  EXPECT: -88 -30 -20 -10 0 0 0 0 0" << endl << "  ACTUAL:";
  display(v1);
  v1.resize(11, 42);
  assert(v1.class_invariant());
  cout << "  EXPECT: -88 -30 -20 -10 0 0 0 0 0 42 42" << endl << "  ACTUAL:";
  display(v1);
  v1.resize(0);
  assert(v1.class_invariant());
  cout << "  EXPECT:" << endl << "  ACTUAL:";
  display(v1);
  v1.resize(5, 99);
  assert(v1.class_invariant());
  cout << "  EXPECT: 99 99 99 99 99" << endl << "  ACTUAL:";
  display(v1);
  v1.resize(11, 12);
  assert(v1.class_invariant());
  cout << "  EXPECT: 99 99 99 99 99 12 12 12 12 12 12" << endl << "  ACTUAL:";
  display(v1);

  return 0;
}

void display(const LabVector& v)
{
  for (size_t i = 0; i < v.size(); i++)
    cout << ' ' << v.at(i);
  cout << endl;
}
