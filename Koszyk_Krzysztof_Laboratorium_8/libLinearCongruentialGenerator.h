#pragma once
#include <vector>
#include <iostream>
#include <set>
#include "libExceptions.h"
#include "libFile.h"
using namespace std;


/*
* Funkcja realizuje generowanie liczb losowych liniową metodą kongruencyjną
* @param n ilosc liczb pseudolosowych, które mają zostać wygenerowane
* @return Zwraca vector liczb pseudolosowych
*/
vector<int> f_linearCongruentialGenerator(int n);

/*
* Funkcja znajduje rozkład liczby na czynniki pierwsze bez powtórzeń
* @param number liczba do rozłożenia na czynniki pierwsze
* @return zbiór asocjacyjny czynników pierwszych
*/
set<int> f_PrimeFactors(int number);

/*
* Funkcja znajduje możliwe lambdy według wzoru z zadania
* @param m moduł ze wzoru
* @param mPrimeFactors czynniki pierwsze liczby m
* @return zbiór możliwych lambd, które spełniają wzór a^λ mod m == 1; 2 <= a < m
*/
vector<int> f_allPossibleLambdas(int m, set<int> mPrimeFactors);

/*
* Funkcja sprawdza, czy liczby mają wspólny dzielnik
* @param PrimeFactorsA rozkład na czynniki pierwszej liczby
* @param PrimeFactorsB rozkład na czynniki drugiej liczby
* @return true jeśli liczby maja wspólny dzielnik
*/
bool f_commonDivisior(set<int> PrimeFactorsA, set<int> PrimeFactorsB);

/*
* Funkcja sprawdza, czy liczba a jest wielokrotnością liczby b
* @param a pierwsza liczba
* @param b druga liczba
* @return true jeśli liczba jest wielokrotnością liczby b
*/
bool f_isMultiple(int a, int b);

/*
* Funkcja wpisuje wygenerowany liczby pseudolosowe do pliku
* @param fName nazwa pliku, w którym przechowane będą dane
* @param b druga liczba
* @return true jeśli liczba jest wielokrotnością liczby b
*/
void f_writeResultsIntoFile(string fName, vector<int> pseudoRandomNumbers);

/*
* Funkcja dobiera odpowiedni współczynnik C
* @param m moduł m
* @return odpowiedni współczynnik c
*/
int f_createC(int m);

/*
* Funkcja dobiera odpowiedni współczynnik A
* @param a współczynnik a
* @return odpowiedni współczynnik a
*/
int f_createA(int m);