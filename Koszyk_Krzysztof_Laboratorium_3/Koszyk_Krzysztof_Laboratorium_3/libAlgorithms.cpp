#include "libAlgorithms.h"
#include "libArray.h"

int f_BindarySearch(long long* T, int n, int el)
{
	int midIndex = n / 2;
	int start = 0;
	int end = n - 1;
	while (start <= end) // wyszukiwanie elementu
	{
		if (T[midIndex] > el)
		{
			end = midIndex - 1;
		}
		else if (T[midIndex] < el)
		{
			start = midIndex + 1;
		}
		else
		{
			return midIndex;
		}
		midIndex = (start + end) / 2;
	}
	return -1; // Jesli nie udalo sie znalezc elementu zwracamy -1
}

int f_BindarySearchAll(long long* T, int n, int el)
{
	int midIndex = f_BindarySearch(T, n, el);
	int counter = 0; // ilosc elementow

	//Wyszukiwanie wszystkich wyst¹pieñ elementu
	if (midIndex != -1)
	{
		counter++;
		int right = midIndex + 1, left = midIndex - 1;
		while (T[right] == el)
		{
			counter += 1;
			right++;
		}
		while (T[left] == el)
		{
			counter += 1;
			left--;
		}
	}
	return counter;
}

int f_interpolationSearch(long long* T, int n, int el)
{
	int start = 0;
	int end = n - 1;
	int midIndex;
	while (T[start] <= el && T[end] >= el) // wyszukiwanie elementu
	{
		midIndex = ((el - T[start]) * (end - start)) / (T[end] - T[start]) + start;
		if (T[midIndex] > el)
		{
			end = midIndex - 1;
		}
		else if (T[midIndex] < el)
		{
			start = midIndex + 1;
		}
		else
		{
			return midIndex;
		}
		
	}
	return -1; // Jesli nie udalo sie znalezc elementu zwracamy -1
}

long long* f_removeDuplicates(long long* T, int n, int& sizeArrayMax)
{
	int currentIndex = 0;
	long long* noDuplicates = f_createArray(n);
	noDuplicates[0] = T[0];
	for (int i = 1; i < n; i++)
	{
		if (noDuplicates[currentIndex] != T[i])
		{
			currentIndex++;
			noDuplicates[currentIndex] = T[i];
		}
	}
	sizeArrayMax = currentIndex + 1;
	return noDuplicates;
}
