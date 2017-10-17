#include <iostream>
#include "K.h"

int main() {

    K k1;
    K *wk = new K;

    k1.setN(0);
    k1.setZ(0.0);
    k1.setC('a');
    wk->setN(2);
    wk->setZ(1.5);
    wk->setC('c');
    std::cout << k1.getN() << std::endl << k1.getZ() << std::endl << k1.getC() << std::endl;
    std::cout << "Obiekt k1:" << std::endl;
    k1.wypisz();
    std::cout << "Obiekt dynamiczny wk dostep wskaznikiem:" << std::endl;
    wk->wypisz();
    std::cout << "Obiekt dynamiczny wk dostep jak do obiektu:" << std::endl;
    (*wk).wypisz();
    delete wk;
    return 0;
}