#include <iostream>
#include "Klasa.h"

int main() {
    Klasa klasa;

    int tab[2] = {1, 2};
    klasa.set(tab, 11);
    std::cout << klasa.get(2) << std::endl;
    std::cout << klasa.ile() << std::endl;
    klasa.wypisz();

}