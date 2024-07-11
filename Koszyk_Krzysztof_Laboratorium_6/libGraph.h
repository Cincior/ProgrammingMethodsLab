#pragma once
#include "libArray.h"
#include "libFile.h"
#include <vector>
#include <fstream>

using namespace std;

/*
* Funkcja znajduje najwi�kszy numer wierzcho�ka grafu
* @param fileName nazwa pliku zawieraj�cego dane o grafie
* @return nawi�kszy numer wierzcho�ka grafu
*/
int f_biggestNumberOfGraphPoint(string fileName);
/*
* Funkcja znajduje ilo�� po��cze� w grafie
* @param fileName nazwa pliku zawieraj�cego dane o grafie
* @return ilo�� po��cze� w grafie
*/
int f_amountOfConnectionsInGraph(string fileName);
/*
* Funkcja tworzy macierz incydencji grafu
* @param amountOfConnections ilo�� po��cze� mi�dzy wierzcho�kami grafu
* @param biggestNumber najwi�kszy wierzcho�ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return macierz indycencji
*/
int** f_createIncidentArray(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy wektor incydencji grafu
* @param amountOfConnections ilo�� po��cze� mi�dzy wierzcho�kami grafu
* @param biggestNumber najwi�kszy wierzcho�ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return wektor indycencji
*/
vector<vector<int>> f_createIncidentVector(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy macierz s�siad�w danego wierzcho�ka grafu
* @param incidentArray macierz incydencji danego grafu
* @param amountOfConnections ilo�� po��cze� mi�dzy wierzcho�kami grafu
* @param biggestNumber najwi�kszy wierzcho�ek grafu
* @return macierz indycencji
*/
int** f_createAdjacencyArray( int amountOfConnections, int biggestNumber, string fileName);