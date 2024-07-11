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
* @return True je�li stos jest pusty
*/
bool f_isEmpty(Element* top);

/*
* Funkcja zwracaj�ca aktualn� ilo�� element�w stosu
* @return ilo�� element�w stosu
*/
int f_amountOfElements(Element* top);

/*
* Funkcja zwraca element z g�ry stosu
* @return ostatnio dodany element do stosu
*/
int f_getTop(Element* top);

/*
* Funkcja dodaje element do stosu
* @param v warto��, kt�ra ma by� dodana do stosu
*/
void f_push(Element*& top, int v);

/*
* Funkcja usuwa ostatni element ze stosu
* @return usuni�ty element
*/
int f_pop(Element*& top);