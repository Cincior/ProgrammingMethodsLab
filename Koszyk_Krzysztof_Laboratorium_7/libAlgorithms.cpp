#include "libAlgorithms.h"

int f_BinarySearch(vector<int> dataRow, int findingValue)
{
	int midIndex = dataRow.size() / 2;
	int start = 0;
	int end = dataRow.size() - 1;
	int foundedIndex = -1;
	while (start <= end) // wyszukiwanie elementu
	{
		if (dataRow[midIndex] > findingValue)
		{
			end = midIndex - 1;
		}
		else if (dataRow[midIndex] < findingValue)
		{
			start = midIndex + 1;
		}
		else
		{
			foundedIndex = midIndex;
			break;
		}
		midIndex = (start + end) / 2;
	}
	if (foundedIndex != -1) // jesli w danym wierszu jest dana liczba, to znajdz jej pierwsze wystapienie leksykograficzne
	{
		while (dataRow[foundedIndex - 1] == findingValue)
		{
			foundedIndex--;
		}
		return foundedIndex;
	}
	return -1; // Jesli nie udalo sie znalezc elementu zwracamy -1
}

int f_BinarySearchLast(vector<int> dataRow, int findingValue)
{
	int midIndex = dataRow.size() / 2;
	int start = 0;
	int end = dataRow.size() - 1;
	int foundedIndex = -1;
	while (start <= end) // wyszukiwanie elementu
	{
		if (dataRow[midIndex] > findingValue)
		{
			end = midIndex - 1;
		}
		else if (dataRow[midIndex] < findingValue)
		{
			start = midIndex + 1;
		}
		else
		{
			foundedIndex = midIndex;
			break;
		}
		midIndex = (start + end) / 2;
	}
	if (foundedIndex != -1) // jesli w danym wierszu jest dana liczba, to znajdz jej ostatnie wystapienie leksykograficzne
	{
		while (dataRow[foundedIndex + 1] == findingValue)
		{
			foundedIndex++;
		}
		return foundedIndex;
	}
	return -1; // Jesli nie udalo sie znalezc elementu zwracamy -1
}
