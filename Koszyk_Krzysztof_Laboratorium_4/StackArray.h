#pragma once
#include "libArray.h"
#include <iostream>

using namespace std;

class StackArray
{
	int* elements;
	int currentIndex;
	int size;

public:
	/*
	* Konstruktor inicjalizuj¹cy sk³adowe klasy reprezentuj¹cej stos
	* @param amountOfElements Rozmiar tablicy, która bêdzie przetrzymywaæ elementy stosu
	*/
	StackArray(int amountOfElements);

	/*
	* Funkcja sprawdza, czy stos jest pusty
	* @return True jeœli stos jest pusty
	*/
	bool isEmpty();

	/*
	* Funkcja zwracaj¹ca aktualn¹ iloœæ elementów stosu
	* @return iloœæ elementów stosu
	*/
	int amountOfElements();

	/*
	* Funkcja zwraca element z góry stosu
	* @return ostatnio dodany element do stosu
	*/
	int getTop();

	/*
	* Funkcja dodaje element do stosu
	* @param v wartoœæ, która ma byæ dodana do stosu
	*/
	void push(int v);

	/*
	* Funkcja usuwa ostatni element ze stosu
	* @return usuniêty element
	*/
	int pop();
};

