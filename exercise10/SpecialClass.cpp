#include "SpecialClass.h"

std::ostream &operator<<(std::ostream &os, const SpecialClass &aClass) {
    os << "I'm from SpecialClass with string: " << aClass.string << std::endl;
    return os;
}

const std::string &SpecialClass::getString() const {
    return string;
}

SpecialClass::SpecialClass() {
    string = "empty";
}
