#pragma once
#include "libFile.h"
using namespace std;
/*
* Funkcja zapisuje do pliku wszystkie podzbiory zbioru n-elementowego
* @param n iloœæ elemtnów zbioru
* @param B tablica zawieraj¹ca g³ówny zbiór 
* @return True jeœli uda³o siê wypisaæ wszystkie podzbiory
*/
bool f_getAllSubsets(int n);
/*
* Funkcja zapisuje do pliku wszystkie k-elementowe podzbiory zbioru n-elementowego w porz¹dku leksykograficznym
* @param n iloœæ elemtnów zbioru
* @param B tablica zawieraj¹ca g³ówny zbiór
* @return True jeœli uda³o siê wypisaæ wszystkie podzbiory
*/
bool f_getKSubsets(int n, int k);
/*
* Funkcja zapisuje do pliku ciag podzia³ów liczby n w porz¹dku odwrotnym do leksykograficznego
* @param n liczba do podzialu
* @return True jeœli uda³o siê poprawnie podzieliæ
*/
bool f_getPartsN(int n);