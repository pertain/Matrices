/*
 * Complex.h
 *
 *  Created on: Nov 26, 2013
 *      Author: William Ersing
 */

//  Complex stores complex numbers
//  in two parts:
//  real, and imaginary (imag)


//  This class has the following member functions
//
//-----------------------------------------------------------------------------------
//
//  Complex(float, float)
//
//  Parameters:     real, float, represents the real part of a complex number, passed by value
//                  imag, float, represents the imaginary part of a complex number, passed by value
//  Post-condition: Parameterized constructor for Complex objects
//
//-----------------------------------------------------------------------------------
//
//  Complex operator+(Complex)
//
//  Parameters:     cx, Complex, represents a Complex object, passed by reference
//  Post-condition: adds two Complex objects and outputs a third Complex object
//
//-----------------------------------------------------------------------------------
//
//  Complex operator+(float)
//
//  Parameters:     rl, float, represents a real number, passed by value
//  Post-condition: adds two Complex objects and outputs a third Complex object
//
//-----------------------------------------------------------------------------------


//  This class also has the following friend functions
//
//-----------------------------------------------------------------------------------
//
//  Complex operator+(float, Complex)
//
//  Parameters:     rl, float, represents a real number, passed by value
//                  cx, Complex, represents a Complex object, passed by reference
//  Post-condition: adds two Complex objects and outputs a third Complex object
//
//-----------------------------------------------------------------------------------
//
//  Complex operator*(Complex)
//
//  Parameters:     cx, Complex, represents a Complex object, passed by reference
//  Post-condition: multiplies two Complex objects and outputs a third Complex object
//
//-----------------------------------------------------------------------------------
//
//  Complex operator<<(ostream, Complex)
//
//  Parameters:     out, ostream, represents an output stream, passed by reference
//                  cpx, Complex, represents a Complex object, passed by reference
//  Post-condition: overloads output stream and prints to screen
//
//-----------------------------------------------------------------------------------
//
//  Complex operator>>(istream, Complex)
//
//  Parameters:     in, istream, represents an input stream, passed by reference
//                  cpx, Complex, represents a Complex object, passed by reference
//  Post-condition: overloads input stream and takes in data from user
//
//-----------------------------------------------------------------------------------

#include <iostream>
using namespace std;


class Complex{

private:
    float real;
    float imag;

public:
    Complex (float = 0, float = 0);
    const Complex operator+(const Complex &);
    const Complex operator+(float);
    const Complex operator*(const Complex &);
    friend Complex operator+(float, Complex &);
    friend ostream &operator<<(ostream &, Complex &);
    friend istream &operator>>(istream &, Complex &);
};
