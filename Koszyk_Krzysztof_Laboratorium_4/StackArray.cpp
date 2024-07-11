#include "StackArray.h"

StackArray::StackArray(int amountOfElements)
{
	elements = f_createArray(amountOfElements);
	currentIndex = -1;
	size = amountOfElements;
}
bool StackArray::isEmpty()
{
	if (currentIndex == -1)
	{
		cout << "Stos jest pusty!\n";
		return true;
	}
	else
	{
		return false;
	}
}
int StackArray::amountOfElements()
{
	return currentIndex + 1;
}
int StackArray::getTop()
{
	if (currentIndex != -1)
	{
		return elements[currentIndex];
	}
	else
	{
		cout << "\nNie ma zadnego elementu!";
		return -1;
	}
}
void StackArray::push(int v)
{
	if ((currentIndex + 1) < size)
	{
		currentIndex++;
		elements[currentIndex] = v;
	}
	else // Jeœli nie ma miejsca na nowy element, powieksza talibce dwukrotnie
	{
		int* tempArray = f_createArray(size * 2);
		for (int i = 0; i < size; i++)
		{
			tempArray[i] = elements[i];
		}
		size *= 2;
		elements = tempArray;
		currentIndex++;
		elements[currentIndex] = v;

		delete[] tempArray;
	}
}
int StackArray::pop()
{
	if (!isEmpty())
	{
		int x = elements[currentIndex];
		elements[currentIndex] = 0;
		currentIndex--;
		return x;
	}
	else
	{
		cout << "Stos jest pusty!\n";
		return -1;
	}
}
