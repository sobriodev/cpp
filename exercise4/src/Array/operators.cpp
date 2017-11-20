#include <cstdlib>
#include <iostream>
#include "operators.h"
#include "../Utils/Utils.h"

Array operator+(const Array &array1, const Array &array2) {
    Utils::compareArraysSizes(array1, array2);
    Array res(array1.getRows(), array1.getColumns());

    for (int i = 0; i < res.getRows(); ++i) {
        for (int j = 0; j < res.getColumns(); ++j) {
            res.getArray()[i][j] = array1.getArray()[i][j] + array2.getArray()[i][j];
        }
    }
    if (Array::debugEnabled) { std::cout << "#DEBUG# binary operator+ was used" << std::endl; }
    return res;
}

Array operator-(const Array &array1, const Array &array2) {
    Utils::compareArraysSizes(array1, array2);
    Array res(array1.getRows(), array1.getColumns());

    for (int i = 0; i < res.getRows(); ++i) {
        for (int j = 0; j < res.getColumns(); ++j) {
            res.getArray()[i][j] = array1.getArray()[i][j] - array2.getArray()[i][j];
        }
    }
    if (Array::debugEnabled) { std::cout << "#DEBUG# binary operator+ was used" << std::endl; }
    return res;
}

Array operator*(const Array &array, const double value) {
    Array res(array.getRows(), array.getColumns());
    for (int i = 0; i < res.getRows(); ++i) {
        for (int j = 0; j < res.getColumns(); ++j) {
            res.getArray()[i][j] = array.getArray()[i][j] * value;
        }
    }
    return res;
}

bool operator==(const Array &array1, const Array &array2) {
    if (array1.getRows() != array2.getRows() || array1.getColumns() != array2.getColumns()) {
        return false;
    }

    for (int i = 0; i < array1.getRows(); ++i) {
        for (int j = 0; j < array1.getColumns(); ++j) {
            if (array1.getArray()[i][j] != array2.getArray()[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Array &array1, const Array &array2) {
    return !(array1 == array2);
}

std::ostream &operator<<(std::ostream &os, const Array &array) {
    if (Array::debugEnabled) { std::cout << "#DEBUG# Printing array" << std::endl; }
    if (array.getRows()) {
        for (int i = 0; i < array.getRows(); ++i) {
            std::cout << "Row " << i << " -> ";
            if (array.getColumns()) {
                for (int j = 0; j < array.getColumns(); ++j) {
                    std::cout << array.getArray()[i][j] << " ";
                }
            } else {
                std::cout << "EMPTY";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "EMPTY ARRAY" << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Array &array) {
    unsigned int rows, columns;
    std::cout << "Enter number of rows: ";
    is >> rows;
    std::cout << "Enter number of columns: ";
    is >> columns;
    array.changeArraySize(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << "Enter value for array[" << i << "][" << j << "]: ";
            is >> array.getArray()[i][j];
        }
    }
    return is;
}

Array operator*(const Array &array1, const Array &array2) {
    if (!array1.getRows() || !array1.getColumns() || !array2.getRows() || !array2.getColumns()) {
        std::cout << "Operator+ -> Arrays have NULL fields. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (array1.getColumns() != array2.getRows()) {
        std::cout << "Array1 rows != array2 columns. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
    Array res(array1.getRows(), array2.getColumns());
    for(int i = 0; i < array1.getRows(); ++i) {
        for(int j = 0; j < array2.getColumns(); ++j) {
            for(int k = 0; k < array1.getColumns(); ++k) {
                res.getArray()[i][j] += array1.getArray()[i][k] * array2.getArray()[k][j];
            }
        }
    }
    return res;
}

