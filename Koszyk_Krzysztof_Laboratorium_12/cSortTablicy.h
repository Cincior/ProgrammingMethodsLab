#ifndef CSORTTABLICY_H
#define CSORTTABLICY_H

class cSortTablicy {
public:
    // Konstruktor
    cSortTablicy() {}

    // Metody
    void wprowadzDaneZKlawiatury(int& n);
    void losujDane(int* tab, int n, int typ);
    void sortuj(int* tab, int n, int typ);
    unsigned long long pobierzLiczbePorownan() const;
    unsigned long long pobierzLiczbePrzestawien() const;
    void wypiszTablice(int* tab, int n);

private:
    // Sk³adowe
    unsigned long long comparisons = 0;
    unsigned long long swaps = 0;

    // Metody pomocnicze
    void wypiszStatystyki(unsigned long long comparisons, unsigned long long swaps);

};

#endif // CSORTTABLICY_H
