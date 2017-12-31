#include <iostream>
#include "Vector/Vector.h"
#include "Vector/SVector.h"

int main() {
    //Vector
    int i;
    Vector v1(10);
    for (i = 0; i < v1.getLength(); ++i) { v1[i] = i; }
    Vector v2(v1), v3;
    v3 = v2;
    v3[2] = 5.5;
    std::cout << "v1 = " << v1 << "v2 = " << v2 << "v3 =" << v3;
    if (v1 == v2) { std::cout << "v1 == v2" << std::endl; }
    if (v1 != v3) { std::cout << "v1 != v3" << std::endl; }
    v1.setLength(15);
    v1.addValue(34.56);
    std::cout << "Podaj v2" << std::endl;
    std::cin >> v2;
    std::cout << "v1 = " << v1 << "v2 = " << v2;

    //SVector
    SVector sv1(10);
    for (i = 0; i < sv1.getLength(); ++i) { sv1[i] = i; }
    SVector sv2(sv1);
    SVector sv3(v1);
    std::cout << "sv1 = " << sv1 << "sv2 = " << sv2 << "sv3 =" << sv3;
    if (sv1 == sv2) { std::cout << "sv1 == sv2" << std::endl; }
    if (sv1 != sv3) { std::cout << "sv1 != sv3" << std::endl; }
    v1[0] = sv1[7] = sv2[3] = sv3[4] = 4.5;
    std::cout << "v1 = " << v1 << "sv1 = " << sv1 << "sv2 =" << sv2 << "sv3 = " << sv3;
    sv3 = v2;
    sv1.setLength(20);
    sv1.addValue(-12.45);
    std::cout << "Podaj sv2" << std::endl;
    std::cin >> sv2;
    std::cout << "sv1 = " << sv1 << "sv2 = " << sv2 << "sv3 =" << sv3;
    return EXIT_SUCCESS;

}