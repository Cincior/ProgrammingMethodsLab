#include <iostream>

int** utworzTablice(int rozmiarN, int rozmiarM);
int podajRozmiarN();
int podajRozmiarM();
int** wypelnijTablice(int** tab, int rozmiarN, int rozmiarM);
int sprawdzPodtablice2D(int** tab, int rozmiarN, int rozmiarM);
int sprawdzPodtablice(int* tab, int rozmiar);


int main()
{
	int z;
	std::cin >> z;
	int* odp = new int[z];
	for (int i = 0; i < z; i++)
	{
		int rozmiarTN = podajRozmiarN();
		int rozmiarTM = podajRozmiarM();
		if (rozmiarTN <= 0 || rozmiarTN > 100 || rozmiarTM <= 0 || rozmiarTM > 100)
		{
			std::cout << "Rozmiar poza zakresem!";
			exit(0);
		}
		int** tablica = utworzTablice(rozmiarTN, rozmiarTM);
		tablica = wypelnijTablice(tablica, rozmiarTN, rozmiarTM);
		odp[i] = sprawdzPodtablice2D(tablica, rozmiarTN, rozmiarTM);
	}
	for (int i = 0; i < z; i++)
	{
		std::cout << odp[i] << std::endl;
	}
}
/*
 Argumenty:
rozmiarN - ilosc wierszy w tablicy
rozmiarM - ilosc kolumn w tablicy
Funkcja tworzy wskaŸnik do tablicy dwuwymiarowej liczb ca³kowitych i tworzy tê tablice
Zwraca wskaŸnik do nowo utworzonej tablicy.
*/
int** utworzTablice(int rozmiarN, int rozmiarM)
{
	int** T = nullptr;

	try
	{
		T = new int* [rozmiarN];
		for (int i = 0; i < rozmiarN; i++)
		{
			T[i] = new int[rozmiarM];
		}
	}
	catch (std::bad_alloc er)
	{
		std::cerr << er.what();
		exit(0);
	}

	return T;
}

/*
Funkcja prosi u¿ytkownika o podanie iloœci kolumn w tablicy.
Zwraca podan¹ iloœæ
*/
int podajRozmiarN()
{
	int rTN;
	std::cin >> rTN;
	return rTN;
}
/*
Funkcja prosi u¿ytkownika o podanie iloœci wierszy w tablicy.
Zwraca podan¹ iloœæ
*/
int podajRozmiarM()
{
	int rTM;
	std::cin >> rTM;
	return rTM;
}
/*
 Argumenty:
tab - tablica elementów
rozmiarN - ilosc wierszy w tablicy
rozmiarM - ilosc kolumn w tablicy
Funkcja wype³nia tablice elementami podanymi przez u¿ytkownika
Zwraca wype³nion¹ tablicê.
*/
int** wypelnijTablice(int** tab, int rozmiarN, int rozmiarM)
{
	int el;
	for (int i = 0; i < rozmiarN; i++)
	{
		for (int j = 0; j < rozmiarM; j++)
		{
			std::cin >> el;
			if (abs(el) > 32768)
			{
				std::cout << "Liczba poza zakresem!\n";
				j--;
			}
			else
			{
				tab[i][j] = el;
			}
		}
	}
	return tab;
}

// Algorytm opracowany we wczeœniejszym zadaniu.
/*
Argumenty:
tab - tablica elementów
rozmiar - rozmiar tablicy przekazanej w argumencie nr 1
Funkcja znajdujê najwiêksz¹ mo¿liw¹ podtablice, w której suma elementów jest maksymalna i nieujemna
Zwraca Maksymaln¹ sumê
*/
int sprawdzPodtablice(int* tab, int rozmiar)
{
	int sumaPodtablicy = 0, sumaNajwyzsza = 0, indexStart = 0, indexStop = 0, poczatekPodtablicy = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		sumaPodtablicy += tab[i];

		if (sumaPodtablicy < 0) // Jeœli suma podtablicy mniejsza od 0 mo¿emy tê podtablicê wykluczyæ z rozwa¿añ.
		{
			sumaPodtablicy = 0;
			poczatekPodtablicy = i + 1;
		}

		if (sumaPodtablicy > sumaNajwyzsza)
		{
			sumaNajwyzsza = sumaPodtablicy; // aktualizacja najwiêkszej sumy
			indexStart = poczatekPodtablicy; // Ustawienie indexu pocz¹tkowego
			indexStop = i; // Ustawienie indexu koñcowego
		}
	}
	//std::cout << indexStart << " " << indexStop << " " << sumaNajwyzsza;
	return sumaNajwyzsza;
}

/*
Argumenty:
tab - tablica elementów
rozmiarN - iloœæ wierszy w tablicy
rozmiarM - iloœæ kolumn w tablicy
Funkcja znajdujê najwiêksz¹ mo¿liw¹ podtablice dwuwymiarow¹, w której suma elementów jest maksymalna i nieujemna
Zwraca maksymaln¹ sumê
*/
int sprawdzPodtablice2D(int** tab, int rozmiarN, int rozmiarM)
{
	int sumaPodtablicy = 0, sumaNajwyzsza = 0, indexTop = 0, indexBottom = 0, indexLeft = 0, indexRight = 0;
	int* tablicaPomocnicza = new int[rozmiarN];
	

	for (int i = 0; i < rozmiarM; i++)
	{
		// wype³enienie pomocniczej tablicy w celu poprawnego wykonania poŸniejszych dzia³añ
		for (int i = 0; i < rozmiarM; i++)
		{
			tablicaPomocnicza[i] = 0;
		}
		for (int j = i; j < rozmiarM; j++)
		{
			for (int k = 0; k < rozmiarN; k++)
			{
				tablicaPomocnicza[k] += tab[k][j]; 
				// przygotowanie tablicy tymczasowej do uzycia na niej algorytmu z funkcji sprawdzPodtablice
				// Dodajemy kolejno do siebie poszczególne kolumny tablicy
			}
			sumaPodtablicy = sprawdzPodtablice(tablicaPomocnicza, rozmiarM);
			// Obliczenie maksymalnej sumy z podtablicy pozwala ustalic jak mo¿e wygladac podtablica dwuwymiarowa, która ma najwiêksz¹ sumê.
			if (sumaPodtablicy > sumaNajwyzsza) { 
				sumaNajwyzsza = sumaPodtablicy;
			}
		}
	}
	return sumaNajwyzsza;
}