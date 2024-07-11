#include <iostream>
#include "libArray.h"
#include "libFile.h"
#include "libSolutions.h"

using namespace std;

int main()
{
	ifstream fileRead = f_openFileToRead("wejscie.txt");
	ofstream fileWrite = f_openFileToWrite("wyjscie.txt");
	string amountOfLinesString;
	getline(fileRead, amountOfLinesString);
	int amountOfLines = stoi(amountOfLinesString);

	string line, name, expression;
	for (int i = 0; i < amountOfLines; i++)
	{
		getline(fileRead, line);

		for (int i = 0; i < 3; i++)
		{
			name += line[i];
		}

		if (name == "INF")
		{
			for (int i = 5; i < line.length(); i++)
			{
				expression += line[i];
			}
			fileWrite << "ONP: " << f_INF_To_ONP(expression) << "\n";
		}
		else if (name == "ONP")
		{
			vector<string> expressionONP;
			for (int i = 5; i < line.length(); i++) 
			{
				char character = line[i];
				expressionONP.push_back(string(1, character)); // Tworzymy wektor stringów, ka¿dy zawiera jedn¹ literê
			}
			fileWrite << "INF: " << f_ONP_To_INF(expressionONP) << "\n";
		}
		else
		{
			cout << "error in reading name";
			return -1;
		}


		name = "";
		expression = "";
	}
	fileRead.close();
	fileWrite.close();
}