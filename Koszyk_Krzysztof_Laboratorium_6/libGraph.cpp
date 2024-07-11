#include "libGraph.h"

int f_amountOfConnectionsInGraph(string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	int amountOfConnections;
	fileRead >> amountOfConnections;
	fileRead.close();

	return amountOfConnections;
}

int f_biggestNumberOfGraphPoint(string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	int amountOfConnections;
	fileRead >> amountOfConnections;

	int startNumber, endNumber, maxNumber = 0;

	for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		if (maxNumber < startNumber)
		{
			maxNumber = startNumber;
		}
		else if (maxNumber < endNumber)
		{
			maxNumber = endNumber;
		}
	}
	fileRead.close();
	return maxNumber;
}

int** f_createIncidentArray(int amountOfConnections, int biggestNumber, string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	int** incidentMatrix = f_createArrayInt2D(amountOfConnections, biggestNumber);

	int startNumber, endNumber;
	fileRead >> startNumber; //pominiecie pierwszej danej z pliku
	for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		for (int j = 0; j < biggestNumber; j++)
		{
			if (startNumber == j + 1)
			{
				incidentMatrix[i][j] = 1;
			}
			else if (endNumber == j + 1)
			{
				incidentMatrix[i][j] = -1;
			}
			else
			{
				incidentMatrix[i][j] = 0;
			}
		}
	}
	return incidentMatrix;
}

vector<vector<int>> f_createIncidentVector(int amountOfConnections, int biggestNumber, string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);
	vector<vector<int>> incidentVector(amountOfConnections);

	int startNumber, endNumber;
	fileRead >> startNumber; //pominiecie pierwszej danej z pliku
	for (int i = 0; i < amountOfConnections; i++)
	{
		incidentVector[i] = vector<int>(biggestNumber);
		fileRead >> startNumber;
		fileRead >> endNumber; 
		for (int j = 0; j < biggestNumber; j++)
		{
			if (startNumber == j + 1)
			{
				incidentVector[i][j] = 1;
			}
			else if (endNumber == j + 1)
			{
				incidentVector[i][j] = -1;
			}
			else
			{
				incidentVector[i][j] = 0;
			}
		}
	}
	return incidentVector;
}

int** f_createAdjacencyArray(int amountOfConnections, int biggestNumber, string fileName)
{
	ifstream fileRead = f_openFileToRead(fileName);

	int startNumber, endNumber;
	fileRead >> startNumber; //pominiecie pierwszej danej z pliku

	int** adjacency = f_createArrayInt2D(biggestNumber, biggestNumber);

	for (int i = 0; i < biggestNumber; i++)
	{
		for (int j = 0; j < biggestNumber; j++)
		{
			adjacency[i][j] = 0; //wypelnienie zerami
		}
	}

	for (int i = 0; i < amountOfConnections; i++)
	{
		fileRead >> startNumber;
		fileRead >> endNumber;
		adjacency[startNumber - 1][endNumber - 1] = 1;
	}

	return adjacency;
}
