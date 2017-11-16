#include <iostream>
#include <random>
#include "Array.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"

double **Array::allocateMemory(
        const unsigned int rows,
        const unsigned int columns,
        const double value)
{
    auto **pointer = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        pointer[i] = new double[columns];
    }
    setValues(pointer, rows, columns, value);
    return pointer;
}

double **Array::generateArray(const unsigned int rows, const unsigned int columns) {
    double **res = allocateMemory(rows, columns);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            res[i][j] = dis(gen);
        }
    }

    if (debugEnabled) { std::cout << "Generating random array (Array" << rows << "x" << columns << ")" << std::endl; }
    return res;
}

void Array::freeMemory(double **pointer, const unsigned int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] pointer[i];
    }
    delete[] pointer;
    if (debugEnabled) { std::cout << "#DEBUG Free memory (Array -> " << rows << ")" <<  std::endl; }
}

void Array::printArray(double **pointer, const unsigned int rows, const unsigned int columns) {
    if (debugEnabled) { std::cout << "#DEBUG Printing array (Array " << rows << "x" << columns << ")" << std::endl; }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << "Array[" << i << "][" << j <<"] = " << pointer[i][j] << std::endl;
        }
    }
}

void Array::printArray() {
    printArray(array, rows, columns);
}

void Array::setValues(
        double **pointer,
        const unsigned int rows,
        const unsigned int columns,
        const double value)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            pointer[i][j] = value;
        }
    }
}

/*************************************************/
/*************** Constructors *******************/

Array::Array() {
    rows = columns = 0;
    array = nullptr;
    if (debugEnabled) { std::cout << "#DEBUG The default constructor (Array 0x0) was used" << std::endl; }
}

Array::Array(const unsigned int rows, const unsigned int columns): rows(rows), columns(columns) {
    array = allocateMemory(rows, columns);
    if (debugEnabled) { std::cout << "#DEBUG The fixed array size constructor (Array " << rows << "x" << columns << ") was used" << std::endl; }
}

Array::Array(double **originalArray, const unsigned int rows, const unsigned int columns): rows(rows), columns(columns) {
    array = allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = originalArray[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG The fixed array constructor (Array " << rows << "x" << columns << ") was used" << std::endl; }
}

Array::~Array() {
    freeMemory(array, rows);
}

Array::Array(Array &originalArray): rows(originalArray.getRows()), columns(originalArray.getColumns()) {
    array = allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = originalArray.getArray()[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG The copy constructor (Array " << rows << "x" << columns << ") was used" << std::endl; }
}

unsigned int Array::getRows() const {
    return rows;
}

unsigned int Array::getColumns() const {
    return columns;
}

double **Array::getArray() const {
    return array;
}

void Array::changeSize(const unsigned int rows, const unsigned int columns) {
    freeMemory(array, this->rows);
    array = allocateMemory(rows, columns);
    this->rows = rows;
    this->columns = columns;
    if (debugEnabled) { std::cout << "#DEBUG Change array size to Array " << rows << "x" << columns << std::endl; }
}

Array &Array::operator=(const Array &a) {
    freeMemory(array, rows);
    allocateMemory(a.getRows(), a.getColumns());
    rows = a.getRows();
    columns = a.getColumns();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = a.getArray()[i][j];
        }
    }
    return *this;
}

/* overloaded operators */



#pragma clang diagnostic pop