// cplx.h
// Lab 7 Exercise B - Fall 2015


#ifndef lab7_exe_B_Cplx
#define lab7_exe_B_Cplx
/* The following class definition represnets Complex Numbers and contains two
 * private data members called realM (the real part of a complex number),
 * and imagM (the imaginary part of a complex number).
 */

class Cplx {
public:
    
    Cplx (double r = -999, double i = -999);
    // PROMISES: initializes the real part and the imaginary part of a complex number
    // with the supplied values by r, and i, respectively.
    
    double getRealPart () const;
    // PROMISES: returns real part of a complex number.
    
    double getImaginaryPart () const;
    // PROMISES: returns imaginary part of a complex number
    
    void setRealPart(double arg);
    // PROMISES: sets a new value to real part of a complex number with the
    //           value of arg.
    void setImaginaryPart(double arg);
    // PROMISES: sets a new value to imaginary part of a complex number with the
    //           value of arg.
    
    Cplx add(const Cplx& other)const;
    // PROMISES: returns a Cplx object which its real part is the result of
    //           this object's real part plus the other object's real part,
    //           and its imaginary part is this object's imaginary part plus
    //           plus the other object's imaginary part.
    
    Cplx subtract(const Cplx* other)const;
    // PROMISES: returns a Cplx object which its real part is the result of
    //           this object's real part mius the other object's real part,
    //           and its imaginary part is the result of this object's imaginary
    //           part minus the other object's imaginary part.
private:
    double realM;  // the real part of a complex number
    double imagM;  // the imaginary part of a complex number
};

#endif