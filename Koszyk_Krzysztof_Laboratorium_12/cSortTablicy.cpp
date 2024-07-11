#include "cSortTablicy.h"
#include "cTablica.h"
#include "libCustomExceptions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

void cSortTablicy::wprowadzDaneZKlawiatury(int& n) {
    try {
        cout << "Podaj liczbe elementow tablicy: ";
        if (!(cin >> n) || n <= 0) {
            throw CustomExceptions::VariableError("Niepoprawna liczba elementów tablicy.");
        }
    }
    catch (const CustomExceptions::VariableError& e) {
        cerr << "Blad: " << e.what() << endl;
        exit(1);
    }
}



void cSortTablicy::losujDane(int* tab, int n, int typ) {
    try {
        if (n <= 0) {
            throw invalid_argument("Nieprawidlowy rozmiar tablicy");
        }
        srand(time(nullptr)); // Inicjalizacja generatora liczb pseudolosowych

        int tenPercent;

        switch (typ) {
        case 1: // Losowe elementy
            for (int i = 0; i < n; i++) {
                tab[i] = rand() % 1000; // Losowanie liczb z zakresu 0-999
            }
            break;
        case 2: // Uporz¹dkowane elementy
            for (int i = 0; i < n; i++) {
                tab[i] = i + 7; 
            }
            break;
        case 3: // Odwrotnie uporzadkowane elementy
            for (int i = n; i > 0; i--) {
                tab[n - i] = i;
            }
            break;

        case 4: // Prawie posortowane elementy (10% elementów na z³ych pozycjach)
            tenPercent = n / 10;
            for (int i = 0; i < n - tenPercent; i++) {
                tab[i] = i + 7;
            }
            for (int i = n - tenPercent; i < n; i++) {
                tab[i] = i - 7;
            }
            break;
        default:
            throw invalid_argument("Nieprawidlowy typ danych");
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Blad: " << e.what() << endl;
    }
}

void cSortTablicy::sortuj(int* tab, int n, int typ) {
    try {
        if (n <= 0) {
            throw invalid_argument("Nieprawidlowy rozmiar tablicy");
        }
        cTablica sortTest;

        switch (typ) {
        case 1:
            cout << "Sortowanie b¹belkowe (shaker sort):" << endl;
            sortTest.shakerSort(tab, n);
            break;
        case 2:
            cout << "Sortowanie szybkie (algorytm Lomuto):" << endl;
            sortTest.quickSortLomuto(tab, 0, n - 1);
            break;
        case 3:
            cout << "Sortowanie szybkie (algorytm Hoare'a):" << endl;
            sortTest.quickSortHoare(tab, 0, n - 1);
            break;
        case 4:
            cout << "Sortowanie przez kopcowanie:" << endl;
            sortTest.heapSort(tab, n);
            break;
        default:
            throw invalid_argument("Nieprawidlowy typ sortowania");
        }

        // Wyœwietlanie statystyk tylko raz, po sortowaniu
        wypiszStatystyki(sortTest.getComparisons(), sortTest.getSwaps());
    }
    catch (const invalid_argument& e) {
        cerr << "Blad: " << e.what() << endl;
    }
}


unsigned long long cSortTablicy::pobierzLiczbePorownan() const
{
    return comparisons;
}

unsigned long long cSortTablicy::pobierzLiczbePrzestawien() const
{
    return swaps;
}

void cSortTablicy::wypiszTablice(int* tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void cSortTablicy::wypiszStatystyki(unsigned long long comparisons, unsigned long long swaps) {
    cout << "Liczba porownan: " << comparisons << "\nLiczba przestawien: " << swaps << "\n";
}
