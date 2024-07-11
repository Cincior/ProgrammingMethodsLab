#include "libSolutions.h"
#include <iostream>

bool f(int x)
{
	return true;
}

bool f2(int x)
{
	return false;
}

const int* f_porownaj(int* a, const int* b)
{
	return (*a) > (*b) ? a : b;
}

long long silnia(int n)
{
	if (n < 2)
		return 1;

	return n * silnia(n - 1);
}

int f_wielomian(int N, const int* a, int x)
{
	if (N > 0)
	{
		return a[N] * pow(x, N) + f_wielomian(N - 1, a, x);
	}
	else
	{
		return a[0];
	}
}

const int* f_maximum(int N, const int* t)
{
	int indexN = N - 1; //index ostatniego elementu
	if (N < 0 || t == nullptr)
	{
		return nullptr;
	}


	if (indexN == 0)
	{
		return &t[0];
	}

	int testingvalue2 = t[indexN];
	const int* testingValue = f_maximum(N - 1, t);
	return f_porownaj(&testingvalue2, testingValue);

}

int f_newton(int N, int K)
{
	
	if (N < K || N < 0 || K < 0)
	{
		return 0;
	}
	if (K > 33 || N > 33)
	{
		return -1;
	}
	int liczbA = (silnia(N)) / (silnia(K) * silnia(N - K));

	return liczbA;
}



int f_sumaWarunkowa(bool (*f)(int), const int* b, const int* e, int& iloscSpelniajacaWarunek)
{
	double suma = 0;
	if (f(*b) && b < e)
	{
		suma = *b;
		iloscSpelniajacaWarunek++;
		return suma += f_sumaWarunkowa(f, b + 1, e, iloscSpelniajacaWarunek);
	}
	if (!f(*b) && b < e)
	{
		f_sumaWarunkowa(f, b + 1, e, iloscSpelniajacaWarunek);
	}
	return 0;
}

unsigned int f_sredniaWarunkowa(double& s, bool (*f)(int), const int* b, const int* e)
{
	int iloscSpelniajacychWarunek = 0;
	double suma = f_sumaWarunkowa(f, b, e, iloscSpelniajacychWarunek);
	if (iloscSpelniajacychWarunek == 0) return iloscSpelniajacychWarunek;
	s = suma / iloscSpelniajacychWarunek;
	return iloscSpelniajacychWarunek;
}



bool f_wystapienieUjemnychWZakresie(double* b, double* e)
{
	bool czyWystapilaUjemna = false;
	if (b < e and *b >= 0)
		czyWystapilaUjemna = f_wystapienieUjemnychWZakresie(b + 1, e); //Jezeli wystapi choc jedna liczba < 0, to true utrzyma sie w zmiennej do koñca
	if (b < e and *b < 0)
	{
		return true;
	}
	return czyWystapilaUjemna;
}

double f_sumaZakresu(double* b, double* e)
{
	double sum = 0;
	if (b < e)
	{
		sum = *b;
		return sum += f_sumaZakresu(b + 1, e);
	}
	else
	{
		return sum;
	}
}

double f_sumaIloczynowZakresu(double* b, double* e, double* a)
{
	double sum = 0;
	if (b < e)
	{
		sum = *b * *a;
		return sum += f_sumaIloczynowZakresu(b + 1, e, a + 1);
	}
	else
	{
		return sum;
	}
}

bool f_sumaWazona(double& s, double* b, double* e, double* a)
{

	if (!f_wystapienieUjemnychWZakresie(b, e) && f_sumaZakresu(b, e) <= 1)
	{
		//cout << "\n" << f_sumaZakresu(b, e) << "\n";
		//cout << "\n" << e- b << "\n";
		s = f_sumaIloczynowZakresu(b, e, a) + (a[e - b] * (1 - f_sumaZakresu(b, e)));
		return true;
	}
	else
	{
		return false;
	}

}



