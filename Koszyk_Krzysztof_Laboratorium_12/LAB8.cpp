#include <iostream>
#include "cSortTablicy.h"
#include "libOperations.h"
#include "typeClasses.h"
#include "libFile.h"
#include "libCustomExceptions.h"
#include "cTablica.h"

using namespace std;

int main() {
    int wybor;
    cout << "Wybierz zadanie do wykonania:" << endl;
    cout << "1. Zadanie 1 - Wyra¿enia Arytmetyczne" << endl;
    cout << "2. Zadanie 2 - Algorytmy Sortowania" << endl;
    cout << "Wybor: ";
    cin >> wybor;

    switch (wybor) {
    case 1: {
        // Tworzenie obiektów klas cDouble, cFloat, cInt, cChar
        cDouble D(2.5, 12.5);
        cFloat F(5.5f, 2.2f);
        cInt I(10, 3);
        char x[] = "1aaaa";
        char y[] = "def";
        cChar C(x, y);

        // Wywo³ywanie funkcji na rzecz obiektów
        cout << "cDouble (2.5, 12.5):\n";
        cout << "fadd: " << D.a << " + " << D.b << " = " << fadd<double, double>(D.a, D.b) << "\n";
        cout << "fsub: " << D.a << " - " << D.b << " = " << fsub<double, double>(D.a, D.b) << "\n";
        cout << "fmul: " << D.a << " * " << D.b << " = " << fmul<double, double>(D.a, D.b) << "\n";
        cout << "fdiv: " << D.a << " / " << D.b << " = " << fdiv<double, double>(D.a, D.b) << "\n";
        cout << "\n";

        cout << "cFloat (5.5, 2.2):\n";
        cout << "fadd: " << F.a << " + " << F.b << " = " << fadd<float, float>(F.a, F.b) << "\n";
        cout << "fsub: " << F.a << " - " << F.b << " = " << fsub<float, float>(F.a, F.b) << "\n";
        cout << "fmul: " << F.a << " * " << F.b << " = " << fmul<float, float>(F.a, F.b) << "\n";
        cout << "fdiv: " << F.a << " / " << F.b << " = " << fdiv<float, float>(F.a, F.b) << "\n";
        cout << "\n";

        cout << "cInt (10, 3):\n";
        cout << "fadd: " << I.a << " + " << I.b << " = " << fadd<int, int>(I.a, I.b) << "\n";
        cout << "fsub: " << I.a << " - " << I.b << " = " << fsub<int, int>(I.a, I.b) << "\n";
        cout << "fmul: " << I.a << " * " << I.b << " = " << fmul<int, int>(I.a, I.b) << "\n";
        cout << "fdiv: " << I.a << " / " << I.b << " = " << fdiv<int, int>(I.a, I.b) << "\n";
        cout << "\n";

        cout << "cChar (\"1aaaa\", \"def\"):\n";
        cout << "flen: \"" << C.a << "\" + \"" << C.b << "\" = " << flen<char*, int>(C.a, C.b) << "\n";

        break;
    }
    case 2: {
        cSortTablicy sorter;

        // Wprowadzanie liczby elementów z klawiatury
        int n;
        sorter.wprowadzDaneZKlawiatury(n);

        int* tab = new int[n];

        // Losowanie danych
        cout << "Wybierz typ danych do wylosowania:" << endl;
        cout << "1. Losowe elementy" << endl;
        cout << "2. Uporzadkowane elementy" << endl;
        cout << "3. Odwrotnie uporzadkowane elementy" << endl;
        cout << "4. Prawie posortowane elementy (10% elementów na z³ych pozycjach)" << endl;
        int typ;
        cout << "Wybor: ";
        cin >> typ;

        sorter.losujDane(tab, n, typ);

        // Wyœwietlanie wylosowanych danych
        /*cout << "Wylosowane liczby:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << tab[i] << " ";
        }
        cout << endl;*/

        // Wybór i ilustracja dzia³ania metod sortowania
        cout << "Wybierz metode sortowania:" << endl;
        cout << "1. Sortowanie b¹belkowe (shaker sort)" << endl;
        cout << "2. Sortowanie szybkie (algorytm Lomuto)" << endl;
        cout << "3. Sortowanie szybkie (algorytm Hoare'a)" << endl;
        cout << "4. Sortowanie przez kopcowanie" << endl;
        int metoda;
        cout << "Wybor: ";
        cin >> metoda;

        sorter.sortuj(tab, n, metoda);

        // Wyœwietlanie posortowanej tablicy
        cout << "Posortowane liczby:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << tab[i] << " ";
        }
        cout << endl;

        delete[] tab; // Zwolnienie pamiêci zaalokowanej dla tablicy

        break;
    }
    default:
        cout << "Nieprawid³owy wybór!" << endl;
    }

    return 0;
}
