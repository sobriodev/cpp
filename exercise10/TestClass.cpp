#include "TestClass.h"

bool TestClass::operator<(const TestClass &rhs) const {
    return value < rhs.value;
}

bool TestClass::operator>(const TestClass &rhs) const {
    return rhs < *this;
}

std::ostream &operator<<(std::ostream &os, const TestClass &object) {
    os << "I'm from Test class with value: " << object.value << std::endl;
    return os;
}

TestClass::TestClass() {
    value = 0;
}
