#include <iostream>
#include <vector>
#include "BitmapaExt.h"
#include "ZlozeniePrzeksztalcen.h"
#include "Przeksztalcenie.h"
#include "Inwersja.h"
#include "Zerowanie.h"
#include "Erozja.h"
#include "Dylatacja.h"
#include "Usrednianie.h"
using namespace std;

// Funkcja do wyœwietlania menu i pobierania wyboru u¿ytkownika
vector<Przeksztalcenie*> wyswietlMenu();

int main() {
    BitmapaExt aa(5, 5);
    aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;
    cout << aa << "\n";

    // Wyœwietlanie menu i pobieranie wyboru u¿ytkownika
    vector<Przeksztalcenie*> przeksztalcenia = wyswietlMenu();

    // Wykonanie przekszta³ceñ na podstawie wyboru u¿ytkownika
    if (!przeksztalcenia.empty()) {
        ZlozeniePrzeksztalcen z;
        for (Przeksztalcenie* p : przeksztalcenia) {
            z.dodajPrzeksztalcenie(p);
        }
        z.przeksztalc(aa);
    }

    cout << aa << "\n";

    // Zwolnienie pamiêci zaalokowanej na obiekty przekszta³ceñ
    for (Przeksztalcenie* p : przeksztalcenia) {
        delete p;
    }

    return 0;
}


vector<Przeksztalcenie*> wyswietlMenu() {
    vector<Przeksztalcenie*> przeksztalcenia;

    cout << "Wybierz funkcje do uruchomienia:" << endl;
    cout << "1. Inwersja" << endl;
    cout << "2. Erozja" << endl;
    cout << "3. Dylatacja" << endl;
    cout << "4. Zerowanie" << endl;
    cout << "5. Usrednianie" << endl;
    cout << "0. Wyjscie" << endl;
    cout << "Podaj numer funkcji: ";

    int wybor;
    while (cin >> wybor && wybor != 0) {
        switch (wybor) {
        case 1:
            przeksztalcenia.push_back(new Inwersja());
            break;
        case 2:
            przeksztalcenia.push_back(new Erozja());
            break;
        case 3:
            przeksztalcenia.push_back(new Dylatacja());
            break;
        case 4:
            przeksztalcenia.push_back(new Zerowanie());
            break;
        case 5:
            przeksztalcenia.push_back(new Usrednianie());
            break;
        default:
            cout << "Niepoprawny wybór. Spróbuj ponownie." << endl;
            break;
        }
        cout << "Podaj kolejny numer funkcji lub wpisz 0, aby zakoñczyæ: ";
    }

    return przeksztalcenia;
}