#include "Array.h"
#include "../Utils/Utils.h"
#include <random>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"

/** ------------------------------------------- */
/** -------------- GETTERS -------------------- */
unsigned int Array::getRows() const { return rows; }

unsigned int Array::getColumns() const { return columns; }

double **Array::getArray() const { return array; }

/** ------------------------------------------- */
/** ------------- CONSTRUCTORS ---------------- */
Array::Array() {
    rows = columns = 0;
    array = Utils::allocateMemory(rows, columns);
    if (debugEnabled) { std::cout << "#DEBUG# Default constructor was used" << std::endl; }
}

Array::Array(const unsigned int rows, const unsigned int columns): rows(rows), columns(columns) {
    array = Utils::allocateMemory(rows, columns);
    if (debugEnabled) { std::cout << "#DEBUG# Fixed array size constructor was used" << std::endl; }
}

Array::Array(
        double **originalArray,
        const unsigned int rows,
        const unsigned int columns) : rows(rows), columns(columns)
{
    array = Utils::allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = originalArray[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG The fixed array constructor was used" << std::endl; }
}

Array::Array(const Array &originalArray): rows(originalArray.getRows()), columns(originalArray.getColumns()) {
    array = Utils::allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = originalArray.getArray()[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG# Copy constructor was used" << std::endl; }
}

/** ------------------------------------------- */
/** -------------- DESTRUCTORS ---------------- */
Array::~Array() {
    Utils::freeMemory(array, rows);
    array = nullptr;
    if (debugEnabled) { std::cout << "#DEBUG# Array object was destroyed" << std::endl; }
}

/** ------------------------------------------- */
/** -------------- PUBLIC METHODS ------------- */
void Array::printArray() {
    if (debugEnabled) { std::cout << "#DEBUG# Printing array" << std::endl; }
    if (rows) {
        for (int i = 0; i < rows; ++i) {
            std::cout << "Row " << i << " -> ";
            if (columns) {
                for (int j = 0; j < columns; ++j) {
                    std::cout << array[i][j] << " ";
                }
            } else {
                std::cout << "EMPTY";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "EMPTY ARRAY" << std::endl;
    }
}

void Array::changeArraySize(const unsigned int newRows, const unsigned int newColumns) {
    if (rows && columns) {
        double **tempArray = Utils::allocateMemory(newRows, newColumns);;
        unsigned int x = rows > newRows ? newRows : rows;
        unsigned int y = columns > newColumns ? newColumns : columns;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                tempArray[i][j] = array[i][j];
            }
        }

        rows = newRows;
        columns = newColumns;
        array = Utils::allocateMemory(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                array[i][j] = tempArray[i][j];
            }
        }

        Utils::freeMemory(tempArray, newRows);

    } else {
        rows = newRows;
        columns = newColumns;
        array = Utils::allocateMemory(rows, columns);
        if (debugEnabled) { std::cout << "#DEBUG# Array rows (columns) was 0. Creating new array" << std::endl; }
    }
}

double **Array::generateRandomArray(const unsigned int rows, const unsigned int columns) {
    double **ptr = Utils::allocateMemory(rows, columns);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            ptr[i][j] = dis(gen);
        }
    }
    return ptr;
}

/** ------------------------------------------- */
/** ----------- OVERLOADED OPERATORS ---------- */
Array &Array::operator=(const Array &other) {
    Utils::freeMemory(array, rows);
    rows = other.getRows();
    columns = other.getColumns();
    array = Utils::allocateMemory(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = other.getArray()[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG# operator= was used" << std::endl; }
    return *this;
}

Array &Array::operator+() {
    if (debugEnabled) { std::cout << "#DEBUG# unary operator+ was used" << std::endl; }
    return *this;
}

Array &Array::operator-() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = -array[i][j];
        }
    }
    if (debugEnabled) { std::cout << "#DEBUG# unary operator- was used" << std::endl; }
    return *this;
}

Array &Array::operator+=(const Array &other) {
    Utils::compareArraysSizes(*this, other);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] += other.getArray()[i][j];
        }
    }
    return *this;
}

Array &Array::operator-=(const Array &other) {
    Utils::compareArraysSizes(*this, other);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] -= other.getArray()[i][j];
        }
    }
    return *this;
}

Array &Array::operator*=(const unsigned int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] *= value;
        }
    }
}

double Array::operator()(const unsigned int row, const unsigned int column) {
    if (rows == 0 || columns == 0) {
        std::cout << "Empty array. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    } else if (row > rows - 1 || column > columns - 1) {
        std::cout << "Invalid index. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return array[row][column];
}

double *Array::operator[](const unsigned int value) {
    return array[value];
}

Array &Array::operator*=(const Array &other) {
    if (!rows || !other.getColumns() || !columns || !other.getColumns()) {
        std::cout << "Operator+ -> Arrays have NULL fields. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (columns != other.getRows()) {
        std::cout << "Array1 rows != array2 columns. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
    double **tempArray = Utils::allocateMemory(rows, other.getColumns());
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < other.getColumns(); ++j) {
            for(int k = 0; k < columns; ++k) {
                tempArray[i][j] += array[i][k] * other.getArray()[k][j];
            }
        }
    }

    changeArraySize(rows, other.getColumns());
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.getColumns(); ++j) {
            array[i][j] = tempArray[i][j];
        }
    }

    Utils::freeMemory(tempArray, rows);
    return *this;
}


#pragma clang diagnostic pop