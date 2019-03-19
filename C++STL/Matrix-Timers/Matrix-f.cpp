//
// Created by Leszek on 2018-10-23.
//
#include "Matrix.h"

Matrix::Matrix() {
    a.push_back(std::vector<double>(1));
    a[0][0] = 0;
    size = 1;
}

Matrix::Matrix(const int n){
        srand(time(nullptr));
        std::vector<double> tmp ;
        for (int j=0; j<n; j++){
            for (int i=0; i<n; i++) {
                tmp.push_back(rand()/(RAND_MAX/1.5)+0.5);
            }
            a.push_back(tmp);
            tmp.clear();
        }
        size = n;
    }

std::vector<double> & Matrix::operator[](const int index){
    return a[index];
}

void Matrix::zero() {
    a.clear();
    std::vector<double> tmp(size, 0);
    for(int i=0; i<size; i++) {
        a.push_back(tmp);
    }
}

void Matrix::write() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << a[j][i] << " ";
        std::cout << std::endl;
    }
}

int Matrix::getSize() const {
    return size;
}

Matrix Matrix::mult(Matrix &A, Matrix &B) {
    Matrix tmp(A.getSize());
    tmp.zero();
    int i=0;
    for(int d=0; d<A.getSize(); d++){
        for (int j=0; j < A.getSize(); j++) {
            for (int n=0; n < A.getSize(); n++) {
                tmp[j][i] += A[n][i] * B[j][n];
            }
        }
        i++;
    }
    return tmp;
}
