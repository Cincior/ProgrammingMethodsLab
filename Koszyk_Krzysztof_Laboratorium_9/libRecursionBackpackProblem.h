#pragma once
#include <vector>
#include "libFile.h"
#include "libExceptions.h"

/*
* Funkcja znajduje sekwencjê elementów, których sumaryczna waga jest równma pojemnoœci plecaka
* @param results - wektor wyników
* @param remaining - wagi brane pod uwage
* @param elementsWeight - poszczegolne wagi przedmiotów
* @param n - ilosc mo¿liwych wag elementów do wyboru
* @param capacityLeft - ilosc pozosta³ego miejsca do zape³nienia
*/
void f_findSequence(std::vector<int>& result, std::vector<int>remaining, std::vector<int> elementsWeight, int n, int capacityLeft);

/*
* Funkcja znajduje sekwencjê elementów, których sumaryczna waga jest równma pojemnoœci plecaka. Zaczytuje dane i wywo³uje funkcjê rekurencyjn¹
*/
void f_recursionBackpackProblem();

/*
* Funkcja sprawdza, czy liczba zawiera siê w przedziale od 1 do 1 000 000
* @param number liczba do sprawdzenia
* @return true, jeœli liczba spe³nia warunek
*/
bool f_isNumberVaild(int number);