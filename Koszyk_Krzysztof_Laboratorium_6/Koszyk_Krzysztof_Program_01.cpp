#include <iostream>
#include "libArray.h"
#include "libFile.h"
#include "libGraph.h"

using namespace std;

int main()
{
    string fileName = "wejscie";
    int amountOfConnections = f_amountOfConnectionsInGraph(fileName);
    int biggestNumber = f_biggestNumberOfGraphPoint(fileName);

	cout << "Tablica:\n";
    int** incidentMatrix = nullptr;
    incidentMatrix = f_createIncidentArray(amountOfConnections, biggestNumber, fileName);
    
	for (int i = 0; i < amountOfConnections; i++)
	{
		for (int j = 0; j < biggestNumber; j++)
		{
			cout << incidentMatrix[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\nVector:\n";
	vector<vector<int>> incidentVector = f_createIncidentVector(amountOfConnections, biggestNumber, fileName);

	for (int i = 0; i < amountOfConnections; i++)
	{
		for (int j = 0; j < incidentVector[i].size(); j++)
		{
			cout << incidentVector[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\nSasiedzi:\n";
	int** adjacency = nullptr;
	adjacency = f_createAdjacencyArray(amountOfConnections, biggestNumber, fileName);

	
	for (int i = 0; i < biggestNumber; i++)
	{
		for (int j = 0; j < biggestNumber; j++)
		{
			if (adjacency[i][j] == 1)
			{
				cout << (i + 1) << " ma sasiada: " << (j + 1) << "\n";
			}
		}
	}
}