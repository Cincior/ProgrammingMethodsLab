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
	* Konstruktor inicjalizuj�cy sk�adowe klasy reprezentuj�cej stos
	* @param amountOfElements Rozmiar tablicy, kt�ra b�dzie przetrzymywa� elementy stosu
	*/
	StackArray(int amountOfElements);

	/*
	* Funkcja sprawdza, czy stos jest pusty
	* @return True je�li stos jest pusty
	*/
	bool isEmpty();

	/*
	* Funkcja zwracaj�ca aktualn� ilo�� element�w stosu
	* @return ilo�� element�w stosu
	*/
	int amountOfElements();

	/*
	* Funkcja zwraca element z g�ry stosu
	* @return ostatnio dodany element do stosu
	*/
	int getTop();

	/*
	* Funkcja dodaje element do stosu
	* @param v warto��, kt�ra ma by� dodana do stosu
	*/
	void push(int v);

	/*
	* Funkcja usuwa ostatni element ze stosu
	* @return usuni�ty element
	*/
	int pop();
};

