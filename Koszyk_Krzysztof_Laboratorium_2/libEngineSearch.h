#pragma once
#include <string>

using namespace std;
/*
* Funkcja znajduje najlepsze dopasowanie silnika na podstawie danych z pliku
* @param fileName nazwa pliku, w którym umieszonce s¹ dane
* @param fileName nazwa pliku, w którym umieszonce s¹ dane
* @param fileNameResults nazwa pliku, w którym umieszone zostan¹ wyniki dzia³ania
* @return Zwraca true jesli szukanie powiedzie sie
*/
bool f_findBestEngineMatch(string fileName, string fileNamePattern, string fileNameResults);