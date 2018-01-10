#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include "Vector.h"
#include "Memory.h"

Vector::Vector(): length(0), vector(Memory::malloc(length)) {}

Vector::Vector(const double *array, unsigned length): length(length), vector(Memory::malloc(length)) {
    for (int i = 0; i < length; ++i) {
        vector[i] = array[i];
    }
}

Vector::Vector(unsigned length): length(length), vector(Memory::malloc(length)) {
    for (int i = 0; i < length; ++i) {
        vector[i] = 0;
    }
}

Vector::Vector(const Vector &oVector): length(oVector.length), vector(Memory::malloc(length)) {
    for (int i = 0; i < length; ++i) {
        vector[i] = oVector.vector[i];
    }
}

Vector::~Vector() {
    Memory::free(vector);
}

Vector &Vector::operator=(const Vector &oVector) {
    length = oVector.length;
    vector = Memory::malloc(length);
    for (int i = 0; i < length; ++i) {
        vector[i] = oVector.vector[i];
    }
    return *this;
}

double &Vector::operator[](unsigned index) {
    if (!length || index > length - 1) {
        std::fputs("Vector::operator[]: invalid index!", stderr);
        exit(EXIT_FAILURE);
    }
    return vector[index];
}

unsigned int Vector::getLength() const {
    return length;
}

void Vector::setLength(unsigned length) {
    const double *temp = vector;
    vector = Memory::malloc(length);
    unsigned min = this->length < length ? this->length : length;
    int i;
    for (i = 0; i < min; ++i) {
        vector[i] = temp[i];
    }
    for (; i < length; ++i) {
        vector[i] = 0;
    }
    this->length = length;
    Memory::free(temp);
}

void Vector::addValue(double value) {
    const double *temp = vector;
    vector = Memory::malloc(length + 1);
    int i;
    for (i = 0; i < length; ++i) {
        vector[i] = temp[i];
    }
    vector[i] = value;
    ++length;
    Memory::free(temp);
}

bool operator==(const Vector &lhs, const Vector &rhs) {
    if (lhs.length != rhs.length) {
        return false;
    }
    for (int i = 0; i < lhs.length; ++i) {
        if (lhs.vector[i] != rhs.vector[i]) { return false; }
    }
    return true;
}

bool operator!=(const Vector &lhs, const Vector &rhs) {
    return !(rhs == lhs);
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "[" << vector.length << (!vector.length ? "" : " ");
    for (int i = 0; i < vector.length; ++i) {
        os << vector.vector[i] << (i == vector.length - 1 ? "" : " ");
    }
    os << "]" << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Vector &vector) {
    return vector.input(is);
}

std::istream &Vector::input(std::istream &is) {
    std::string temp;
    std::cout << "Enter new vector: ";
    std::getline(std::cin, temp);
    if (temp.length() < 3) {
        std::fputs("Input vector string must have at least 3 characters!", stderr);
        exit(EXIT_FAILURE);
    }
    if (temp.at(0) != '[' || temp.back() != ']') {
        std::fputs("Input vector string must start and end with [] characters!", stderr);
        exit(EXIT_FAILURE);
    }
    temp.erase(0, 1);
    temp.erase(temp.length() - 1, 1);

    unsigned length;
    std::istringstream stringStream(temp);
    stringStream >> length;
    if (!stringStream) {
        std::fputs("Invalid vector length value!", stderr);
        exit(EXIT_FAILURE);
    }

    double *numbers = Memory::malloc(length);
    double tempNumber;
    for (int i = 0; i < length; ++i) {
        if (!(stringStream >> tempNumber)) {
            std::fputs("Error while reading vector value!", stderr);
            exit(EXIT_FAILURE);
        }
        numbers[i] = tempNumber;
    }
    setLength(length);
    for (unsigned i = 0; i < length; ++i) {
        vector[i] = numbers[i];
    }

    Memory::free(numbers);
    return is;
}
