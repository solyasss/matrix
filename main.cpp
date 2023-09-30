#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int rows = 5;
    int cols = 5;
    int **ptr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        ptr[i] = new int[cols];
    }

    Matrix<int> int_matrix(ptr, rows, cols);
    int_matrix.input();
    int_matrix.print();

    delete[] ptr;

    Matrix<int> int_matrix2 = {{1, 11, 22, 33, 44},
                               {2, 12, 23, 34, 45},
                               {3, 13, 24, 35, 46},
                               {4, 14, 25, 36, 47},
                               {5, 15, 26, 37, 48}};

    int_matrix2.print();

    if (int_matrix.add(int_matrix2))
    {
        Matrix<int> int_matrix3 = int_matrix + int_matrix2;
        int_matrix3.print();
    }
    else
    {
        cout << "Do not match this" << endl;
    }

    if (int_matrix.subtract(int_matrix2))
    {
        Matrix<int> int_matrix4 = int_matrix - int_matrix2;
        int_matrix4.print();
    }
    else
    {
        cout << " Do not match this" << endl;
    }

    if (int_matrix.multiply(int_matrix2))
    {
        Matrix<int> int_matrix5 = int_matrix * int_matrix2;
        int_matrix5.print();
    }
    else
    {
        cout << "Do not match this" << endl;
    }

    cout << "Max: " << int_matrix.max() << endl;
    cout << "Min: " << int_matrix.min() << endl;

    Matrix<int> int_matrix6 = int_matrix2.inverse();
    if (!int_matrix6.empty())
    {
        Matrix<int> int_matrix7 = int_matrix * int_matrix6;
        int_matrix7.print();
    }
    else
    {
        cout << "Inverse matrix do not match this" << endl;
    }

    Matrix<int> int_matrix8 = int_matrix / int_matrix2;
    int_matrix8.print();

    return 0;
}
