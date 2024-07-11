#include <iostream>
#include <queue>
#include <locale>
#include "libFile.h"
#include "libCustomExceptions.h"
#include "libHuffmanSolution.h"

using namespace std;

int main()
{
	cout << "Wybierz, dla ktorych danych chcesz obliczyc kod prefiksowy:\n1 - tabela a\n2 - tabela b\nInna opcja - przyklad 2\n";
	int choose;
	string fileName = "input2"; // default

	cin >> choose;

	switch (choose)
	{
	case 1:
		fileName = "inputTask1";
		break;
	case 2:
		fileName = "inputTask2";
		break;
	default:
		break;
	}

	
	ifstream fileRead = f_openFileToRead(fileName);
	fileRead.imbue(locale("")); // Dla poprawnego odczytania liczb z przecinkiem
	try
	{
		if (!fileRead.is_open())
		{
			throw CustomExceptions::FileOpenException("Blad otwarcia pliku " + fileName);
		}
	}
	catch (const exception& error)
	{
		cerr << error.what();
		return -1;
	}
	

	priority_queue<Node*, vector<Node*>, CompareNode> Trees;
	try
	{
		char letter;
		double occurances;
		while (!fileRead.eof())
		{
			Node* node = new Node;
			fileRead >> letter;
			fileRead >> occurances;
			if (fileRead.fail())
			{
				throw CustomExceptions::VariableError();
			}
			else
			{
				node->letter = letter;
				node->occurrences = occurances;
				Trees.push(node);
			}
		}
	}
	catch (const exception& error)
	{
		cerr << error.what();
		return -1;
	}

	f_createTree(Trees);
	cout << "Wygenerowane drzewo:\n";
	printTree(Trees.top(), "", true);
	cout << "Wygenerowane kody:\n";
	f_printPrefixCode(Trees.top(), "");
	return 0;
}
