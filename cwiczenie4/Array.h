#ifndef CWICZENIE4_ARRAY_H
#define CWICZENIE4_ARRAY_H

class Array {

public:
    const static bool debugEnabled = true;

    static double **allocateMemory(unsigned int rows, unsigned int columns, double value = 0);
    static void freeMemory(double **pointer, unsigned int rows);
    static double **generateArray(unsigned int rows, unsigned int columns);
    static void printArray(double **pointer, unsigned int rows, unsigned int columns);
    void printArray();
    static void setValues(double **pointer, unsigned int rows, unsigned int columns, double value = 0);
    void changeSize(unsigned int rows, unsigned int columns);

    Array();
    Array(unsigned int rows, unsigned int columns);
    Array(double **originalArray, unsigned int rows, unsigned int columns);
    Array(Array &originalArray);

    unsigned int getRows()const;
    unsigned int getColumns() const;
    double **getArray() const;

    ~Array();

    /* overloaded operators */
    Array &operator=(const Array &a);

private:
    unsigned int rows;
    unsigned int columns;
    double **array;
};


#endif //CWICZENIE4_ARRAY_H
