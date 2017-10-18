#ifndef CWICZENIE2_KLASA_H
#define CWICZENIE2_KLASA_H


class Klasa {
private:
    const static int MAKS_DLUGOSC = 10;
    const int KOD_BLEDU = 999;
    int tablica[MAKS_DLUGOSC];
    int dlugosc = 0;

    static int licznik;

public:
    Klasa();

    int set(int *tablica, int dlugosc);
    int get(int indeks);
    static int ile();
    void wypisz();

    ~Klasa();
};

#endif //CWICZENIE2_KLASA_H
