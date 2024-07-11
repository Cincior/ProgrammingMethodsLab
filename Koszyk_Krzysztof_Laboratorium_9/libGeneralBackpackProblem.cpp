#include "libGeneralBackpackProblem.h"

void f_generalBackpackProblem()
{
	ifstream fileRead = f_openFileToRead("input");

	// Wczytanie M_max
	int maxBackpackWeight;
	try
	{
		fileRead >> maxBackpackWeight;
		if (!f_isNumberPositive(maxBackpackWeight) || fileRead.fail())
		{
			throw EXCEPTION_CODE::readError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return;
	}

	//Zaczytanie z pliku przedmiotów
	vector<Item> availableItems;

	while (!fileRead.eof())
	{
		Item item;
		try
		{
			fileRead >> item.name;
			fileRead >> item.weight;
			fileRead >> item.price;
			if (!f_isNumberPositive(item.weight) || !f_isNumberPositive(item.price) || fileRead.fail())
			{
				throw EXCEPTION_CODE::readError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return;
		}
		

		availableItems.push_back(item);
	}

	vector<vector<int>> P = f_createArrayP(availableItems, maxBackpackWeight);

	//wypisanie P
	for (int i = 1; i < P.size(); i++)
	{
		for (int j = 1; j < P[0].size(); j++)
		{
			cout << P[i][j] << "\t";
		}
		cout << "\n";
	}
	
	vector<vector<int>> Q = f_createArrayQ(availableItems, maxBackpackWeight, P);
	
	//wypisanie Q
	cout << "\n";
	for (int i = 1; i < P.size(); i++)
	{
		for (int j = 1; j < P[0].size(); j++)
		{
			cout << Q[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "Przedmioty w plecaku:\n";
	int helper = maxBackpackWeight;
	while (helper > 0)
	{
		cout << availableItems[Q[availableItems.size()][helper] - 1].name << " ";
		helper = helper - availableItems[Q[availableItems.size()][helper] - 1].weight;
	}
	
}

bool f_isNumberPositive(int number)
{
	return number < 1 ? false : true;
}

vector<vector<int>> f_createArrayP(vector<Item> availableItems, int maxBackpackWeight)
{
	vector<vector<int>> P(availableItems.size() + 1, vector<int>(maxBackpackWeight + 1, 0));

	// wpisy do P 
	// 1 wiersz
	for (int i = 1; i < P[1].size(); i++)
	{
		int maxAmountOfElement = i / availableItems[0].weight;
		if (availableItems[0].weight > i)
		{
			P[1][i] = 0;
		}
		else
		{
			P[1][i] = availableItems[0].price * maxAmountOfElement;
		}

	}

	// nastêpne wiersze
	for (int i = 2; i < P.size(); i++)
	{
		for (int j = 1; j < P[0].size(); j++)
		{
			if (availableItems[i - 1].weight > j)
			{
				P[i][j] = P[i - 1][j];
			}
			else // availableItems[i - 1].weight <= j
			{
				if (P[i - 1][j] > (P[i][j - availableItems[i - 1].weight] + availableItems[i - 1].price))
				{
					P[i][j] = P[i - 1][j];
				}
				else
				{
					P[i][j] = P[i][j - availableItems[i - 1].weight] + availableItems[i - 1].price;
				}
			}
		}
	}
	return P;
}

vector<vector<int>> f_createArrayQ(vector<Item> availableItems, int maxBackpackWeight, vector<vector<int>> P)
{
	vector<vector<int>> Q(availableItems.size() + 1, vector<int>(maxBackpackWeight + 1, 0));
	for (int i = 1; i < Q[1].size(); i++)
	{
		if (availableItems[0].weight > i)
		{
			Q[1][i] = 0;
		}
		else
		{
			Q[1][i] = 1;
		}

	}

	// nastêpne wiersze
	for (int i = 2; i < Q.size(); i++)
	{
		for (int j = 1; j < Q[0].size(); j++)
		{
			if (availableItems[i - 1].weight > j)
			{
				Q[i][j] = Q[i - 1][j];
			}
			else // availableItems[i - 1].weight <= j
			{
				if (P[i - 1][j] > (P[i][j - availableItems[i - 1].weight] + availableItems[i - 1].price))
				{
					Q[i][j] = Q[i - 1][j];
				}
				else
				{
					Q[i][j] = i;
				}
			}
		}
	}
	return Q;
}
