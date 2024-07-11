#include <iostream>
#include "libLinearCongruentialGenerator.h"
#include "libAdditionalCongruentGenerator.h"
#include "libExceptions.h"

using namespace std;

int main()
{
    int chooseMethod = -1;
    cout << "Wybierz metode:\n1. Liniowa metoda kongruencyjna LCG\n2. Addytywna metoda kongruencyjna\n3. Zakoncz program\n";
	cin >> chooseMethod;


	vector<int> generatedNumbers;
	int n;
	switch (chooseMethod)
	{
	case 1:
		
		try
		{
			cout << "Podaj n:\n";
			cin >> n;
			if (n < 0 || cin.fail())
			{
				throw EXCEPTION_CODE::numberError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return -1;
		}

		generatedNumbers = f_linearCongruentialGenerator(n);
		if (generatedNumbers[0] != -1)
		{
			cout << "wygenerowano:\n";
			for (int x : generatedNumbers)
			{
				cout << x << " ";
			}
			//wpis do pliku
			f_writeResultsIntoFile("lcgResults", generatedNumbers);
		}
		else
		{
			cout << "Wystapil blad!";
			return -1;
		}
		
		break;
	case 2:
		int m; // modu³
		try
		{
			cout << "Podaj n:\n";
			cin >> n;
			if (n < 0 || cin.fail())
			{
				throw EXCEPTION_CODE::numberError;
			}
			cout << "Podaj m:\n";
			cin >> m;
			if (m < 0 || cin.fail())
			{
				throw EXCEPTION_CODE::numberError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return -1;
		}
		generatedNumbers = f_AdditionalCongruentGenerator(n, m);
		if (generatedNumbers[0] != -1)
		{
			//wpis do pliku
			f_writeResultsIntoFile("additionalResults", generatedNumbers);
		}
		else
		{
			cout << "Wystapil blad!";
			return -1;
		}
		break;
	case 3:
		return 0;
	default:
		break;
	}
	return 0;
}
