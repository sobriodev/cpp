#ifndef CWICZENIE4_MATRIX_H
#define CWICZENIE4_MATRIX_H

class Matrix {

public:
    /* Default constructor */
    Matrix();

    /* Create matrix of a given size */
    Matrix(unsigned int rows, unsigned int columns);

    /* Copy matrix to matrix */
    Matrix(double **originalMatrix, unsigned int rows, unsigned int columns);

    /* Default destructor*/
    ~Matrix();

    /* Print the matrix */
    void printMatrix();

    /* Rows getter */
    unsigned int getRows();

    /* Columns getter */
    unsigned int getColumns();

    /* Generate random matrix */
    static double **generateMatrix(unsigned int rows, unsigned int columns);

private:
    /* Number of internal matrix rows */
    unsigned int rows;
    /* Number of internal matrix columns */
    unsigned int columns;
    /* Internal matrix */
    double **matrix;

    /* Allocate matrix memory */
    void allocateMemory(unsigned int rows, unsigned int columns);
    /* Free memory used to store the matrix */
    void freeMemory();
};


#endif //CWICZENIE4_MATRIX_H
