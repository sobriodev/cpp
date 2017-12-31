#ifndef EXERCISE8_MEMORY_H
#define EXERCISE8_MEMORY_H

class Memory {
public:
    /**
     * Allocate memory
     * @param length Array length
     * @return Pointer to allocated memory or nullptr when something gone wrong
     */
    static double *malloc(unsigned length);
    /**
     * Free memory
     * @param array Array to delete
     */
    static void free(const double *array);
};

#endif
