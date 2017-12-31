#include "Memory.h"

double *Memory::malloc(unsigned length) {
    return !length ? nullptr : new double[length];
}

void Memory::free(const double *array) {
    delete[] array;
}
