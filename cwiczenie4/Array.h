#ifndef CWICZENIE4_MATRIX_H
#define CWICZENIE4_MATRIX_H

enum messagesIDs { DEFAULT_CONSTRUCTOR };

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

    unsigned int getRows();
    unsigned int getColumns();
    double **getArray();

    ~Array();

private:
    unsigned int rows;
    unsigned int columns;
    double **array;
};


#endif //CWICZENIE4_MATRIX_H
