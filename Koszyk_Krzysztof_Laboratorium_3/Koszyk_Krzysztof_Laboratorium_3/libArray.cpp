#include "libArray.h"
#include <iomanip>

long long* f_createArray(int sizeArray)
{
	long long* T = nullptr;

    try {
        T = new long long[sizeArray];
    }
    catch (std::bad_alloc)
    {
        std::cerr << "\n Brak miejsca";
        (void)getchar();
        exit(0);
    }
    return T;
}

double** f_createArrayDouble(int sizeArrayRow, int sizeArrayColumn)
{
	double** T = nullptr;
	try
	{
		T = new double* [sizeArrayRow];
		for (int i = 0; i < sizeArrayRow; i++)
		{
			T[i] = new double[sizeArrayColumn];
		}
	}
	catch (std::bad_alloc er)
	{
		std::cerr << er.what();
		exit(0);
	}

	return T;
}

double** f_copyArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn)
{
	double** newT = new double*[sizeArrayRow];

	for (int i = 0; i < sizeArrayRow; i++)
	{
		newT[i] = new double[sizeArrayColumn];
	}
	for (int i = 0; i < sizeArrayRow; i++)
	{
		for (int j = 0; j < sizeArrayColumn; j++)
		{
			newT[i][j] = tab[i][j];
		}
	}
	return newT;
}

void f_deleteArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn)
{

	for (int i = 0; i < sizeArrayRow; ++i) 
	{
		delete[] tab[i];
	}
	delete[] tab;
	
}

void f_printArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn)
{
	for (int i = 0; i < sizeArrayRow; i++)
	{
		for (int j = 0; j < sizeArrayColumn; j++)
		{
			std::cout << std::setprecision(12) << tab[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void f_printArray(int* tab, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		std::cout << tab[i] << " ";
	}
}
