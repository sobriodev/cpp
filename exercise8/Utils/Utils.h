#ifndef EXERCISE8_UTILS_H
#define EXERCISE8_UTILS_H


class Utils {

public:
    /**
     * Allocate vector memory with given length
     * @param length vector length
     * @return
     */
    static double *malloc(unsigned length);
    /**
     * Free vector memory
     * @param vector vector to be deleted
     */
    static void free(const double *vector);

};


#endif
