#include <iostream>
#include <cstring>
#include "String.h"
#include "../Utils/Utils.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"

unsigned String::objects = 0;

/* -------------------------------- */
/* ----CONSTRUCTORS/DESTRUCTORS---- */
/* -------------------------------- */
String::String() {
    objects++;
    string = Utils::allocateMemory(0);
    if (debugEnabled) { std::cout << "#DEBUG# Default constructor was used" << std::endl; }
}

String::String(const char *ptr) {
    objects++;
    string = Utils::allocateMemory(Utils::realPtrLength(ptr));
    if (ptr) { std::strcpy(string, ptr); }
    if (debugEnabled) { std::cout << "#DEBUG# String from pointer constructor was used" << std::endl; }
}

String::String(const String &originalStr) {
    objects++;
    string = Utils::allocateMemory(Utils::realPtrLength((char *) originalStr));
    if ((char *) originalStr) { std::strcpy(string, (char *) originalStr); }
    if (debugEnabled) { std::cout << "#DEBUG# Copy constructor was used" << std::endl; }
}

String::~String() {
    objects--;
    Utils::freeMemory(string);
    string = nullptr;
    if (debugEnabled) { std::cout << "#DEBUG# Destructor was used" << std::endl; }
}

/* -------------------------------- */
/* ---------PUBLIC FUNCTIONS------- */
/* -------------------------------- */
unsigned String::getLength() {
    return string == nullptr ? 0 : unsigned(std::strlen(string));
}

void String::print() {
    if (!string) { std::cout << "EMPTY STRING!" << std::endl; }
    else { std::cout << string << std::endl; }
}

unsigned String::howMuchObjects() {
    return objects;
}

/* -------------------------------- */
/* -OVERLOADED OPERATORS/FUNCTIONS- */
/* -------------------------------- */
String::operator char *() const {
    if (debugEnabled) { std::cout << "#DEBUG# Operator char * was used" << std::endl; }
    return string;
}

String &String::operator=(const String &originalStr) {
    Utils::freeMemory(string);
    string = Utils::allocateMemory(Utils::realPtrLength((char *) originalStr));
    if ((char *) originalStr) { std::strcpy(string, (char *) originalStr); }
    if (debugEnabled) { std::cout << "#DEBUG# operator= was used" << std::endl; }
    return *this;
}

String &String::operator=(const char *originalString) {
    Utils::freeMemory(string);
    string = Utils::allocateMemory(Utils::realPtrLength(originalString));
    if (originalString) { std::strcpy(string, originalString); }
    return *this;
}

String &String::operator+=(const String &secondString) {
    auto *tempStr = Utils::allocateMemory(Utils::realPtrLength(string));
    if (tempStr) { std::strcpy(tempStr, string); }
    if (!tempStr) {
        // NULL, NOT NULL
        if (((char *) secondString)) {
            unsigned newStringLength = Utils::realPtrLength((char *) secondString);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, (char *) secondString);
        }
    } else {
        // NOT NULL, NULL
        if (!((char *) secondString)) {
            unsigned newStringLength = Utils::realPtrLength(tempStr);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, tempStr);
        }
        else {
            // NOT NULL, NOT NULL
            unsigned newStringLength = getLength() + Utils::realPtrLength((char *) secondString);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, tempStr);
            std::strcpy(string + getLength(), (char *) secondString);
        }
    }
    Utils::freeMemory(tempStr);
    return *this;
}

String &String::operator+=(const char *secondString) {
    auto *tempStr = Utils::allocateMemory(Utils::realPtrLength(string));
    if (tempStr) { std::strcpy(tempStr, string); }
    if (!tempStr) {
        // NULL, NOT NULL
        if (secondString) {
            unsigned newStringLength = Utils::realPtrLength(secondString);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, secondString);
        }
    } else {
        // NOT NULL, NULL
        if (!secondString) {
            unsigned newStringLength = Utils::realPtrLength(tempStr);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, tempStr);
        }
        else {
            // NOT NULL, NOT NULL
            unsigned newStringLength = getLength() + Utils::realPtrLength(secondString);
            string = Utils::allocateMemory(newStringLength);
            std::strcpy(string, tempStr);
            std::strcpy(string + getLength(), secondString);
        }
    }
    Utils::freeMemory(tempStr);
    return *this;
}


#pragma clang diagnostic pop