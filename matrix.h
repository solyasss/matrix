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
    Matrix() = default;
    Matrix(T **array, int rows, int cols);
    ~Matrix();

    void input();
    void print();

    Matrix(initializer_list<T> param);
};
