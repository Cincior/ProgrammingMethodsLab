#pragma once
#include "fstream"

/*
* Funkcja otwiera plik tylko do odczytu
* @param fileName nazwa pliku
* @return Zwraca uchwyt do otwartego pliku
*/
std::ifstream f_openFileToRead(std::string fileName);
/*
* Funkcja otwiera plik tylko do zapisu
* @param fileName nazwa pliku
* @return Zwraca uchwyt do otwartego pliku
*/
std::ofstream f_openFileToWrite(std::string fileName);

