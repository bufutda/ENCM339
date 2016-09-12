// File trace-me8A.cpp
// ENCM 339 Fall 2015 Lab 8 Exercise A

#include "TracerV2.h"

void foo(TracerV2 x, TracerV2& y);

TracerV2* bar();

int main()
{
  TracerV2 a, b(30);
  TracerV2 c(b);
  TracerV2 *d = bar();
  d[1] = b;
  d[1].inc().inc().inc().inc();
  foo(a, b);
  c.inc().inc();
  delete [ ] d;
  return 0;
}

void foo(TracerV2 x, TracerV2& y)
{
  TracerV2 z(40);
  x.inc();
  y.inc();
  z.inc();

  // point two

  cout << "data in foo's parameters: " << x.data() << ' ' << y.data() << endl;
  cout << "data in foo's local variable: " << z.data() << endl;
}

TracerV2* bar()
{
  TracerV2 g(60);
  TracerV2 *h = new TracerV2[3];
  h[0].inc().inc();
  h[2] = g;
  h[2].inc();
  return h;
}
