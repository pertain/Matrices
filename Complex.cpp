/*
 * Complex.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: William Ersing
 *
 *  Creates Complex number objects and provides basic
 *  operations for complex numbers
 */

#include "Complex.h"
#include <iostream>
#include <iomanip>
using namespace std;


// parameterized constructor
Complex::Complex (float left, float right){
    real = left;
    imag = right;
}

const Complex Complex::operator+(const Complex &cx){
    return Complex(real + cx.real, imag + cx.imag);
}

const Complex Complex::operator+(float rl){
    return Complex(real + rl, imag);
}

const Complex Complex::operator*(const Complex &cx){
    Complex tempComplex;
    float x, y, a, b;
    x = real;
    y = imag;
    a = cx.real;
    b = cx.imag;
    tempComplex.real = (x * a) - (y * b);
    tempComplex.imag = (x * b) + (y * a);
    return tempComplex;
}

Complex operator+(float rl, Complex &cx){
    return Complex(cx.real + rl, cx.imag);
}

istream &operator>>(istream &in, Complex &cpx){
    in >> cpx.real >> cpx.imag;
    return in;
}

ostream &operator<<(ostream &out, Complex &cpx){
    out << setw(2) << fixed << setprecision(1);
    if(cpx.imag == 0){
        return out << cpx.real << "\t";
    }
    else{
        if(cpx.real == 0){
            return out << cpx.imag << "i\t";
        }
        else{
            if(cpx.imag < 0){
                return out << cpx.real << " - " << ((-1)*cpx.imag) << "i";
            }
            else{
                return out << cpx.real << " + " << cpx.imag << "i";
            }
        }
    }
}
