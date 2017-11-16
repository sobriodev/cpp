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

#pragma clang diagnostic pop