#ifndef EXERCISE8_SVECTOR_H
#define EXERCISE8_SVECTOR_H

#include "Vector.h"

class SVector : public Vector {
private:
    /**
     * Sort elements
     */
    void sort();

public:
    virtual double &operator[](unsigned index);

private:

    /**
     * Compare vector values
     * @param first element x
     * @param second element x + 1
     * @return 1 if x > x + 1, -1 if x < x + 1, 0 if they are equals
     */
    static int compareValues(const void *first, const void *second);

public:
    /**
     * Default constructor (set length to zero)
     */
    SVector();

    /**
     * Create vector using fixed base array
     * @param array Base array
     * @param length Array length
     */
    SVector(const double *array, unsigned length);

    /**
     * Create fixed length vector and fill it with zeroes
     * @param length SVector length
     */
    explicit SVector(unsigned length);

    /**
     * Copy constructor with Vector instance
     * @param oVector
     */
    explicit SVector(const Vector &oVector);

    /**
     * Overloaded setLength
     */
    void setLength(unsigned length) override;

    /**
     * Overloaded addValue
     */
    void addValue(double value) override;

    SVector &operator=(const Vector &oVector);

    std::istream &input(std::istream &is) override;
};


#endif
