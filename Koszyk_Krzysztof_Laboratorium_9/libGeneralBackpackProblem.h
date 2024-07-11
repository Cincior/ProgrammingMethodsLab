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
* Funkcja znajduje najoptymalniejsze zapakowanie plecaka metod¹ programowania dynamicznego
*/
void f_generalBackpackProblem();

/*
* Funkcja sprawdza, czy liczba jest dodatnia - zawiera siê w przedziale od 1 do nieskoñczonoœci
* @param number liczba do sprawdzenia
* @return true, jeœli liczba jest dodatnia
*/
bool f_isNumberPositive(int number);

/*
* Funkcja tworzy tablice P, która zawiera wartoœci najlepszych upakowañ plecaka
* @param availableItems przedmioty mo¿liwe do spakowania
* @param maxBackpackWeight maksymalna pojemnoœæ plecaka
* @return tablice 2-wymiarowa P
*/
vector<vector<int>> f_createArrayP(vector<Item> availableItems, int maxBackpackWeight);

/*
* Funkcja tworzy tablice Q, która zawiera ostatni zapakowany element
* @param availableItems przedmioty mo¿liwe do spakowania
* @param maxBackpackWeight maksymalna pojemnoœæ plecaka
* @param P tablica najlepszych upakowañ plecaka
* @return tablice 2-wymiarowa Q
*/
vector<vector<int>> f_createArrayQ(vector<Item> availableItems, int maxBackpackWeight, vector<vector<int>> P);