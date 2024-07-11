#pragma once
/*
* Funkcja znajduje indeks pod którym kryje siê szukana wartoœæ w tablicy
* @param T tablica elementow
* @param n iloœæ elementów w tablicy
* @param el szukany element
* @return zwraca indeks pod którym przechowywana jest szukana wartoœæ
*/
int f_BindarySearch(long long* T, int n, int el);
/*
* Funkcja zwraca iloœæ wyst¹pieñ podanego elementu w tablicy
* @param T tablica elementow
* @param n iloœæ elementów w tablicy
* @param el szukany element
* @return zwraca iloœæ wystst¹pieñ szukanego elementu
*/
int f_BindarySearchAll(long long* T, int n, int el);
/*
* Funkcja znajduje indeks elementu o danej wartosci szukanego w tablicy
* @param T tablica elementow
* @param n iloœæ elementów w tablicy
* @param el szukany element
* @return zwraca indeks pod którym znajduje siê szukany element
*/
int f_interpolationSearch(long long* T, int n, int el);
/*
* Funkcja usuwa duplikaty w tablicy
* @param T tablica elementow
* @param n iloœæ elementów w tablicy
* @return zwraca tablice bez duplikatow
*/
long long* f_removeDuplicates(long long* T, int n, int& sizeArrayMax);