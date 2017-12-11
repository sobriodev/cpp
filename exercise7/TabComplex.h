#ifndef EXERCISE7_TABCOMPLEX_H
#define EXERCISE7_TABCOMPLEX_H

#include <iostream>
#include "Complex.h"

class TabComplex {
private:
    Complex tab_c[10];
public:
    TabComplex();
    friend std::ostream &operator<<(std::ostream &os, TabComplex &complex);
};


#endif
