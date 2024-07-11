#include "libGraph2.h"

list<int>* f_incidentTabList(int amountOfConnections, int biggestNumber, string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	list<int>* incidentTab = new list<int>[biggestNumber];

	int startNumber, endNumber;
	fileRead >> startNumber; //pominiecie pierwszej danej z pliku

	//bez powielania
	/*for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		incidentTab[(startNumber - 1)].push_back(endNumber);
	}*/

	//z powielaniem
	for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		incidentTab[(startNumber - 1)].push_back(endNumber);
		incidentTab[(endNumber - 1)].push_back(startNumber);
	}
	return incidentTab;
}

listStruct* f_incidentMyList(int amountOfConnections, int biggestNumber, string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	listStruct* incidentTab = new listStruct[biggestNumber];

	int startNumber, endNumber;
	fileRead >> startNumber; //pominiecie pierwszej danej z pliku


	for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		incidentTab[(startNumber - 1)].addElementback(endNumber);
		incidentTab[(endNumber - 1)].addElementback(startNumber);
	}
	return incidentTab;
}
