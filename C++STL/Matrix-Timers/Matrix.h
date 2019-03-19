//
// Created by Bartek on 2018-10-22.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#ifndef MACIERZE_MATRIX_H
#define MACIERZE_MATRIX_H

class Matrix {

private:
    std::vector<std::vector<double>> a;
    int size;
    
public:
    //Object

    //constructors
    Matrix();
    Matrix(const int n);
    Matrix(const Matrix&) = default;
    //operators
    std::vector<double> & operator[](const int index);
    Matrix& operator=(Matrix&) = default;
    Matrix& operator=(Matrix&&) = default;
    Matrix& operator=(const Matrix&) = default;
    //methods
    void write();
    //getter
    int getSize() const;
    //setter
    void zero();

    //Class

    //methods
    static Matrix mult(Matrix& A, Matrix & B);
};

#endif //MACIERZE_MATRIX_H
