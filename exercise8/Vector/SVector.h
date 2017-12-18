#ifndef EXERCISE8_SVECTOR_H
#define EXERCISE8_SVECTOR_H

#include <ostream>
#include "Vector.h"

class SVector : public Vector {

private:
    /**
     * Sort elements
     */
    void sort();

    /**
     * Compare vector values
     * @param first element x
     * @param second element x + 1
     * @return 1 if x > x + 1, -1 if x < x + 1, 0 if they are equals
     */
    static int compareValues(const void *first, const void *second);

public:
    SVector();

    SVector(const double *array, unsigned length);

    explicit SVector(unsigned length);

    explicit SVector(const Vector &oVector);

    SVector &operator=(const SVector &other);

    void setLength(unsigned length) override ;

    void addElement(double value) override ;

    friend std::istream &operator>>(std::istream &is, SVector &vector);
};

#endif
