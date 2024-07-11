#pragma once
#include <vector>
#include "libAlgorithms.h"

using namespace std;

/*
* Funkcja wyszukuje iteracyjnie pierwsze wystapienie podanego elementu w tablicy dwuwymiarowej
* @param dataArray dane do przeszukania
* @param searchedValue szukana liczba
* @return tablica indeksów, pod którymi kryje sie szukana wartoœæ
*/
vector<int> f_iterPier(vector<vector<int>> dataArray, int searchedValue);
/*
* Funkcja wyszukuje iteracyjnie ostatnie wystapienie podanego elementu w tablicy dwuwymiarowej
* @param dataArray dane do przeszukania
* @param searchedValue szukana liczba
* @return tablica indeksów, pod którymi kryje sie szukana wartoœæ
*/
vector<int> f_iterOst(vector<vector<int>> dataArray, int searchedValue);
/*
* Funkcja wyszukuje rekurencyjnie pierwsze wystapienie podanego elementu w tablicy jednowymiarowej
* @param dataArray tablica do przeszukania
* @param start index poczatkowy podtablicy (dotyczy wyszukiwania binarnego)
* @param end index koñcowy podtablicy (dotyczy wyszukiwania binarnego)
* @param searchedValue szukana liczba
* @return indexw, pod którym kryje sie szukana wartoœæ
*/
int f_binarySearchRecursionFirst(vector<int> dataRow, int start, int end, int searchedValue);
/*
* Funkcja wyszukuje rekurencyjnie pierwsze wystapienie podanego elementu w tablicy dwuwymiarowej
* @param dataArray dane do przeszukania
* @param row przeszukiwany wiersz
* @param searchedValue szukana liczba
* @return tablica indeksów, pod którymi kryje sie szukana wartoœæ
*/
vector<int> f_rekPier(vector<vector<int>> dataArray, int row, int searchedValue);
/*
* Funkcja wyszukuje rekurencyjnie pierwsze wystapienie podanego elementu w tablicy jednowymiarowej
* @param dataArray tablica do przeszukania
* @param start index poczatkowy podtablicy (dotyczy wyszukiwania binarnego)
* @param end index koñcowy podtablicy (dotyczy wyszukiwania binarnego)
* @param searchedValue szukana liczba
* @return indexw, pod którym kryje sie szukana wartoœæ
*/
int f_binarySearchRecursionLast(vector<int> dataRow, int start, int end, int searchedValue);
/*
* Funkcja wyszukuje rekurencyjnie ostatnie wystapienie podanego elementu w tablicy dwuwymiarowej
* @param dataArray dane do przeszukania
* @param row przeszukiwany wiersz
* @param searchedValue szukana liczba
* @return tablica indeksów, pod którymi kryje sie szukana wartoœæ
*/
vector<int> f_rekOst(vector<vector<int>> dataArray, int row, int searchedValue);