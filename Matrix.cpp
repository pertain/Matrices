/*
 * Matrix.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: William Ersing
 *
 *  Creates a dynamic matrix of Complex numbers and
 *  provides matrix arithmetic operations
 */

#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// parameterized constructor
Matrix::Matrix(int row, int col){
	rows = row;
	cols = col;

	matrixArray = new Complex*[rows];
	for(int i = 0; i < rows; i++){
		matrixArray[i] = new Complex[cols];
	}
}

Matrix::~Matrix(){
	for(int i = 0; i < rows; i++){
		delete [] matrixArray[i];
	}
	delete [] matrixArray;
}

Matrix &Matrix::operator=(const Matrix &mx){
	rows = mx.rows;
	cols = mx.cols;
	delete matrixArray;
	matrixArray = new Complex*[mx.rows];
	for(int i = 0; i < mx.rows; i++){
		matrixArray[i] = new Complex[mx.cols];
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			matrixArray[i][j] = mx.matrixArray[i][j];
		}
	}
	return *this;
}

Matrix &Matrix::operator=(const Complex &cx){
	rows = 1;
	cols = 1;
	delete matrixArray;										//	Calls destructor on original matrixArray
	matrixArray = new Complex*[rows];						//	and creates a new matrixArray of size 1
	matrixArray[0] = new Complex[cols];						//	that is populated with the assigned Complex number
	matrixArray[0][0] = cx;
	return *this;
}

const Matrix Matrix::operator+(const Matrix &mx){
	Matrix tempMatrix(rows, cols);
	if(rows == mx.rows && cols == mx.cols){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				tempMatrix.matrixArray[i][j] = matrixArray[i][j] + mx.matrixArray[i][j];
			}
		}
	}
	else{
		cout << "\nUnable to add the matrices because" << endl;
		cout << "they are not the same size\n" << endl;
	}
	return tempMatrix;
}

const Matrix Matrix::operator+(const Complex &cx){
	Matrix tempMatrix(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			tempMatrix.matrixArray[i][j] = matrixArray[i][j] + cx;
		}
	}
	return tempMatrix;
}

const Matrix Matrix::operator*(const Matrix &mx){
	Matrix tempMatrix(rows, mx.cols);
	if(cols == mx.rows){
		int commonSize = cols;
		for(int i = 0; i < rows; i++){
		    for(int j = 0; j < mx.cols; j++){
		        Complex product = 0;
		        for(int k = 0; k < commonSize; k++){
		        	product = product + matrixArray[i][k] * mx.matrixArray[k][j];
		        }
		        tempMatrix.matrixArray[i][j] = product;
		    }
		}
	}
	else{
		cout << "\nThe matrices are not compatible for multiplication\n" << endl;
	}
	return tempMatrix;
}

const Matrix Matrix::operator*(const Complex &cx){
	Matrix tempMatrix(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			tempMatrix.matrixArray[i][j] = matrixArray[i][j] * cx;
		}
	}
	return tempMatrix;
}

Matrix operator+(Complex &cx, Matrix &mx){
	Matrix tempMatrix(mx.rows, mx.cols);
	for(int i = 0; i < mx.rows; i++){
		for(int j = 0; j < mx.cols; j++){
			tempMatrix.matrixArray[i][j] = mx.matrixArray[i][j] + cx;
		}
	}
	return tempMatrix;
}

Matrix operator*(Complex &cx, Matrix &mx){
	Matrix tempMatrix(mx.rows, mx.cols);
	for(int i = 0; i < mx.rows; i++){
		for(int j = 0; j < mx.cols; j++){
			tempMatrix.matrixArray[i][j] = mx.matrixArray[i][j] * cx;
		}
	}
	return tempMatrix;
}


ostream &operator<<(ostream &out, Matrix &mx){
	out << "\n\n";
	for(int i = 0; i < mx.rows; i++){
		for(int j = 0; j < mx.cols; j++){
			out << "\t" << mx.matrixArray[i][j];
		}
		out << "\n\n\n";
	}
	out << "\n";
	return out;
}

istream &operator>>(istream &in, Matrix &mx){
	Complex cpx;
	for(int i = 0; i < mx.rows; i++){
		for(int j = 0; j < mx.cols; j++){
			cout << "Location [" << i << "][" << j << "]? ";
			in >> cpx;
			mx.matrixArray[i][j] = cpx;
		}
	}
	return in;
}


ifstream &operator>>(ifstream &fin, Matrix &mx){
	Complex cpx;
	int numRows, numCols;
	float rl, img;

	if(fin.is_open()){
		fin >> numRows >> numCols;
		mx.rows = numRows;
		mx.cols = numCols;
		delete mx.matrixArray;											//	Calls destructor on the original matrixArray
		mx.matrixArray = new Complex*[numRows];							//	and creates a new matrixArray
		for(int i = 0; i < numRows; i++){								//	Dimensions come from the input file
			mx.matrixArray[i] = new Complex[numCols];
		}
		for(int i = 0; i < numRows; i++){								//	Populates matrixArray with
			for(int j = 0; j < numCols; j++){							//	values from the input file
				fin >> rl >> img;										//
				cpx = Complex(rl, img);									//
				mx.matrixArray[i][j] = cpx;
			}
		}
		fin.close();
	}
	else{
		cout << "Unable to open file" << endl;
	}
	return fin;
}
