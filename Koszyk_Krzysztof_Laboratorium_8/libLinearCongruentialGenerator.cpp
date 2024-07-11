#include "libLinearCongruentialGenerator.h"


vector<int> f_linearCongruentialGenerator(int n)
{
    int Xmax;
	try
	{
		cout << "Wprowadx Xmax:\n";
		cin >> Xmax;
		if (Xmax < 0 || cin.fail())
		{
			throw EXCEPTION_CODE::numberError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return { -1 };
	}

	int m = Xmax + 1; // jeœli Xmax >= 0, m > 0
    
	int seedX0;
	try
	{
		cout << "Wprowadz seed:\n"; //wporowadzanie z klawiatury
		cin >> seedX0;
		if (seedX0 < 0 || seedX0 >= m || cin.fail())
		{
			throw EXCEPTION_CODE::numberError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return { -1 };
	}

	

	// dobór mo¿liwie najwy¿szego c
	int c = f_createC(m);
	if (c == -1)
	{
		cout << "Blad doboru czynnika c";
		return { -1 };
	}

	// dobór a
	int a = f_createA(m);
	if (a == -1)
	{
		cout << "Blad doboru czynnika a";
		return { -1 };
	}

	vector<int> pseudoRandomNumbers;
	int Xn = (a * seedX0 + c) % m;
	for (int i = 0; i < n; i++)
	{
		pseudoRandomNumbers.push_back(Xn);
		Xn = (a * Xn + c) % m;
	}

    return pseudoRandomNumbers;
}

//funkcja oblicza najwiêkszy wspólny dzielnik liczb a i b
//int NWD(int a, int b)
//{
//	int pom;
//
//	while (b != 0)
//	{
//		pom = b;
//		b = a % b;
//		a = pom;
//	}
//
//	return a;
//}
//
//int f_createC(int m)
//{
//	int c = 2;
//
//	while (NWD(c, m) != 1)
//	{
//		c++;
//	}
//	return c;
//}

int f_createC(int m)
{
	int c = m - 1;

	try
	{
		set<int> cPrimeFactors = f_PrimeFactors(c);
		set<int> mPrimeFactors = f_PrimeFactors(m);
		if (mPrimeFactors.count(-1) == 1 || cPrimeFactors.count(-1) == 1)
		{
			cout << "Blad rozkladu na czynniki pierwsze!";
			return -1;
		}
		while (f_commonDivisior(mPrimeFactors, cPrimeFactors)) // czynniki c ró¿ne od czynnikow modu³u m
		{
			c--;
			cPrimeFactors = f_PrimeFactors(c);
			if (c < 0)
			{
				throw EXCEPTION_CODE::outOfRangeError;
			}
		}

	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return -1;
	}
	return c;
}

int f_createA(int m)
{
	int a = -1;
	set<int> mPrimeFactors = f_PrimeFactors(m);
	if (mPrimeFactors.count(-1) == 1)
	{
		cout << "Blad rozkladu na czynniki pierwsze!";
		return -1;
	}

	vector<int> lambdas = f_allPossibleLambdas(m, mPrimeFactors); // dla a = 2 index w wektorze = 0
	vector<int> aWithBiggestLambda; // czynniki a, dla których lambda jest najwiêksza

	auto biggestLambda = max_element(lambdas.begin(), lambdas.end()); // najwiêksza wartoœæ lambdy ze wszystkich lambd
	if (*biggestLambda == -1)
	{
		cout << "Blad generowania wspolczynnika a!";
		return { -1 };
	}
	for (int i = 0; i < lambdas.size(); i++)
	{
		if (*biggestLambda == lambdas[i])
		{
			aWithBiggestLambda.push_back((i + 2)); // wspó³czynniki a, dla których lambda jest najwiêksza
		}
	}


	// wybieram najwieksze a, gdyby ¿adne nie spe³ni³o twierdzeñ
	int biggestA = aWithBiggestLambda[0];
	for (int i = 1; i < aWithBiggestLambda.size(); i++)
	{
		if (aWithBiggestLambda[i] > biggestA)
		{
			biggestA = aWithBiggestLambda[i];
		}
	}
	a = biggestA;

	// 1 twierdzenie sprawdzone przy wyborze wspó³czynnika c

	vector<int> tempA;
	// 2 twierdzenie
	for (int i = 0; i < aWithBiggestLambda.size(); i++)
	{
		int possibleA = aWithBiggestLambda[i];
		bool isMultiple = true;
		for (int factor : mPrimeFactors)
		{
			if (!f_isMultiple((possibleA - 1), factor))
			{
				isMultiple = false;
				break;
			}
		}
		if (isMultiple)
		{
			tempA.push_back(possibleA);
		}
	}

	aWithBiggestLambda = tempA;
	tempA = {};
	// 3 twierdzenie
	for (int i = 0; i < aWithBiggestLambda.size(); i++)
	{
		if (m % 4 == 0)
		{
			if ((aWithBiggestLambda[i] - 1) % 4 == 0)
			{
				tempA.push_back(aWithBiggestLambda[i]);
			}
			else
			{
				continue;
			}
		}
		else
		{
			tempA.push_back(aWithBiggestLambda[i]);
		}
	}

	aWithBiggestLambda = tempA;

	
	// Jesli jest jakies a, które spe³nia 3 twierdzenia to u¿ywam go
	if (!aWithBiggestLambda.empty())
	{
		a = aWithBiggestLambda[0];
	}
	return a;
}

vector<int> f_allPossibleLambdas(int m, set<int> mPrimeFactors)
{
	vector<int> PossibleLambdas;
	for (int a = 2; a < m; a++)
	{
		set<int> aPrimeFactors = f_PrimeFactors(a);
		if (f_commonDivisior(aPrimeFactors, mPrimeFactors)) // jeœli a i m maj¹ wspólny dzielnik to nie spe³niaj¹ warunków
		{
			PossibleLambdas.push_back(-1); // dla zachowania odpowiedniego indeksowania
			continue;
		}
		int lambda = 1;
		while (static_cast<int>(pow(a, lambda)) % m != 1)
		{
			lambda++;
			if (lambda > 100)
			{
				break;
			} 
		}
		PossibleLambdas.push_back(lambda);
	}
	if (PossibleLambdas.empty())
	{
		PossibleLambdas.push_back(-1);
	}

	return PossibleLambdas;
}

bool f_commonDivisior(set<int> PrimeFactorsA, set<int> PrimeFactorsB)
{
	for (int factor : PrimeFactorsA)
	{
		if (PrimeFactorsB.count(factor) == 1)
		{
			return true;
		}
	}
	return false;
}

bool f_isMultiple(int a, int b)
{
	return (a % b == 0);
}

void f_writeResultsIntoFile(string fName, vector<int> pseudoRandomNumbers)
{
	ofstream fileWrite = f_openFileToWrite(fName);
	for (int randomNumber : pseudoRandomNumbers)
	{
		fileWrite << randomNumber << "\n";
	}
	fileWrite.close();
}

set<int> f_PrimeFactors(int number) 
{
	set<int> factorsSet;

	if (number < 2)
	{
		factorsSet.insert(-1); // ERROR
		return factorsSet;
	}

	int k = 2; //ustawiamy k na pierwsz¹ liczbê pierwsz¹

	//rozk³ad liczby na czynniki pierwsze
	while (number > 1 && k <= sqrt(number))
	{
		while (number % k == 0) //dopóki liczba jest podzielna przez k
		{
			factorsSet.insert(k);
			number /= k;
		}
		++k;
	}

	if (number > 1)
	{
		factorsSet.insert(number);
	}

	return factorsSet;
}
