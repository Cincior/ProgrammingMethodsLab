#pragma once
#include <iostream>

using namespace std;

/*
Szablon elementu stosu
*/
struct Element
{
	int value;
	Element* next;
};

/*
* Funkcja sprawdza, czy stos jest pusty
* @return True jeœli stos jest pusty
*/
bool f_isEmpty(Element* top);

/*
* Funkcja zwracaj¹ca aktualn¹ iloœæ elementów stosu
* @return iloœæ elementów stosu
*/
int f_amountOfElements(Element* top);

/*
* Funkcja zwraca element z góry stosu
* @return ostatnio dodany element do stosu
*/
int f_getTop(Element* top);

/*
* Funkcja dodaje element do stosu
* @param v wartoœæ, która ma byæ dodana do stosu
*/
void f_push(Element*& top, int v);

/*
* Funkcja usuwa ostatni element ze stosu
* @return usuniêty element
*/
int f_pop(Element*& top);