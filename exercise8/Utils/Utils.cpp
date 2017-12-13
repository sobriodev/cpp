#include "Utils.h"

double *Utils::malloc(unsigned length) {
    return !length ? nullptr : new double[length];
}

void Utils::free(const double *vector) {
    delete[] vector;
}
