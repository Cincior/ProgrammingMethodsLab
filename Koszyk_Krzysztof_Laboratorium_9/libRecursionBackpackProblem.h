#pragma once
#include <vector>
#include "libFile.h"
#include "libExceptions.h"

/*
* Funkcja znajduje sekwencj� element�w, kt�rych sumaryczna waga jest r�wnma pojemno�ci plecaka
* @param results - wektor wynik�w
* @param remaining - wagi brane pod uwage
* @param elementsWeight - poszczegolne wagi przedmiot�w
* @param n - ilosc mo�liwych wag element�w do wyboru
* @param capacityLeft - ilosc pozosta�ego miejsca do zape�nienia
*/
void f_findSequence(std::vector<int>& result, std::vector<int>remaining, std::vector<int> elementsWeight, int n, int capacityLeft);

/*
* Funkcja znajduje sekwencj� element�w, kt�rych sumaryczna waga jest r�wnma pojemno�ci plecaka. Zaczytuje dane i wywo�uje funkcj� rekurencyjn�
*/
void f_recursionBackpackProblem();

/*
* Funkcja sprawdza, czy liczba zawiera si� w przedziale od 1 do 1 000 000
* @param number liczba do sprawdzenia
* @return true, je�li liczba spe�nia warunek
*/
bool f_isNumberVaild(int number);