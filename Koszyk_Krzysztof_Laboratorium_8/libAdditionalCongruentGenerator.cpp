#include "libAdditionalCongruentGenerator.h"

vector<int> f_AdditionalCongruentGenerator(int n, int m)
{
	int k, j;
	vector<int> pair = f_findBestPair(n);
	cout << pair[0] << pair[1];

	j = pair[0] - 1;
	k = pair[1] - 1;

	vector<int> X(n, 0);
	X = f_linearCongruentialGenerator(n);
	if (X[0] == -1)
	{
		cout << "Blad!";
		return { -1 };
	}

	X[0] = 2;
	X[1] = 5;
	X[2] = 1;
	X[3] = 7;
	X[4] = 4;
	X[5] = 3;
	vector<int> Y(n, 0);
	int indexHelper = n - 1;
	for (int i = 0; i < n; i++)
	{
		Y[i] = X[indexHelper];
		indexHelper--;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		Y[i] = (Y[j] + Y[k]) % m;

		k--;
		j--;
		if (j == -1)
		{
			j = n - 1;
		}
		else if (k == -1)
		{
			k = n - 1;
		}
	}

	return Y;
}

vector<int> f_findBestPair(int n)
{
	vector<int> pair = {-1, -1};
	ifstream fileRead = f_openFileToRead("pairs");

	int firstNumber, secondNumber;
	fileRead >> firstNumber;
	fileRead >> secondNumber;
	pair[0] = firstNumber;
	pair[1] = secondNumber;

	int maxLenght;
	maxLenght = pair[1] - pair[0];

	while (!fileRead.eof())
	{
		fileRead >> firstNumber;
		fileRead >> secondNumber;
		
		if (secondNumber < n)
		{
			if (maxLenght <= secondNumber - firstNumber)
			{
				pair[0] = firstNumber;
				pair[1] = secondNumber;
				maxLenght = secondNumber - firstNumber;
			}
		}
	}
	return pair;
}
