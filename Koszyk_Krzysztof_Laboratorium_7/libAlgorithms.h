#pragma once
#include <vector>

using namespace std;

/*
* Funkcja znajduje indeks pod którym kryje siê PIERWSZA szukana wartoœæ w tablicy
* @param dataArray tablica elementow
* @param findingValue szukana wartosc
* @return zwraca indeks pod którym przechowywana jest szukana wartoœæ
*/
int f_BinarySearch(vector<int> dataRow, int findingValue);

/*
* Funkcja znajduje indeks pod którym kryje siê OSTATNIA szukana wartoœæ w tablicy
* @param dataArray tablica elementow
* @param findingValue szukana wartosc
* @return zwraca indeks pod którym przechowywana jest szukana wartoœæ
*/
int f_BinarySearchLast(vector<int> dataRow, int findingValue);
