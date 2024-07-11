// Koszyk Krzysztof
#include <iostream>
#include <vector>
#include "libExceptions.h"
#include "libSolutions.h"

using namespace std;

int main()
{
	int tries = 0; //ilosc prob wprowadzenia poprawnyej ilosci zestawow danych

	int amountOfSets;

	while (tries < 3)
	{
		try
		{
			//cout << "Podaj ilosc zestawow: \n";
			cin >> amountOfSets;

			if (amountOfSets <= 0) // dana ma byc tylko wieksza od 0 bo int zrzutuje na calkowita
			{
				throw EXCEPTION_CODE::outOfRangeError;
			}
			else
			{
				tries = 3;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			showException(error);
			tries++;
		}
	}

	if(tries > 3)
	{ 
		return -1;
	}

	int rows, cols;

	string* allResults = new string[(amountOfSets * 4)];
	int indexHelper = 0;

	for (int i = 0; i < amountOfSets; i++)
	{
		try
		{
			//cout << "Podaj ilosc wierszy i kolumn:\n";
			cin >> rows;
			cin >> cols;

			if (rows < 1 || rows > 100 || cols < 1 || cols > 100)
			{
				throw EXCEPTION_CODE::outOfRangeError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return -1;
		}


		vector<vector<int>> dataArray;
		for (int i = 0; i < rows; ++i)
		{
			vector<int> col;
			dataArray.push_back(col);
		}
		int inputValue, searchedValue;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				try
				{
					cin >> inputValue;
					if (inputValue < (-pow(2, 15)) || inputValue > pow(2, 15))
					{
						throw EXCEPTION_CODE::outOfRangeError;
					}
					else
					{
						dataArray[i].push_back(inputValue);
					}
				}
				catch (EXCEPTION_CODE error)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					showException(error);
					j--; // by ponowiæ próbe wpisania danej
					continue;
				}
			}
		}

		try
		{
			cin >> searchedValue;
			if (std::cin.fail())
			{
				throw EXCEPTION_CODE::numberError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return -1;
		}

		// Wywolanie i przygotowanie stringa na wyjscie dla poszczególnych funkcji:

		vector<int> foundedIndexesIterPier = f_iterPier(dataArray, searchedValue);
		string outputIterPier = "IterPier: ";
		if (foundedIndexesIterPier[0] != -1 && foundedIndexesIterPier[1] != -1)
		{
			outputIterPier += to_string(searchedValue) + " w (" + to_string(foundedIndexesIterPier[0]) + ", " + to_string(foundedIndexesIterPier[1]) + ")";
		}
		else
		{
			outputIterPier += "nie ma " + to_string(searchedValue);
		}

		vector<int> foundedIndexesIterOst = f_iterOst(dataArray, searchedValue);
		string outputIterOst = "IterOst: ";
		if (foundedIndexesIterOst[0] != -1 && foundedIndexesIterOst[1] != -1)
		{
			outputIterOst += to_string(searchedValue) + " w (" + to_string(foundedIndexesIterOst[0]) + ", " + to_string(foundedIndexesIterOst[1]) + ")";
		}
		else
		{
			outputIterOst += "nie ma " + to_string(searchedValue);
		}

		vector<int> foundedIndexesRekPier = f_rekPier(dataArray, 0, searchedValue);
		string outputRekPier = "RekPier: ";
		if (foundedIndexesRekPier[0] != -1 && foundedIndexesRekPier[1] != -1)
		{
			outputRekPier += to_string(searchedValue) + " w (" + to_string(foundedIndexesRekPier[0]) + ", " + to_string(foundedIndexesRekPier[1]) + ")";
		}
		else
		{
			outputRekPier += "nie ma " + to_string(searchedValue);
		}

		vector<int> foundedIndexesRekOst = f_rekOst(dataArray, dataArray.size() - 1, searchedValue);
		string outputRekOst = "RekOst: ";
		if (foundedIndexesRekOst[0] != -1 && foundedIndexesRekOst[1] != -1)
		{
			outputRekOst += to_string(searchedValue) + " w (" + to_string(foundedIndexesRekOst[0]) + ", " + to_string(foundedIndexesRekOst[1]) + ")";
		}
		else
		{
			outputRekOst += "nie ma " + to_string(searchedValue);
		}

		/*cout << outputRekPier << "\n";
		cout << outputRekOst << "\n";
		cout << outputIterPier << "\n";
		cout << outputIterOst << "\n";
		cout << "---\n";*/

		allResults[indexHelper] = outputRekPier;
		indexHelper++;
		allResults[indexHelper] = outputRekOst;
		indexHelper++;
		allResults[indexHelper] = outputIterPier;
		indexHelper++;
		allResults[indexHelper] = outputIterOst;
		indexHelper++;
	}

	for (int i = 1; i < indexHelper + 1; i++) 
	{
		cout << allResults[(i - 1)] << endl;
		if (i % 4 == 0)
		{
			cout << "---\n";
		}
	}

	
}