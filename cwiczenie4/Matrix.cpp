#include <iostream>
#include <random>
#include "Matrix.h"

Matrix::Matrix() {
    rows = 0;
    columns = 0;
    matrix = nullptr;
}

Matrix::~Matrix() {
    freeMemory();
}

Matrix::Matrix(unsigned int rows, unsigned int columns): rows(rows), columns(columns) {
    allocateMemory(rows, columns);
}

Matrix::Matrix(double **originalMatrix, unsigned int rows, unsigned int columns): rows(rows), columns(columns) {
    allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) { matrix[i][j] = originalMatrix[i][j]; }
    }
}

void Matrix::allocateMemory(unsigned int rows, unsigned int columns) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) { matrix[i] = new double[columns]; }
}

void Matrix::freeMemory() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

void Matrix::printMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << "Matrix[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
        }
    }
}

unsigned int Matrix::getRows() {
    return rows;
}

unsigned int Matrix::getColumns() {
    return columns;
}

double **Matrix::generateMatrix(unsigned int rows, unsigned int columns) {
    auto **res = new double*[rows];
    for (int i = 0; i < rows; ++i) { res[i] = new double[columns]; }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1.0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            res[i][j] = dis(gen);
        }
    }

    return res;
}
