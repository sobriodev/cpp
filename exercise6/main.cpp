#include <iostream>
#include <cstring>
#include "String/String.h"

int main() {
    String A("_ciag_A_");
    String B;
    B = "_ciag_B_";
    B += A;
    std::cout << "Istnieja : " << String::howMuchObjects() << " ciagi" << std::endl;
    String C;
    std::cout << "Podaj ciag C: ";
    std::cin >> C;
    String D;
    D = A + B + "_cos_";
    std::cout << "Istnieja : " << String::howMuchObjects() << " ciagi" << std::endl;
    A += "_dodaje_zwykly_ciag_";
    C += A;
    std::cout << A << B << C << D << std::endl;
    {
        String ZZ;
        std::cout << "Powstal ciag lokalny i istnieja " << String::howMuchObjects() << " ciagi" << std::endl;
    }
    std::cout << "A teraz znowu sa " << A.howMuchObjects() << " ciagi" << std::endl;
    std::cout << std::strlen((char *) A) << std::endl;
    std::cout << std::strlen((char *) B) << std::endl;
    std::cout << std::strlen((char *) C) << std::endl;
    std::cout << std::strlen((char *) D) << std::endl;
    return EXIT_SUCCESS;
}