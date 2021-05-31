//  matrixDriver.cpp
//  
//  Driver to test implementation of the Matrix class
//
//  Submitted by:   William Ersing
//  Course:         CSC 415
//  Semester:       Fall 2013

#include "Matrix.h"
#include <iostream>
#include <fstream>

int main ()
{
    Matrix m1, m2, m3, m4, m5, m6;
    std::ifstream inStr1a, inStr1, inStr2, inStr3, inStr5;
    Complex number (5.2, 3.4);
    std::string infilename;

    //Test overloaded stream insertion and extraction operators
    std::cout << "Opening Matrix 1 from file" << std::endl;
    std::cin >> infilename;
    inStr1a.open (infilename.c_str());
    inStr1a >> m1;
    std::cout << "Matrix 1a is " << m1 << std::endl;
    inStr1a.close();


    // Test overloaded assignment operator
    std::cout << "After assigning m1 to m4, m4 is: " << std::endl;
    m4 = m1;
    std::cout << m4 << std::endl;

    std::cout << "Re-enter Matrix 1 from a file" << std::endl;
    std::cin >> infilename;
    inStr1.open (infilename.c_str());
    inStr1 >> m1;
    std::cout << "Matrix 1 is " << std::endl << m1 << std::endl;
    inStr1.close();


    // Test if Matrix 4 is impacted by the change in Matrix 1
    std::cout << "Matrix 4 is now: " << std::endl;
    std::cout << m4 << std::endl;

    std::cout << "Enter Matrix 2 from a file" << std::endl;
    std::cin >> infilename;
    inStr2.open (infilename.c_str());
    inStr2 >> m2;
    std::cout << "Matrix 2 is " << std::endl << m2 << std::endl;
    inStr2.close();

    std::cout << "Enter larger Matrix 3 from a file" << std::endl;
    std::cin >> infilename;
    inStr3.open (infilename.c_str());
    inStr3 >> m3;
    std::cout << "Matrix 3 is " << m3 << std::endl;
    inStr3.close();


    // Test overloaded plus operator
    std::cout << "Adding compatible Matrix 1 and Matrix 2 gives:" << std::endl;
    m3 = m1 + m2;
    std::cout << m3 << std::endl;

    std::cout << "Adding incompatible Matrix 4 and Matrix 2 gives:" << std::endl;
    m3 = m4 + m2;
    std::cout << m3 << std::endl;

    std::cout << "Adding Matrix 1 and number gives:" << std::endl;
    m3 = m1 + number;
    std::cout << m3 << std::endl;

    std::cout << "Adding number and Matrix 2 gives:" << std::endl;
    m3 = number + m2;
    std::cout << m3 << std::endl;


    // Test overloaded multiplication operator
    std::cout << "Enter Matrix 5 from a file" << std::endl;
    std::cin >> infilename;
    inStr5.open (infilename.c_str());
    inStr5 >> m5;
    std::cout << "Matrix 5 is " << std::endl << m5 << std::endl;
    inStr5.close();

    std::cout << "Multiplying compatible Matrix 1 and Matrix 5 gives:" << std::endl;
    m6 = m1 * m5;
    std::cout << m6 << std::endl;

    std::cout << "Multiplying incompatible Matrix 4 and Matrix 5 gives:" << std::endl;
    m6 = m4 * m5;
    std::cout << m6 << std::endl;

    std::cout << "Multiplying Matrix 1 and number gives:" << std::endl;
    m6 = m1 * number;
    std::cout << m6 << std::endl;

    std::cout << "Multiplying number and Matrix 5 gives:" << std::endl;
    m6 = number * m5;
    std::cout << m6 << std::endl;

    std::cout << "Testing m1 = m1 " << std::endl;
    m1 = m1;
    std::cout << "Matrix 1 is " << std::endl << m1 << std::endl;

    std::cout << "Testing copy constructor " << std::endl;
    Matrix m7(m2);
    std::cout << "Matrix 7 is " << std::endl << m7 << std::endl;


    // Test if Matrix 2 is impacted by the change in Matrix 7
    m7 = m7 * number;
    std::cout << "Matrix 7 is now: " << std::endl;
    std::cout << m7 << std::endl;
    std::cout << "Matrix 2 is now: " << std::endl;
    std::cout << m2 << std::endl;
    std::cout << "Bye!" << std::endl << std::endl;    

    return 0;
}
