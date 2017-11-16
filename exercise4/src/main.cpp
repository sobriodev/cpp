#include "Array/Array.h"

int main() {
    unsigned int rows = 5, columns = 3;
    double **ptr = Array::generateRandomArray(rows, columns);
    Array a(ptr, rows, columns);
    a.printArray();
    a.changeArraySize(0, 0);
    a.printArray();



    return 0;
}