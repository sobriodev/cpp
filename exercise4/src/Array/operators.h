#ifndef EXERCISE4_OPERATORS_H
#define EXERCISE4_OPERATORS_H

#include "Array.h"

Array operator+(const Array &array1, const Array &array2);
Array operator-(const Array &array1, const Array &array2);
Array operator*(const Array &array, double value);
Array operator*(const Array &array1, const Array &array2);
bool operator==(const Array &array1, const Array &array2);
bool operator!=(const Array &array1, const Array &array2);
std::ostream &operator<<(std::ostream &os, const Array &array);
std::istream &operator>>(std::istream &is, Array &array);

#endif
