#include <fstream>
#include "libEngineSearch.h"
#include "libFile.h"
#include "libArray.h"
#include <iomanip>


bool f_findBestEngineMatch(string fileName, string fileNamePattern, string fileNameResults)
{
	const int r = 2, c = 106; // ilosc wierszy i kolumn w siatce
    
    ifstream fileRead = f_openFileToRead(fileName);
    ifstream filePattern = f_openFileToRead(fileNamePattern);

    if (fileRead.is_open() == false || filePattern.is_open() == false) // Jesli ktorys z plikow nie zostal otwarty - nazwa zosta³a podana nieprawid³owo - to zwraca 0
    {
        return 0;
    }

    ofstream fileResults = f_openFileToWrite(fileNameResults);
    double** tablicaNM = f_createArrayDouble(r, c);
    double** tablicaSiatka = f_createArrayDouble(r, c);
    double** tablicaSiatka_Kandydat = nullptr; // kandydat na najlepsze dopasowanie

	for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            filePattern >> tablicaNM[i][j];
        }
    }
    double Mse1 = INT_MAX, Mse2 = 0, x, y;
    fileResults << "Wartoœci b³êdów mse dla ka¿dej z siatek:\n\n";
    for (int l = 0; l < 81; l++)
    {
        Mse2 = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                fileRead >> tablicaSiatka[i][j];
            }
        }
        for (int i = 6; i < c; i++) //Obliczanie bledu mse dla danej siatki
        {
            y = tablicaSiatka[0][i] - tablicaNM[0][i];
            x = tablicaSiatka[1][i] - tablicaNM[1][i];
            y = y * y;
            x = x * x;
            Mse2 += x + y;
        }
        Mse2 = sqrt(Mse2);
        fileResults << Mse2 << " ";
        if (Mse1 > Mse2)
        {
            Mse1 = Mse2;
            tablicaSiatka_Kandydat = f_copyArrayDouble(tablicaSiatka, r, c); //przechowanie danych, ktore potencjalnie mog¹ byæ najlepszym odwzorowaniem
        }
    }
    fileResults << "\n\nMinimalny b³¹d mse: " << Mse1 << "\n\nWektor Y, X z wszystkimi danymi najlepszego dopasowania:\n\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fileResults << setprecision(12) << tablicaSiatka_Kandydat[i][j] << "\t"; //setprecision(12) by wziac pod uwage kazda cyfre po przecinku.
        }
        fileResults << "\n\n";
    }


    fileResults.close();
    filePattern.close();
    fileRead.close();
    f_deleteArrayDouble(tablicaNM, r, c);
    f_deleteArrayDouble(tablicaSiatka, r, c);
    f_deleteArrayDouble(tablicaSiatka_Kandydat, r, c);
    return 1;
}
