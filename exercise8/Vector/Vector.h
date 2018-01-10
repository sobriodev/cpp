#ifndef EXERCISE8_VECTOR_H
#define EXERCISE8_VECTOR_H

#include <ostream>

class Vector {
protected:
    /**
     * Vector length
     */
    unsigned length;

    /**
     * Pointer to vector memory
     */
    double *vector;

public:
    /**
     * Default constructor (set length to zero)
     */
    Vector();

    /**
     * Create vector using fixed base array
     * @param array Base array
     * @param length Array length
     */
    Vector(const double *array, unsigned length);

    /**
     * Create fixed length vector and fill it with zeroes
     * @param length Vector length
     */
    explicit Vector(unsigned length);

    /**
     * Copy constructor
     * @param oVector Original Vector instance
     */
    Vector(const Vector &oVector);

    /**
     * Vector destructor
     */
    virtual ~Vector();

    /**
     * Copy assignment operator
     * @param oVector Original Vector instance
     * @return Vector instance
     */
    Vector &operator=(const Vector &oVector);

    /**
     * Array subscript operator
     * @param index Value index
     * @return reference to requested index
     */
    virtual double &operator[](unsigned index);

    /**
     * Length getter
     * @return Vector length
     */
    unsigned int getLength() const;

    /**
     * Set new vector length
     * @param length New length
     */
    virtual void setLength(unsigned length);

    /**
     * Add new value to the vector's end
     * @param value New value
     */
    virtual void addValue(double value);

    /**
     * Vectors equality operator
     * @param rhs Other Vector
     * @return true if vectors are the same, false otherwise
     */
    friend bool operator==(const Vector &lhs, const Vector &rhs);

    /**
     * Vectors inequality operator
     * @param rhs Other Vector
     * @return true if vectors are not the same, false otherwise
     */
    friend bool operator!=(const Vector &lhs, const Vector &rhs);

    /**
     * Stream output operator
     * @param os Output stream instance
     * @param vector Vector to display
     * @return Stream output instance
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);

    /**
     * Stream input operator
     * @param is Input stream instance
     * @param vector Vector to input
     * @return Stream input instance
     */
    friend std::istream &operator>>(std::istream &is, Vector &vector);

    virtual std::istream &input(std::istream &is);
};

#endif
