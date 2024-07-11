#pragma once
#include "libFile.h"
using namespace std;
/*
* Funkcja zapisuje do pliku wszystkie podzbiory zbioru n-elementowego
* @param n ilo�� elemtn�w zbioru
* @param B tablica zawieraj�ca g��wny zbi�r 
* @return True je�li uda�o si� wypisa� wszystkie podzbiory
*/
bool f_getAllSubsets(int n);
/*
* Funkcja zapisuje do pliku wszystkie k-elementowe podzbiory zbioru n-elementowego w porz�dku leksykograficznym
* @param n ilo�� elemtn�w zbioru
* @param B tablica zawieraj�ca g��wny zbi�r
* @return True je�li uda�o si� wypisa� wszystkie podzbiory
*/
bool f_getKSubsets(int n, int k);
/*
* Funkcja zapisuje do pliku ciag podzia��w liczby n w porz�dku odwrotnym do leksykograficznego
* @param n liczba do podzialu
* @return True je�li uda�o si� poprawnie podzieli�
*/
bool f_getPartsN(int n);