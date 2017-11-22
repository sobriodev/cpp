#include "Array/Array.h"
#include "Utils/Utils.h"
#include "Array/operators.h"

int main() {
    const unsigned int rows = 3;
    const unsigned int columns = 4;
    double **ptr = Utils::allocateMemory(rows, columns, 2);
    double **ptr2 = Utils::allocateMemory(columns, rows, 3);

    Array array(ptr, rows, columns);
    Array array2(ptr2, columns, rows);
    std::cout << (array *= array2);

    Utils::freeMemory(ptr, rows);
    Utils::freeMemory(ptr2, columns);

    return 0;
}