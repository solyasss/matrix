#include "matrix.h"
#include <iostream>

using namespace std;

template <class T>
Matrix<T>::Matrix() : array(nullptr), rows(0), cols(0) {}

template <class T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    array = new T *[rows];
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new T[cols];
    }
}

template <class T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> param)
{
    rows = param.size();
    cols = param.begin()->size();
    array = new T *[rows];
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new T[cols];
        auto it = param.begin();
        advance(it, i);
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = *(it->begin() + j);
        }
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

template <class T>
bool Matrix<T>::dimensions_equal(const Matrix<T> &obj)
{
    return (rows == obj.rows && cols == obj.cols);
}

template <class T>
bool Matrix<T>::add(const Matrix<T> &obj)
{
    return dimensions_equal(obj);
}

template <class T>
bool Matrix<T>::subtract(const Matrix<T> &obj)
{
    return dimensions_equal(obj);
}

template <class T>
bool Matrix<T>::multiply(const Matrix<T> &obj)
{
    return (cols == obj.rows);
}

template <class T>
T Matrix<T>::max()
{
    T max_ptr = array[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (array[i][j] > max_ptr)
            {
                max_ptr = array[i][j];
            }
        }
    }
    return max_ptr;
}

template <class T>
T Matrix<T>::min()
{
    T min_ptr = array[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (array[i][j] < min_ptr)
            {
                min_ptr = array[i][j];
            }
        }
    }
    return min_ptr;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &obj)
{
    if (!add(obj))
    {
        cout << "Do not match this" << endl;
        return *this;
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.array[i][j] = array[i][j] + obj.array[i][j];
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &obj)
{
    if (!subtract(obj))
    {
        cout << "Do not match this" << endl;
        return *this;
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.array[i][j] = array[i][j] - obj.array[i][j];
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &obj)
{
    if (!multiply(obj))
    {
        cout << "Do not match this" << endl;
        return *this;
    }

    Matrix<T> result(rows, obj.cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < obj.cols; ++j)
        {
            result.array[i][j] = 0;
            for (int k = 0; k < cols; ++k)
            {
                result.array[i][j] += array[i][k] * obj.array[k][j];
            }
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> &obj)
{
    Matrix<T> result(rows, obj.cols);
    Matrix<T> inverse = obj.inverse();

    if (!multiply(inverse))
    {
        cout << "Do not match this" << endl;
        return *this;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < obj.cols; ++j)
        {
            result.array[i][j] = 0;
            for (int k = 0; k < cols; ++k)
            {
                result.array[i][j] += array[i][k] * inverse.array[k][j];
            }
        }
    }
    return result;
}

template <class T>
bool Matrix<T>::empty() const
{
    return (array == nullptr);
}
