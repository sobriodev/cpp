#include <iostream>
#include "Vector.h"
#include "../Utils/Utils.h"

Vector::Vector(): length(0), vector(Utils::malloc(length)) {}

Vector::Vector(const double *array, unsigned length):
        length(length),
        vector(Utils::malloc(length))
{
    for (int i = 0; i < length; ++i) {
        vector[i] = array[i];
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

void Vector::setLength(unsigned length) {
    double *temp = vector;
    vector = Utils::malloc(length);
    unsigned min = this->length < length ? this->length : length;
    int i;
    for (i = 0; i < min; ++i) {
        vector[i] = temp[i];
    }
    for (; i < length; ++i) {
        vector[i] = 0;
    }
    this->length = length;
    Utils::free(temp);
}

void Vector::addElement(double value) {
    double *temp = vector;
    vector = Utils::malloc(length + 1);
    int i;
    for (i = 0; i < length; ++i) {
        vector[i] = temp[i];
    }
    vector[i] = value;
    ++length;
    Utils::free(temp);
}

bool operator==(const Vector &first, const Vector &second) {
    if (first.length != second.length) {
        return false;
    }
    for (int i = 0; i < first.length; ++i) {
        if (first.vector[i] != second.vector[i]) { return false; }
    }
    return true;
}

bool operator!=(const Vector &first, const Vector &second) {
    return !(first == second);
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "[" << vector.length << (!vector.length ? "" : " ");
    for (int i = 0; i < vector.length; ++i) {
        os << vector.vector[i] << (i == vector.length - 1 ? "" : " ");
    }
    os << "]" << std::endl;
}

std::istream &operator>>(std::istream &is, Vector &vector) {
    std::cout << "Enter new vector length: ";
    is >> vector.length;
    vector.vector = Utils::malloc(vector.length);
    for (int i = 0; i < vector.length; ++i) {
        std::cout << "Enter value for vector [" << i << "]";
        is >> vector.vector[i];
    }
}
