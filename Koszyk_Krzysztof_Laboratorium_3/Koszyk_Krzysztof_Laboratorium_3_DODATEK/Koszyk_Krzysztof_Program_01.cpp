#include <iostream>
#include "libArray.h"
#include "libFile.h"
#include "libSubset.h"

using namespace std;

int main()
{
    int choice = 0, n = 0;
    cout << "Wybierz opjce:\n1. Wszystkie podzbiory.\n2. k-elementowe podzbiory.\n3. Podzia³y liczby n\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Podaj ilosc elementow zboiru:\n";
            cin >> n;
            if (f_getAllSubsets(n))
            {
                cout << "Pomyslnie zapisano dane do pliku\n";
            }
            else
            {
                cout << "Nie udalo sie poprawnie zapisac danych!";
                break;
            }
            break;
        case 2:
            cout << "Podaj ilosc elementow zboiru:\n";
            cin >> n;
            int k;
            cout << "Podaj ilosc elementow PODzbioru\n";
            cin >> k;
            if (k > n)
            {
                cout << "Ilosc elementow zbioru nie moze byc mniejsza niz ilosc elementow podzbioru";
                break;
            }
            else
            {
                if (f_getKSubsets(n, k))
                {
                    cout << "Pomyslnie zapisano dane do pliku\n";
                }
                else
                {
                    cout << "Nie udalo sie poprawnie zapisac danych!";
                    break;
                }
            }
            break;
        case 3:
            cout << "Podaj liczbe n:\n";
            cin >> n;
            if (f_getPartsN(n))
            {
                cout << "Pomyslnie zapisano dane do pliku\n";
            }
            else
            {
                cout << "Nie udalo sie poprawnie zapisac danych!";
                break;
            }
            break;
        default:
            cout << "Wybrano bledny numer!";
            break;

    };

}