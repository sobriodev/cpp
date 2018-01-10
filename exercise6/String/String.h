#ifndef EXERCISE6_STRING_H
#define EXERCISE6_STRING_H

#include <iostream>

class String {

/* Public variables */
public:
    static const bool debugEnabled = false;
    static unsigned objects;

/* Private variables */
private:
    char *string;

/* Constructors and destructors */
public:
    String();
    explicit String(const char *ptr);
    String(const String &originalStr);
    ~String();

/* Public functions */
public:
    unsigned getLength();
    void print();
    static unsigned howMuchObjects();

/* Overloaded operators and functions */
public:
    explicit operator char *() const;
    String &operator=(const String &originalStr);
    String &operator=(const char *originalString);
    String &operator+=(const String &secondString);
    String &operator+=(const char *secondString);
    friend String operator+(const String &firstString, const String &secondString);
    friend String operator+(const String &firstString, const char * secondString);
    friend std::istream &operator>>(std::istream &is, String &string);
    friend std::ostream &operator<<(std::ostream &os, String &string);

};


#endif
