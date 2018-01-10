#ifndef EXERCISE4_ARRAY_H
#define EXERCISE4_ARRAY_H

#include <iostream>

class Array {

/** Private variables */
private:
    unsigned int rows;
    unsigned int columns;
    double **array;

/** Getters */
public:
    unsigned int getRows() const;
    unsigned int getColumns() const;
    double **getArray() const;

/** Public variables */
public:
    const static bool debugEnabled = true;

/** Constructors */
public:
    Array();
    Array(unsigned int rows, unsigned int columns);
    Array(double **originalArray, unsigned int rows, unsigned int columns);
    Array(const Array &originalArray);

/** Destructors */
public:
    ~Array();

/** Public methods */
public:
    void printArray();
    void changeArraySize(unsigned int newRows, unsigned int newColumns);
    static double **generateRandomArray(unsigned int rows, unsigned int columns);

/* Overloaded operators */
public:
    Array& operator=(const Array& other);
    Array& operator+();
    Array& operator-();
    Array& operator+=(const Array& other);
    Array& operator-=(const Array& other);
    Array& operator*=(unsigned int value);
    Array& operator*=(const Array &other);
    double *operator[](unsigned int value);
    double operator()(unsigned int row, unsigned int column);

};


#endif
