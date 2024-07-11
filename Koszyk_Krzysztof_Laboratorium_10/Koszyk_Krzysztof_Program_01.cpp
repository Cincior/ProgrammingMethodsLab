#include <iostream>
#include "libExceptions.h"
#include "libFile.h"
#include "StatesTree.h"
#include "libValidate.h"

using namespace std;

int main()
{
	ifstream fileRead = f_openFileToRead("inputMain");

	double W;
	try
	{
		fileRead >> W;
		if (!f_isNumberPositive(W) || fileRead.fail())
		{
			throw EXCEPTION_CODE::readError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return -1;
	}

	int n;
	try
	{
		fileRead >> n;
		if (!f_isNumberPositive(n) || fileRead.fail())
		{
			throw EXCEPTION_CODE::readError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return -1;
	}
	Item i1;

	vector<Item> items;
	items.push_back(i1); // wrzucenie pod ineks 0 by uzgodnic indeksowanie póŸniej

	while (!fileRead.eof())
	{
		Item item;
		try
		{
			fileRead >> item.P;
			fileRead >> item.W;
			fileRead >> item.ratioPW;
			if (!f_isNumberPositive(item.P) || !f_isNumberPositive(item.W) || fileRead.fail())
			{
				throw EXCEPTION_CODE::readError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return -1;
		}


		items.push_back(item);
	}





	Node* root = f_initializeRoot(items, W);
	Node* answer = nullptr;
	f_createTree(n + 1, 1, root, items, W, answer);
	f_printTree(root, n + 1);

	cout << "Indeksy przedmiotow, ktore powinny zostac upakowane:\n";
	while (answer->up != nullptr)
	{
		if (answer->position % 2 != 0)
		{
			cout << answer->depth << " ";
		}
		answer = answer->up;
	}



	return 0;
}
