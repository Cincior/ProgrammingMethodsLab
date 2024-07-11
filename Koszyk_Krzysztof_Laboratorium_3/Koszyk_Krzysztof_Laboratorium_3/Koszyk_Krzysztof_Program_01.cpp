#include <iostream>
#include <array>
#include "libArray.h"
#include "libFile.h"
#include "libAlgorithms.h"
#include "libValidate.h"
#include "libGenerateFile.h"

using namespace std;

int main()
{
	string fileName;
	cout << "Podaj nazwe pliku z ktorego chcesz zaczytac dane:\n";
	cin >> fileName;
	ifstream fileRead = f_openFileToRead(fileName);
	if (fileRead.is_open())
	{
		int AmountOfSets;
		fileRead >> AmountOfSets; // odczytanie ilosci zestawow
		if (!f_validateInteger(AmountOfSets, 1, pow(2, 15)))
		{
			exit(0);
		}

		for (int set = 0; set < AmountOfSets; set++)
		{
			int sizeArr;
			fileRead >> sizeArr; // odczytanie wielkosci tablicy

			if (!f_validateInteger(sizeArr, 1, pow(2, 15)))
			{
				exit(0);
			}

			long long* T = new long long[sizeArr];
			for (int i = 0; i < sizeArr; i++)
			{
				long long v;
				fileRead >> v;
				if (!f_validateInteger(v, -1 * (pow(2, 48)), pow(2, 48)))
				{
					cout << " xd";
					exit(0);
				}
				T[i] = v; // odczytanie danych
			}

			int AmountOfQuery;
			fileRead >> AmountOfQuery; // ilosc danych do wyszukania

			if (!f_validateInteger(AmountOfQuery, 1, pow(2, 15)))
			{
				exit(0);
			}

			long long* Queries = new long long[AmountOfQuery];
			for (int i = 0; i < AmountOfQuery; i++)
			{
				long long v;
				fileRead >> v;
				if (!f_validateInteger(v, -1 * (pow(2, 48)), pow(2, 48)))
				{
					exit(0);
				}
				Queries[i] = v; // zaczytanie liczb do wyszukania
			}

			ofstream fileWrite = f_openFileToWrite("out.txt");
			int Occurs, foundIdx;
			for (int i = 0; i < AmountOfQuery; i++)
			{
				Occurs = f_BindarySearchAll(T, sizeArr, Queries[i]);
				foundIdx = (Occurs == sizeArr ? 0 : f_interpolationSearch(T, sizeArr, Queries[i]));
				fileWrite << "(" << Occurs << " " << foundIdx << ") ";
			}
			fileWrite << "\n";
			int sizeArrayMax = 0;
			long long * NoDuplicatesArray = f_removeDuplicates(T, sizeArr, sizeArrayMax);
			sizeArrayMax = sizeArrayMax > 200 ? 200 : sizeArrayMax; // jesli ma wiecej niz 200 elementow to skroc do 200
			for (int i = 0; i < sizeArrayMax; i++)
			{
				if (i % 50 == 0 && i != 0)
				{
					fileWrite << "\n";
				}
				fileWrite << NoDuplicatesArray[i] << " ";
			}
		}
		cout << "Pomyslnie wpisano dane do pliku";

	}
	else
	{
		cout << "Niepowodzenie!\n";
	}
	
	//f_GenerateFile("moj.txt"); //Funkcja wygeneruje plik z 1000 danych i 100 elementow szukanych
	

	
	return 0;
}