#include "../String/String.h"

String operator+(const String &firstString, const String &secondString) {
    String res(firstString);
    res += secondString;
    return res;
}

String operator+(const String &firstString, const char * secondString) {
    return String(firstString + String(secondString));
}

std::istream &operator>>(std::istream &is, String &string) {
    const unsigned bufferSize = 100;
    char buffer[bufferSize];
    is.getline(buffer, bufferSize);
    String newString(buffer);
    string = newString;
    return is;
}

std::ostream &operator<<(std::ostream &os, String &string) {
    os << string.string << std::endl;
    return os;
}