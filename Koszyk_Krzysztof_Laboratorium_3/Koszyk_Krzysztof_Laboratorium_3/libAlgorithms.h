#pragma once
/*
* Funkcja znajduje indeks pod kt�rym kryje si� szukana warto�� w tablicy
* @param T tablica elementow
* @param n ilo�� element�w w tablicy
* @param el szukany element
* @return zwraca indeks pod kt�rym przechowywana jest szukana warto��
*/
int f_BindarySearch(long long* T, int n, int el);
/*
* Funkcja zwraca ilo�� wyst�pie� podanego elementu w tablicy
* @param T tablica elementow
* @param n ilo�� element�w w tablicy
* @param el szukany element
* @return zwraca ilo�� wystst�pie� szukanego elementu
*/
int f_BindarySearchAll(long long* T, int n, int el);
/*
* Funkcja znajduje indeks elementu o danej wartosci szukanego w tablicy
* @param T tablica elementow
* @param n ilo�� element�w w tablicy
* @param el szukany element
* @return zwraca indeks pod kt�rym znajduje si� szukany element
*/
int f_interpolationSearch(long long* T, int n, int el);
/*
* Funkcja usuwa duplikaty w tablicy
* @param T tablica elementow
* @param n ilo�� element�w w tablicy
* @return zwraca tablice bez duplikatow
*/
long long* f_removeDuplicates(long long* T, int n, int& sizeArrayMax);