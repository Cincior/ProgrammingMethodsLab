#include <iostream>
#include <string>
#include "libFile.h"
#include "libArray.h"
#include "iomanip"
#include "libEngineSearch.h"

using namespace std;

int main()
{
    const int r = 2, c = 106; // ilosc wierszy i kolumn w siatce
    int errorCount = 0;

    string fileName, fileNamePattern, fileNameResults;
    
    
    while(errorCount < 3)
    {
        cout << "Podaj nazwe pliku z siatkami: \n";
        cin >> fileName;
        cout << "Podaj nazwe pliku z siatka identyfikacyjna: \n";
        cin >> fileNamePattern;
        cout << "Podaj nazwe pliku, do ktorego maja zostac zapisane dane wynikowe: \n";
        cin >> fileNameResults;
        if (!f_findBestEngineMatch(fileName, fileNamePattern, fileNameResults)) 
        {
            cout << "Podles zle nazwy plikow!\n";
            errorCount++; //Jesli uzytkownik 3 razy wpisze z³e nazwy pliku, program zakonczy dzialanie 
        }
        else
        {
            break;
        }
    }
    
    return 0;
}