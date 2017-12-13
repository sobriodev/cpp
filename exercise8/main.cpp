#include <iostream>
#include "Vector/Vector.h"

int main() {
    const unsigned SIZE = 2;
    double array[SIZE] = {2, 1};
    Vector v1(array, SIZE);
    std::cout << v1;
    *v1[0] = 21;
    std::cout << v1;
}