#ifndef EXERCISE4_ARRAY_H
#define EXERCISE4_ARRAY_H

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

};


#endif