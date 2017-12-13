#ifndef EXERCISE8_VECTOR_H
#define EXERCISE8_VECTOR_H


#include <ostream>

class Vector {

private:
    /**
     * Vector length
     */
    unsigned length;
    /**
     * Vector numbers
     */
    double *vector;

public:
    /**
     * Default constructor. Set length to zero and use nullptr
     */
    Vector();

    /**
     * Constructor creating a vector from a given one
     * @param oVector original vector
     * @param length original vector length
     */
    Vector(const double *oVector, unsigned length);

/**
     * Constructor creating a vector with all zeroes from a given length
     * @param length vector length
     */
    explicit Vector(unsigned length);

    /**
     * Copy constructor
     * @param oVector original vector object
     */
    Vector(const Vector &oVector);

    /**
     * Destructor
     */
    virtual ~Vector();

    /**
     * Overloaded copy assignment operator
     * @param other other vector object
     * @return current vector reference
     */
    Vector &operator=(const Vector &other);

    /**
     * Overloaded array access operator
     * @param index number index
     * @return pointer to particular number
     */
    double *operator[](unsigned index);

    /**
     * Print vector using overloaded output stream operator
     * @param os output stream instance
     * @param vector vector object to print
     * @return output stream instance
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

    /**
     * Length getter
     * @return vector length
     */
    unsigned int getLength() const;

};


#endif
