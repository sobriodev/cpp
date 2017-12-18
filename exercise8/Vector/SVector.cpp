#include <iostream>
#include "SVector.h"
#include "../Utils/Utils.h"

void SVector::sort() {
    if (length) {
        std::qsort(vector, length, sizeof(double), &compareValues);
    }
}

int SVector::compareValues(const void *first, const void *second) {
    auto *firstPtr = (double *) first;
    auto *secondPtr = (double *) second;
    if (*firstPtr < *secondPtr) { return -1; }
    else if (*firstPtr > *secondPtr) { return 1; }
    return 0;
}

SVector::SVector() : Vector() {}

SVector::SVector(const double *array, unsigned length) : Vector(array, length) {
    sort();
}

SVector::SVector(unsigned length) : Vector(length) {}

SVector::SVector(const Vector &oVector) : Vector(oVector) {
    sort();
}

SVector &SVector::operator=(const SVector &other) {
    Vector::operator=(other);
    sort();
    return *this;
}

void SVector::setLength(unsigned length) {
    Vector::setLength(length);
    sort();
}

void SVector::addElement(double value) {
    Vector::addElement(value);
    sort();
}

std::istream &operator>>(std::istream &is, SVector &vector) {
    std::cout << "Enter new vector length: ";
    is >> vector.length;
    vector.vector = Utils::malloc(vector.length);
    for (int i = 0; i < vector.length; ++i) {
        std::cout << "Enter value for vector [" << i << "]";
        is >> vector.vector[i];
    }
    vector.sort();
}


