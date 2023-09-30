#pragma once
#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    T **array;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(initializer_list<initializer_list<T>> param);
    ~Matrix();

    void input();
    void print();
    bool dimensions_equal(const Matrix<T> &obj);

    bool add(const Matrix<T> &obj);
    bool subtract(const Matrix<T> &obj);
    bool multiply(const Matrix<T> &obj);

    T max();
    T min();

    Matrix<T> inverse() const;

    Matrix<T> operator+(const Matrix<T> &obj);
    Matrix<T> operator-(const Matrix<T> &obj);
    Matrix<T> operator*(const Matrix<T> &obj);
    Matrix<T> operator/(const Matrix<T> &obj);

    bool empty() const;
};
