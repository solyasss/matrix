#include "Matrix.h"
#include <iostream>
using namespace std;

template <class T>
Matrix<T>::Matrix(initializer_list<T> param)
{
    rows = 1;
    cols = param.size();
    array = new T *[rows];
    array[0] = new T[cols];

    auto it = param.begin();
    for (int j = 0; j < cols; ++j, ++it)
    {
        array[0][j] = *it;
    }
}

template <class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

template <class T>
void Matrix<T>::input()
{
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter elements like this (" << i << ")(" << j << "): ";
            cin >> array[i][j];
        }
    }
}

template <class T>
void Matrix<T>::print()
{
    cout << "Your matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}
