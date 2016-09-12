// ENCM 339 - LAB7 - EXERCISE B

//  cplx.cpp

#include "cplx.h"

Cplx::Cplx(double real , double imag ): realM(real),
imagM(imag) {
    // point three - When the program reaches this point for the second time
}

double Cplx::getRealPart() const {
    // point two - When the program reaches this point for the first time
    return realM;
}

double Cplx::getImaginaryPart( ) const {
    return imagM;
}

void Cplx::setRealPart(double arg) {

    realM = arg;
    // Point one
}

void Cplx::setImaginaryPart(double arg) {
    imagM = arg;
}



Cplx Cplx::add(const Cplx& other)const {
    Cplx local;

    // QUESTION 2: In the following line, member function getRealPart, is called.
    //             Is it necessary to call this function inside the member
    //             function add? Can't realM be accessed directly? Which way is
    //             preferred -- please explain why.

    local.realM = /*this->getRealPart()*/this->realM + other.realM;
    //local.realM = realM + other.realM;

    // QUESTION 3: In the following line, the private data member other.imagM is
    //             accessible directly to the member function add, but on the
    //             other hand the same thing is not true for object n in the function
    //             global_print, defined in lab7_ExB.cpp. Explain briefly what
    //             are the rules for accessing private data members of a class-object.


    local.imagM = imagM + other.imagM;

    return local;
}

Cplx Cplx::subtract(const Cplx* other)const {
    Cplx local;
    local.realM = realM - other->realM;
    local.imagM = imagM - other->imagM;

    // point four

    return local;
}
