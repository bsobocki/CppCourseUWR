#include "Matrix.h"
#include <chrono>

int main() {

    //test of the multiplication

    Matrix A(3);
    Matrix B(3);
    A[0][0] = 3, A[0][1] = 7, A[0][2] = 1, A[1][0] = 2, A[1][1] = 2, A[1][2] = 1, A[2][0] = 1, A[2][1] = 0, A[2][2] = 1;
    B[0][0] = 4, B[0][1] = 0, B[0][2] = 7, B[1][0] = 3, B[1][1] = 0, B[1][2] = 1, B[2][0] = 2, B[2][1] = 7, B[2][2] = 1;

    Matrix C(Matrix::mult(A,B));

    //A.write();
    //std::cout<<"  *"<<std::endl;
    //B.write();
    //std::cout<<"  ="<<std::endl;
    //C.write();

    Matrix a(10), b(100), c(1000), d(10000);

    //test of the time

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    std::chrono::duration<double> seconds;

    //10x10
    start = std::chrono::high_resolution_clock::now();
    for(int i=1; i<10000; i++) {
        Matrix::mult(a, a);
    }
    end = std::chrono::high_resolution_clock::now();
    seconds = end - start;
    std::cout<<"time for 10x10 : "<<seconds.count()/10000<<std::endl;

    //100x100
    start = std::chrono::high_resolution_clock::now();
    for(int i=1; i<1000; i++) {
        Matrix::mult(b, b);
    }
    end = std::chrono::high_resolution_clock::now();
    seconds = end - start;
    std::cout<<"time for 100x100 : "<<seconds.count()/1000<<std::endl;

    //1000x1000
    start = std::chrono::high_resolution_clock::now();
    Matrix::mult(c, c);
    end = std::chrono::high_resolution_clock::now();
    seconds = end - start;
    std::cout<<"time for 1000x1000 : "<<seconds.count()<<std::endl;

    return 0;
}
