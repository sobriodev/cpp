#include <iostream>
#include "Matrix.h"

int main() {

    const unsigned int ROWS = 3;
    const unsigned int COLUMNS = 6;
    auto **originalMatrix = new double*[ROWS];
    for (int i = 0; i < ROWS; ++i) { originalMatrix[i] = new double[COLUMNS]; }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; j++) { originalMatrix[i][j] = i * j; }
    }

    Matrix m(originalMatrix, ROWS, COLUMNS);
    originalMatrix = Matrix::generateMatrix(3, 6);
    Matrix m2(originalMatrix, 3, 6);
    m2.printMatrix();

    for (int i = 0; i < ROWS; ++i) { delete[] originalMatrix[i]; }
    delete[] originalMatrix;
    originalMatrix = nullptr;

    return 0;
}