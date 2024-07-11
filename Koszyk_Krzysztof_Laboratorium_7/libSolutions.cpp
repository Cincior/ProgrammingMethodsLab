#include "libSolutions.h"
#include <iostream>

vector<int> f_iterPier(vector<vector<int>> dataArray, int searchedValue)
{
	vector<int> foundedIndexes = {-1, -1};
	
	for (int i = 0; i < dataArray.size(); i++)
	{
		//Binary Search - Ze wzglêdu na treœæ zadania nie u¿ywam osobnej funkcji
		int midIndex;
		int start = 0;
		int end = dataArray[i].size() - 1;
		int colIndex = -1;
		while (start <= end) // wyszukiwanie elementu
		{
			midIndex = (start + end) / 2;
			if (dataArray[i][midIndex] > searchedValue)
			{
				end = midIndex - 1;
			}
			else if (dataArray[i][midIndex] < searchedValue)
			{
				start = midIndex + 1;
			}
			else
			{
				colIndex = midIndex;
				break;
			}
		}
		if (colIndex != -1) // jesli w danym wierszu jest dana liczba, to znajdz jej pierwsze wystapienie leksykograficzne
		{
			while (colIndex > 0 && dataArray[i][colIndex - 1] == searchedValue)
			{
				colIndex--;
			}
		}



		if (colIndex == -1)
		{
			continue;
		}
		else
		{
			foundedIndexes[0] = i;
			foundedIndexes[1] = colIndex;
			break;
		}
	}
	return foundedIndexes;
}

vector<int> f_iterOst(vector<vector<int>> dataArray, int searchedValue)
{
	vector<int> foundedIndexes = { -1, -1 };
	for (int i = (dataArray.size() - 1); i >= 0; i--) // zaczynamy od ostatniego wiersza
	{
		//Binary Search Last
		int midIndex;
		int start = 0;
		int end = dataArray[i].size() - 1;
		int colIndex = -1;
		while (start <= end) // wyszukiwanie elementu
		{
			midIndex = (start + end) / 2;
			if (dataArray[i][midIndex] > searchedValue)
			{
				end = midIndex - 1;
			}
			else if (dataArray[i][midIndex] < searchedValue)
			{
				start = midIndex + 1;
			}
			else
			{
				colIndex = midIndex;
				break;
			}
		}
		if (colIndex != -1) // jesli w danym wierszu jest dana liczba, to znajdz jej ostatnie wystapienie leksykograficzne
		{
			while (colIndex < dataArray[i].size() - 1 && dataArray[i][colIndex + 1] == searchedValue)
			{
				colIndex++;
			}
		}



		if (colIndex == -1)
		{
			continue;
		}
		else
		{
			foundedIndexes[0] = i;
			foundedIndexes[1] = colIndex;
			break;
		}
	}

	return foundedIndexes;
}


int f_binarySearchRecursionFirst(vector<int> dataRow, int start, int end, int searchedValue) 
{
	if (start > end) 
	{
		return -1;
	}

	int midIndex = (start + end) / 2;

	if (searchedValue > dataRow[midIndex]) 
	{
		return f_binarySearchRecursionFirst(dataRow, midIndex + 1, end, searchedValue);
	}
	else if (searchedValue < dataRow[midIndex]) 
	{
		return f_binarySearchRecursionFirst(dataRow, start, midIndex - 1, searchedValue);
	}
	else
	{
		if (midIndex == 0 || dataRow[midIndex - 1] != searchedValue)
		{
			return midIndex;
		}
		else
		{
			return f_binarySearchRecursionFirst(dataRow, start, midIndex - 1, searchedValue);
		}
	}
}

int f_binarySearchRecursionLast(vector<int> dataRow, int start, int end, int searchedValue)
{
	if (start > end)
	{
		return -1;
	}

	int midIndex = (start + end) / 2;

	if (searchedValue > dataRow[midIndex])
	{
		return f_binarySearchRecursionFirst(dataRow, midIndex + 1, end, searchedValue);
	}
	else if (searchedValue < dataRow[midIndex])
	{
		return f_binarySearchRecursionFirst(dataRow, start, midIndex - 1, searchedValue);
	}
	else
	{
		if (midIndex == dataRow.size() - 1 || dataRow[midIndex + 1] != searchedValue)
		{
			return midIndex;
		}
		else
		{
			return f_binarySearchRecursionLast(dataRow, midIndex + 1, end, searchedValue);
		}
	}
}

vector<int> f_rekPier(vector<vector<int>> dataArray, int row, int searchedValue)
{
	if (row >= dataArray.size())
	{
		return { -1, -1 }; // skonczyla sie tablica elementow
	}
	int foundedColIndex = f_binarySearchRecursionFirst(dataArray[row], 0, dataArray[row].size() - 1, searchedValue);

	if (foundedColIndex != -1)
	{
		return { row, foundedColIndex };
	}
	else
	{
		return f_rekPier(dataArray, row + 1, searchedValue);
	}
}

vector<int> f_rekOst(vector<vector<int>> dataArray, int row, int searchedValue)
{
	if (row == -1)
	{
		return { -1, -1 }; // skonczyla sie tablica elementow
	}
	int foundedColIndex = f_binarySearchRecursionLast(dataArray[row], 0, dataArray[row].size() - 1, searchedValue);

	if (foundedColIndex != -1)
	{
		return { row, foundedColIndex };
	}
	else
	{
		return f_rekOst(dataArray, row - 1, searchedValue);
	}
}