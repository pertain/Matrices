/*
 * Matrix.h
 *
 *  Created on: Nov 22, 2013
 *      Author: William Ersing
 *
 *  Creates dynamic matrix arrays that hold Complex numbers
 *  and provides Matrix arithmetic operations
 */

//  This class has the following member functions
//
//-----------------------------------------------------------------------------------
//
//  Matrix(int, int)
//
//  Parameters:     rows, int, represents the number of rows in the Matrix, passed by value
//                  cols, int, represents the number of columns in the Matrix, passed by value
//
//-----------------------------------------------------------------------------------
//
//  ~Matrix()
//
//  Parameters:     Destructor for Matrix
//  Post-condition: Deallocates memory dynamically assigned by Matrix arrays
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator=(Matrix)
//
//  Parameters:     mx, Matrix, represents the Matrix to be assigned, passed by reference
//  Post-condition: Overloads assignment operator and allows a Matrix to be assigned to another Matrix
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator=(Complex)
//
//  Parameters:     cx, Complex, represents a Complex number, passed by reference
//  Post-condition: Overloads assignment operator and allows a Complex to be assigned to a Matrix
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator+(Matrix)
//
//  Parameters:     mx, Matrix, represents a Matrix to be added to calling Matrix, passed by reference
//  Post-condition: adds two Matrix objects and outputs a third Matrix object
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator+(Complex)
//
//  Parameters:     cx, Complex, represents a Complex to be added to calling Matrix, passed by reference
//  Post-condition: adds a Complex to a Matrix and outputs an additional Matrix object
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator*(Matrix)
//
//  Parameters:     mx, Matrix, represents a Matrix to be multiplied by calling Matrix, passed by reference
//  Post-condition: Multiplies two Matrix objects and outputs a third Matrix object
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator*(Complex)
//
//  Parameters:     cx, Complex, represents a Complex to be multiplied by calling Matrix, passed by reference
//  Post-condition: adds two Complex objects and outputs a third Complex object
//
//-----------------------------------------------------------------------------------


//  This class also has the following friend functions
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator+(Complex, Matrix)
//
//  Parameters:     cx, Complex, represents a Complex number, passed by reference
//                  mx, Matrix, represents a Matrix object, passed by reference
//  Post-condition: adds a Complex and a Matrix and outputs an additional Matrix object
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator*(Complex, Matrix)
//
//  Parameters:     cx, Complex, represents a Complex number, passed by reference
//                  mx, Matrix, represents a Matrix object, passed by reference
//  Post-condition: multiplies a Complex and a Matrix and outputs an additional Matrix object
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator<<(ostream, Matrix)
//
//  Parameters:     out, ostream, represents an output stream, passed by reference
//                  mx, Matrix, represents a Matrix object, passed by reference
//  Post-condition: overloads output stream and prints to screen
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator>>(istream, Matrix)
//
//  Parameters:     in, istream, represents an input stream, passed by reference
//                  mx, Matrix, represents a Matrix object, passed by reference
//  Post-condition: overloads input stream and takes in data from user
//
//-----------------------------------------------------------------------------------
//
//  Matrix operator>>(istream, Matrix)
//
//  Parameters:     fin, ifstream, represents an input stream, passed by reference
//                  mx, Matrix, represents a Matrix object, passed by reference
//  Post-condition: overloads input file stream and takes reads in data from a file
//
//-----------------------------------------------------------------------------------



#include "Complex.h"
#include <iostream>
using namespace std;

class Matrix{

private:
    int rows;
    int cols;
    Complex **matrixArray;

public:
    Matrix(int = 3, int = 4);
    ~Matrix();
    Matrix &operator=(const Matrix &);
    Matrix &operator=(const Complex &);
    const Matrix operator+(const Matrix &);
    const Matrix operator+(const Complex &);
    const Matrix operator*(const Matrix &);
    const Matrix operator*(const Complex &);
    friend Matrix operator+(Complex &, Matrix &);
    friend Matrix operator*(Complex &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix &);
    friend istream &operator>>(istream &, Matrix &);
    friend ifstream &operator>>(ifstream &, Matrix &);
};
