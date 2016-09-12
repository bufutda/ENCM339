// ThreeVec.hpp
// Defines class ThreeVec and provides prototypes for some related
// non-member functions.

// Written by S. Norman for ENCM 339 Fall 2015 Lab 8 Exercise F

#ifndef THREEVEC_HPP
#define THREEVEC_HPP

#include <iosfwd>
// The above line provides enough information for the compiler to deal
// with the use below of std::ostream, without making the compiler
// read the giant amount of code in <iostream>.

class ThreeVec {
public:
  ThreeVec()
  // PROMISES: All components of vector are 0.0.
    : xM(0.0), yM(0.0), zM(0.0) { }

  ThreeVec(double x, double y, double z)
  // PROMISES: Vector is initialized using the given parameters.
    : xM(x), yM(y), zM(z) { }

  // Each of the next six functions returns a reference to the
  // appropriate component of a vector.
  const double& x() const { return xM; }
  const double& y() const { return yM; }
  const double& z() const { return zM; }
  double& x() { return xM; }
  double& y() { return yM; }
  double& z() { return zM; }

  bool is_zero() const;
  // PROMISES: Return value is true if all components of *this are
  // 0.0, false otherwise.

  ThreeVec operator -() const;
  // Unary - operator.
  // PROMISES: Return value is -1.0 times *this.

private:
  double xM;
  double yM;
  double zM;
};

double dot(const ThreeVec& u, const ThreeVec& v);
// PROMISES: Return value is dot product of u and v.

ThreeVec operator +(const ThreeVec& lhs, const ThreeVec& rhs);
// PROMISES: Return value is vector sum of lhs and rhs.

ThreeVec operator *(double lhs, const ThreeVec& rhs);
// PROMISES: Return value is scalar product of lhs and rhs.

ThreeVec operator *(const ThreeVec& lhs, double rhs);
// PROMISES: Return value is scalar product of lhs and rhs.

std::ostream& operator <<(std::ostream& stream, const ThreeVec& v);
// REQUIRES: stream is open for output.
// PROMISES: Components of v are printed on stream in the format [x, y, z].
//   Reference to stream is returned to allow chained calls to << on
//   stream.

#endif  // #ifndef THREEVEC_HPP
