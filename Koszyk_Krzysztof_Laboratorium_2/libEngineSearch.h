#pragma once
#include <string>

using namespace std;
/*
* Funkcja znajduje najlepsze dopasowanie silnika na podstawie danych z pliku
* @param fileName nazwa pliku, w kt�rym umieszonce s� dane
* @param fileName nazwa pliku, w kt�rym umieszonce s� dane
* @param fileNameResults nazwa pliku, w kt�rym umieszone zostan� wyniki dzia�ania
* @return Zwraca true jesli szukanie powiedzie sie
*/
bool f_findBestEngineMatch(string fileName, string fileNamePattern, string fileNameResults);