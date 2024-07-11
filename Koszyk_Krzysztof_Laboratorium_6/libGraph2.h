#pragma once
#include <list>
#include "libGraph.h"
#include "libList.h"

using namespace std;

/*
* Funkcja tworzy tablice z list¹ incydencji grafu
* @param amountOfConnections iloœæ po³¹czeñ miêdzy wierzcho³kami grafu
* @param biggestNumber najwiêkszy wierzcho³ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return tablica zawieraj¹ca listy incydencji
*/
list<int>* f_incidentTabList(int amountOfConnections, int biggestNumber, string fileName);
/*
* Funkcja tworzy tablice z list¹ incydencji grafu
* @param amountOfConnections iloœæ po³¹czeñ miêdzy wierzcho³kami grafu
* @param biggestNumber najwiêkszy wierzcho³ek grafu
* @param fileName nazwa pliku z danymi o grafie
* @return tablica zawieraj¹ca listy incydencji
*/
listStruct* f_incidentMyList(int amountOfConnections, int biggestNumber, string fileName);