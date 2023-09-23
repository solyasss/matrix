#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int rows = 5;
    int cols = 10;
    int **st = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        st[i] = new int[cols];
    }

    Matrix<int> int_matrix(st, rows, cols);
    int_matrix.input();
    int_matrix.print();

    delete[] st;

    Matrix<int> int_matrix2 = {1, 11, 22, 33, 44};
    int_matrix2.print();

    return 0;
}