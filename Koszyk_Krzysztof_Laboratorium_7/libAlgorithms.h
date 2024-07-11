#pragma once
#include <vector>

using namespace std;

/*
* Funkcja znajduje indeks pod kt�rym kryje si� PIERWSZA szukana warto�� w tablicy
* @param dataArray tablica elementow
* @param findingValue szukana wartosc
* @return zwraca indeks pod kt�rym przechowywana jest szukana warto��
*/
int f_BinarySearch(vector<int> dataRow, int findingValue);

/*
* Funkcja znajduje indeks pod kt�rym kryje si� OSTATNIA szukana warto�� w tablicy
* @param dataArray tablica elementow
* @param findingValue szukana wartosc
* @return zwraca indeks pod kt�rym przechowywana jest szukana warto��
*/
int f_BinarySearchLast(vector<int> dataRow, int findingValue);
