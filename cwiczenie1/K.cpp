#include "K.h"
#include <iostream>

int K::getN() const {
    return n;
}

void K::setN(int n) {
    this->n = n;
}

float K::getZ() const {
    return z;
}

void K::setZ(float z) {
    this->z = z;
}

char K::getC() const {
    return c;
}

void K::setC(char c) {
    this->c = c;
}

void K::wypisz() {
    std::cout << "n = " << n << ", z = " << z << ", c = " << c << std::endl;
}
