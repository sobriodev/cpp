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
     * Length getter
     * @return vector length
     */
    unsigned int getLength() const;

    /**
     * Set new vector length
     * @param length length
     */
    void setLength(unsigned length);

    /**
     * Add new value to vector
     * @param value element to add
     */
    void addElement(double value);

    /**
     * Equality operator
     * @param first First Vector
     * @param second Second Vector
     * @return true if vector are equals, false otherwise
     */
    friend bool operator==(const Vector &first, const Vector &second);

    /**
     * Inequality operator
     * @param first First Vector
     * @param second Second Vector
     * @return true if vector are not equals, false otherwise
     */
    friend bool operator!=(const Vector &first, const Vector &second);

    /**
     * Print vector using overloaded output stream operator
     * @param os output stream instance
     * @param vector vector object to print
     * @return output stream instance
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

    /**
     * Input vector using overloaded input stream operator
     * @param is input stream instance
     * @param vector vector object to input values
     * @return input stream instance
     */
    friend std::istream &operator>>(std::istream &is, Vector &vector);

};


#endif
