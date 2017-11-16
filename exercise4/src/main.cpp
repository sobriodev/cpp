#include <iostream>
#include <cstring>
#include "Array/Array.h"
#include "Utils/Utils.h"

int main() {
    unsigned int rows = 3, columns = 4;
    double **ptr = Utils::allocateMemory(rows, columns, 4);

    Array a2(ptr, rows, columns);
    a2.printArray();
    std::cout << "---" << std::endl;
    a2.changeArraySize(12, 12);
    a2.printArray();

    Utils::freeMemory(ptr, rows);
    return 0;
}