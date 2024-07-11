#pragma once
#include <vector>
#include <iostream>
#include "libFile.h"

#include "libLinearCongruentialGenerator.h"

using namespace std;

/*
* Funkcja realizuje generowanie liczb losowych addytywn¹ metod¹ kongruencyjn¹
* @param n rozmiar tablicy
* @param m modu³
* @return Zwraca vector liczb pseudolosowych
*/
vector<int> f_AdditionalCongruentGenerator(int n, int m);

/*
* Funkcja znajduje najlepiej pasuj¹c¹ pare liczb
* @param n rozmiar tablicy
* @return Zwraca pare pasuj¹cych liczb
*/
vector<int> f_findBestPair(int n);