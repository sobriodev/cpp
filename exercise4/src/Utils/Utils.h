#ifndef EXERCISE4_UTILS_H
#define EXERCISE4_UTILS_H

#include <iostream>
#include <cstdlib>
#include "../Array/Array.h"

class Utils {

public:
    /**
     *
     * @param rows
     * @param columns
     * @return **double or nullptr
     */
    static double **allocateMemory(unsigned int rows, unsigned int columns, double value = 0);

    /**
     *
     * @param ptr
     * @param rows
     */
    static void freeMemory(double **ptr, unsigned int rows);

    /**
     *
     * @param array1
     * @param array2
     */
    static void compareArraysSizes(const Array &array1, const Array &array2);
};


#endif
