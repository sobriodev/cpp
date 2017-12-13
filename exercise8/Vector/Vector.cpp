#include <iostream>
#include "Vector.h"
#include "../Utils/Utils.h"

Vector::Vector(): length(0), vector(Utils::malloc(length)) {}

Vector::Vector(const double *oVector, unsigned length):
        length(length),
        vector(Utils::malloc(length))
{
    for (int i = 0; i < length; ++i) {
        vector[i] = oVector[i];
    }
}

Vector::Vector(unsigned length):
        length(length),
        vector(Utils::malloc(length))
{
    for (int i = 0; i < length; ++i) {
        vector[i] = 0;
    }
}

Vector::Vector(const Vector &oVector):
        length(oVector.length),
        vector(Utils::malloc(oVector.length))
{
    for (int i = 0; i < length; ++i) {
        vector[i] = oVector.vector[i];
    }
}

Vector::~Vector() {
    Utils::free(vector);
}

Vector &Vector::operator=(const Vector &other) {
    length = other.length;
    vector = Utils::malloc(length);
    for (int i = 0; i < length; ++i) {
        vector[i] = other.vector[i];
    }
}

double *Vector::operator[](unsigned index) {
    if (!length || index > length - 1) {
        return nullptr;
    }
    return vector + index;
}

unsigned int Vector::getLength() const {
    return length;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "[" << vector.length << (!vector.length ? "" : " ");
    for (int i = 0; i < vector.length; ++i) {
        os << vector.vector[i] << (i == vector.length - 1 ? "" : " ");
    }
    os << "]" << std::endl;
}

