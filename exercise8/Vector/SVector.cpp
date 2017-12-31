#include "SVector.h"

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

SVector::SVector(): Vector() {}

SVector::SVector(const double *array, unsigned length) : Vector(array, length) {
    sort();
}

SVector::SVector(unsigned length) : Vector(length) {}

SVector::SVector(const Vector &oVector) : Vector(oVector) {
    sort();
}

void SVector::setLength(unsigned length) {
    Vector::setLength(length);
    sort();
}

void SVector::addValue(double value) {
    Vector::addValue(value);
    sort();
}

SVector &SVector::operator=(const Vector &oVector) {
    Vector::operator=(oVector);
    sort();
    return *this;
}


std::istream &SVector::input(std::istream &is) {
    Vector::input(is);
    sort();
    return is;
}

double &SVector::operator[](unsigned index) {
    sort();
    return Vector::operator[](index);
}

