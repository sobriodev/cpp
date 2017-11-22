#include <cstring>
#include "Utils.h"

char *Utils::allocateMemory(unsigned length) {
    if (!length) { return nullptr; }
    return new char[length];
}

void Utils::freeMemory(const char *ptr) {
    delete[] ptr;
}

unsigned Utils::realPtrLength(const char *ptr) {
    if (!ptr) { return 0; }
    return unsigned(std::strlen(ptr) + 1);
}
