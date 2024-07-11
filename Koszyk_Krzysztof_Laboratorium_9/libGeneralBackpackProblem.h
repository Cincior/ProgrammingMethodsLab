#pragma once
#include <vector>
#include "libFile.h"
#include "libExceptions.h"

using namespace std;

struct Item 
{
	string name;
	int weight;
	int price;

	Item()
	{
		name = "";
		weight = 0;
		price = 0;
	}
};

/*
* Funkcja znajduje najoptymalniejsze zapakowanie plecaka metod� programowania dynamicznego
*/
void f_generalBackpackProblem();

/*
* Funkcja sprawdza, czy liczba jest dodatnia - zawiera si� w przedziale od 1 do niesko�czono�ci
* @param number liczba do sprawdzenia
* @return true, je�li liczba jest dodatnia
*/
bool f_isNumberPositive(int number);

/*
* Funkcja tworzy tablice P, kt�ra zawiera warto�ci najlepszych upakowa� plecaka
* @param availableItems przedmioty mo�liwe do spakowania
* @param maxBackpackWeight maksymalna pojemno�� plecaka
* @return tablice 2-wymiarowa P
*/
vector<vector<int>> f_createArrayP(vector<Item> availableItems, int maxBackpackWeight);

/*
* Funkcja tworzy tablice Q, kt�ra zawiera ostatni zapakowany element
* @param availableItems przedmioty mo�liwe do spakowania
* @param maxBackpackWeight maksymalna pojemno�� plecaka
* @param P tablica najlepszych upakowa� plecaka
* @return tablice 2-wymiarowa Q
*/
vector<vector<int>> f_createArrayQ(vector<Item> availableItems, int maxBackpackWeight, vector<vector<int>> P);