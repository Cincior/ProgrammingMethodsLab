#pragma once
#include <vector>
#include <iostream>
#include "libFile.h"

#include "libLinearCongruentialGenerator.h"

using namespace std;

/*
* Funkcja realizuje generowanie liczb losowych addytywn� metod� kongruencyjn�
* @param n rozmiar tablicy
* @param m modu�
* @return Zwraca vector liczb pseudolosowych
*/
vector<int> f_AdditionalCongruentGenerator(int n, int m);

/*
* Funkcja znajduje najlepiej pasuj�c� pare liczb
* @param n rozmiar tablicy
* @return Zwraca pare pasuj�cych liczb
*/
vector<int> f_findBestPair(int n);