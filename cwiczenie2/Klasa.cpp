#include "Klasa.h"
#include <iostream>

int Klasa::set(int *tablica, int dlugosc) {
    if (dlugosc > MAKS_DLUGOSC) {
        return KOD_BLEDU;
    } else {
        for (int i = 0; i < dlugosc; ++i) {
            this->tablica[i] = tablica[i];
        }
        this->dlugosc = dlugosc;
    };
    return 0;
}

int Klasa::get(int indeks) {
    if (indeks > dlugosc - 1) {
        return KOD_BLEDU;
    } else {
        return tablica[indeks];
    }
}

int Klasa::licznik = 0;

Klasa::Klasa() {
    licznik++;
}

Klasa::~Klasa() {
    licznik--;
}

int Klasa::ile() {
    return licznik;
}

void Klasa::wypisz() {
    for (int i = 0; i < dlugosc; ++i) {
        std::cout << "[" << i << "] -> " << tablica[i] << std::endl;
    }
}
