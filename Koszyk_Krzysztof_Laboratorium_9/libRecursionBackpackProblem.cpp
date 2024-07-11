#include "libRecursionBackpackProblem.h"



void f_findSequence(std::vector<int>& result, std::vector<int>remaining, std::vector<int> elementsWeight, int n, int capacityLeft)
{
	if (capacityLeft == 0)
	{
		result = remaining;
	}
	if (n == 0 || capacityLeft == 0)
	{ 
		return; 
	}
	if (result.size() == 0) //przeszukiwanie z przeskoczeniem obecnego elementu
	{
		f_findSequence(result, remaining, elementsWeight, n - 1, capacityLeft);
	} 

	remaining.push_back(elementsWeight[n - 1]);

	if (result.size() == 0) //przeszukiwanie z obecnym elementem
	{
		f_findSequence(result, remaining, elementsWeight, n - 1, capacityLeft - elementsWeight[n - 1]);
	}
}

void f_recursionBackpackProblem()
{
	ifstream fileRead = f_openFileToRead("inputP2");

	int amountOfSets;
	try
	{
		fileRead >> amountOfSets;
		if (!f_isNumberVaild(amountOfSets) || fileRead.fail())
		{
			throw EXCEPTION_CODE::readError;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		showException(error);
		return;
	}

	int backpackCapacity;
	int amountOfElements;
	vector<int> elementsWeight;

	for (int i = 0; i < amountOfSets; i++)
	{
		try
		{
			fileRead >> backpackCapacity;
			fileRead >> amountOfElements;
			if (!f_isNumberVaild(backpackCapacity) || !f_isNumberVaild(amountOfElements) || fileRead.fail())
			{
				throw EXCEPTION_CODE::readError;
			}
		}
		catch (EXCEPTION_CODE error)
		{
			showException(error);
			return;
		}

		for (int j = 0; j < amountOfElements; j++)
		{
			int temp;
			try
			{
				fileRead >> temp;
				if (!f_isNumberVaild(temp) || fileRead.fail())
				{
					throw EXCEPTION_CODE::readError;
				}
			}
			catch (EXCEPTION_CODE error)
			{
				showException(error);
				return;
			}
			elementsWeight.push_back(temp);
		}

		//reverse(elementsWeight.begin(), elementsWeight.end());
		
		std::vector<int> result, test;
		f_findSequence(result, test, elementsWeight, amountOfElements, backpackCapacity);
		elementsWeight.clear();
		if (result.empty())
		{
			cout << "BRAK\n";
		}
		else 
		{
			cout << backpackCapacity << " = ";
			reverse(result.begin(), result.end()); // odwrócenie kolejnosci dla poprawnego wyswietlenia, bo rekurencja zrobila na odwrót
			for (int el : result)
			{
				std::cout << el << " ";
			}
			std::cout << "\n";
		}

	}

}


bool f_isNumberVaild(int number)
{
	if (number < 1 || number > 1000000)
	{
		return false;
	}
	return true;
}