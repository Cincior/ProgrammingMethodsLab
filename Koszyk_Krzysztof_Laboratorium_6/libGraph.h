#pragma once
#include "libArray.h"
#include "libFile.h"
#include <vector>
#include <fstream>

using namespace std;

/*
* Funkcja znajduje najwiêkszy numer wierzcho³ka grafu
* @param fileName nazwa pliku zawieraj¹cego dane o grafie
* @return nawiêkszy numer wierzcho³ka grafu
*/
int f_biggestNumberOfGraphPoint(string fileName);
/*
* Funkcja znajduje iloœæ po³¹czeñ w grafie
* @param fileName nazwa pliku zawieraj¹cego dane o grafie
* @return iloœæ po³¹czeñ w grafie
*/
int f_amountOfConnectionsInGraph(string fileName);
/*
* Funkcja tworzy macierz incydencji grafu
* @param amountOfConnections iloœæ po³¹czeñ miêdzy wierzcho³kami grafu
* @param biggestNumber najwiêkszy wierzcho³ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return macierz indycencji
*/
int** f_createIncidentArray(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy wektor incydencji grafu
* @param amountOfConnections iloœæ po³¹czeñ miêdzy wierzcho³kami grafu
* @param biggestNumber najwiêkszy wierzcho³ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return wektor indycencji
*/
vector<vector<int>> f_createIncidentVector(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy macierz s¹siadów danego wierzcho³ka grafu
* @param incidentArray macierz incydencji danego grafu
* @param amountOfConnections iloœæ po³¹czeñ miêdzy wierzcho³kami grafu
* @param biggestNumber najwiêkszy wierzcho³ek grafu
* @return macierz indycencji
*/
int** f_createAdjacencyArray( int amountOfConnections, int biggestNumber, string fileName);