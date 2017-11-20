#include "Utils.h"

double **Utils::allocateMemory(unsigned int rows, unsigned int columns, const double value) {
    if (rows) {
        auto **ptr = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            ptr[i] = !columns ? nullptr : new double[columns];
            for (int j = 0; j < columns; ++j) {
                ptr[i][j] = value;
            }
        }
        return ptr;
    } else {
        return nullptr;
    }
}

void Utils::freeMemory(double **ptr, const unsigned int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void Utils::compareArraysSizes(const Array &array1, const Array &array2) {
    if (array1.getRows() != array2.getRows() || array1.getColumns() != array2.getColumns()) {
        std::cout << "Operator+ -> Arrays do not have the same sizes. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    } else if (!array1.getRows() || !array1.getColumns() || !array2.getRows() || !array2.getColumns()) {
        std::cout << "Operator+ -> Arrays have NULL fields. Aborting!" << std::endl;
        exit(EXIT_FAILURE);
    }
}
