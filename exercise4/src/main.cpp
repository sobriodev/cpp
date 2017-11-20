#include "Array/Array.h"
#include "Utils/Utils.h"
#include "Array/operators.h"

int main() {
    const unsigned int rows = 1;
    const unsigned int columns = 2;
    double **ptr = Utils::allocateMemory(rows, columns, 12);

    Array array(ptr, rows, columns);
    std::cout << array(0,1) << std::endl;

    Utils::freeMemory(ptr, rows);

    return 0;
}