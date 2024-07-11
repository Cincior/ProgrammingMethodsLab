#include <iostream>

int* utworzTablice(int rozmiarTablicy);
int podajRozmiar();
int* wypelnijTablice(int* tab, int rozmiar);
void sprawdzPodtablice(int* tab, int rozmiar);
int suma(int x);

int main()
{
	int z;
	std::cin >> z;
	for (int i = 0; i < z; i++)
	{
		int rozmiarT = podajRozmiar();
		if (rozmiarT <= 0 || rozmiarT > 1000000)
		{
			std::cout << "Rozmiar poza zakresem!";
			exit(0);
		}
		int* tablica = utworzTablice(rozmiarT);
		tablica = wypelnijTablice(tablica, rozmiarT);
		sprawdzPodtablice(tablica, rozmiarT);
		std::cout << std::endl;
		// Wyswietlanie odpowiedz po wype�nieniu pierwszej tablicy
	}
}
/*
 Argumenty:
rozmiarTablicy - zawiera podany przez u�ytkownika rozmiar tablicy, kt�ra ma zosta� utworzona.
Funkcja tworzy wska�nik do tablicy liczb ca�kowitych i tworzy tablice
Zwraca wska�nik do nowo utworzonej tablicy.
*/
int* utworzTablice(int rozmiarTablicy)
{
	int* T = nullptr;

	try
	{
		T = new int[rozmiarTablicy];
	}
	catch (std::bad_alloc er)
	{
		std::cerr << er.what();
		exit(0);
	}

	return T;
}
/*
Funkcja prosi u�ytkownika o podanie rozmiaru tablicy.
Zwraca rozmiar tablicy
*/
int podajRozmiar()
{
	int rT;
	std::cin >> rT;
	return rT;
}

/*
 Argumenty:
tab - tablica element�w
rozmiar - rozmiar tablicy przekazanej w argumencie nr 1
Funkcja wype�nia tablice elementami podanymi przez u�ytkownika
Zwraca wype�nion� tablic�.
*/
int* wypelnijTablice(int* tab, int rozmiar)
{
	int el;
	for (int i = 0; i < rozmiar; i++)
	{
		std::cin >> el;
		if (abs(el) > 2000)
		{
			std::cout << "Liczba poza zakresem!\n";
			i--;
		}
		else
		{
			tab[i] = el;
		}
	}
	return tab;
}

/*
Argumenty:
x - pojedyczny element podtablicy
Funkcja oblicza i zwraca warto�� dla danego elementu podtablicy zgodnie z podanym wzorem na sume;
*/
int suma(int x)
{
	int el = x;
	if (el < 0)
	{
		el = el * 2;
	}
	else
	{
		el = el * 3;
	}
	return el;
}

// Implementacja O(n)
/*
 Argumenty:
tab - tablica element�w
rozmiar - rozmiar tablicy przekazanej w argumencie nr 1
Funkcja znajduj� najwi�ksz� mo�liw� podtablice, w kt�rej suma element�w obliczana wed�ug podanego wzoru jest nieujemna
Wz�r - suma = 3 * D + 2 * U
D = suma dodatnich element�w podtablicy
U = suma ujemnych element�w podtablicy
Wypisuje index pocz�tkowy i ko�cowy podtablicy oraz obliczon� sum� element�w podtablicy wed�ug podanego wzoru.
*/
void sprawdzPodtablice(int* tab, int rozmiar)
{
	int sumaPodtablicy = 0, sumaNajwyzsza = 0, indexStart = 0, indexStop = 0, poczatekPodtablicy = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		sumaPodtablicy += suma(tab[i]);

		if (sumaPodtablicy < 0) // Je�li suma podtablicy mniejsza od 0 mo�emy t� podtablic� wykluczy� z rozwa�a�.
		{
			sumaPodtablicy = 0;
			poczatekPodtablicy = i + 1;
		}

		if (sumaPodtablicy > sumaNajwyzsza)
		{
			sumaNajwyzsza = sumaPodtablicy; // aktualizacja najwi�kszej sumy
			indexStart = poczatekPodtablicy; // Ustawienie indexu pocz�tkowego
			indexStop = i; // Ustawienie indexu ko�cowego
		}
	}
	std::cout << indexStart << " " << indexStop << " " << sumaNajwyzsza;
}

// Implementacja O(n^2)
/*
void sprawdzPodtablice(int* tab, int rozmiar)
{
	int suma1 = 0, sumaNajwyzsza = 0, indexStart = 0, indexStop = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = i; j < rozmiar; j++)
		{
			suma1 += suma(tab[j]);
			if (sumaNajwyzsza < suma1)
			{
				sumaNajwyzsza = suma1;
				indexStart = i;
				indexStop = j;
			}
		}
		suma1 = 0;
		
	}
	std::cout << indexStart << " " << indexStop << " " << sumaNajwyzsza;
}
*/
