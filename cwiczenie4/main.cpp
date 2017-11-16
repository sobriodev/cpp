#include <iostream>
#include "Array.h"

int main() {
//    Array array1;
//    array1.printArray();
//
//    Array array2(5, 6);
//    array2.printArray();
//
//    double **arr = Array::allocateMemory(2, 7);
//    Array::setValues(arr, 2, 7, 171);
//    Array array3(arr, 2, 7);
//    array3.printArray();
//
//    Array array4 = array3;
//    array3.printArray();
//
//    array3.changeSize(8, 8);
//    array3.printArray();
//
//    double **arr2 = Array::generateArray(6, 9);
//    Array::printArray(arr2, 6, 9);
//    Array::freeMemory(arr2, 6);

    double **ptr = Array::generateArray(3, 2);
    Array a1(ptr, 3, 2);
    Array a2(5, 6);
    a2.printArray();
    Array a3(5, 6);
    a3 = a1;
    a3.printArray();


    return 0;
}