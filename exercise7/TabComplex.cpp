#include "TabComplex.h"

TabComplex::TabComplex() {
    for (int i = 0; i < 10; ++i) {
        tab_c[i] = Complex(i, i);
    }
}

std::ostream &operator<<(std::ostream &os, TabComplex &complex) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 4; ++j) {
            Complex c = complex.tab_c[i];
            os << (c.*c.tab_wsk_fun[j])() << std::endl;
        }
    }
    return os;
}
