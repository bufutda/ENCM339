// File TracerV2.h
// ENCM 339 Fall 2015 Lab 8

#ifndef TRACERV2_H
#define TRACERV2_H

#include <iostream>
using std::cout; using std::endl;

class TracerV2 {
public:
  TracerV2() : dataM(0) { 
    cout << "default ctor" << endl;
  }
  TracerV2(int init) : dataM(init) { 
    cout << "ctor with int arg " << init << endl;
  }
  TracerV2(const TracerV2& src) : dataM(src.dataM) {
    cout << "copy ctor " << dataM << endl;
  }
  TracerV2& operator=(const TracerV2& rhs) {
    if (this != &rhs) {
      dataM = rhs.dataM;
      cout << "usual assign " << dataM << endl;
    }
    else
      cout << "self assign " << dataM << endl;
    return *this;
  }
  ~TracerV2() { cout << "dtor " << dataM << endl; }
  int data() const { return dataM; } 
  TracerV2& inc() { 
    dataM++; 
    
    // point one for Lab 8 Exercise A only (not Exercise B)

    return *this;
  }
private:
  int dataM;
};
#endif
