#include <iostream>
#include "Vector/Vector.h"

int main() {
    const unsigned SIZE = 2;
    double array[SIZE] = {2, 1};
    Vector v1(array, SIZE);
    Vector v2;
    std::cout << v2;
    std::cin >> v1;
    std::cout << v1;
    return 0;
}