// File compiler-synth.cpp
// ENCM 339 Fall 2015 Lab 8 Exercise B

#include "TracerV2.h"

class ClassOne {
public:
  int get_w() const { return wM.data(); }
  int get_x() const { return xM.data(); }
  ClassOne& inc_w() { wM.inc(); return *this; }
  ClassOne& inc_x() { xM.inc(); return *this; }
private:
  TracerV2 wM;
  TracerV2 xM;
};

class ClassTwo {
public:
  ClassTwo() {}
  ClassTwo(int yA, int zA) : yM(yA), zM(zA) { }
  int get_y() const { return yM.data(); }
  int get_z() const { return zM.data(); }
  ClassTwo& inc_y() { yM.inc(); return *this; }
  ClassTwo& inc_z() { zM.inc(); return *this; }
private:
  TracerV2 yM;
  TracerV2 zM;
};

int main()
{
  ClassOne c1;
  c1.inc_w().inc_x().inc_w();
  cout << "wM in c1 is " << c1.get_w() << endl;
  cout << "xM in c1 is " << c1.get_x() << endl;

  ClassTwo c2a(20, 100);
  c2a.inc_z().inc_z().inc_z().inc_y();
  cout << "yM in c2a is " << c2a.get_y() << endl;
  cout << "zM in c2a is " << c2a.get_z() << endl;

  ClassTwo c2b(30, 200);
  c2b = c2a;
  c2b.inc_z();
  cout << "yM in c2b is " << c2b.get_y() << endl;
  cout << "zM in c2b is " << c2b.get_z() << endl;

  // point one

#if 1
  ClassTwo c2c;
  c2c.inc_y().inc_y().inc_y();
  cout << "yM in c2c is " << c2c.get_y() << endl;
  cout << "zM in c2c is " << c2c.get_z() << endl;
#endif

  return 0;
}
