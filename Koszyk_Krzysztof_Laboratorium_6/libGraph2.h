#pragma once
#include <list>
#include "libGraph.h"
#include "libList.h"

using namespace std;

/*
* Funkcja tworzy tablice z list� incydencji grafu
* @param amountOfConnections ilo�� po��cze� mi�dzy wierzcho�kami grafu
* @param biggestNumber najwi�kszy wierzcho�ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return tablica zawieraj�ca listy incydencji
*/
list<int>* f_incidentTabList(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy tablice z list� incydencji grafu
* @param amountOfConnections ilo�� po��cze� mi�dzy wierzcho�kami grafu
* @param biggestNumber najwi�kszy wierzcho�ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return tablica zawieraj�ca listy incydencji
*/
listStruct* f_incidentMyList(int amountOfConnections, int biggestNumber, string fileName);