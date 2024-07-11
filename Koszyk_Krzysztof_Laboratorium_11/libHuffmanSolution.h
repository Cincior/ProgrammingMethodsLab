#pragma once
#include <iostream>
#include <queue>
using namespace std;

// struktura w�z�a w drzewie
struct Node
{
	char letter = '0';
	double occurrences = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

// Niestandardowy komparator, by zapewnic poprawne sortowanie w kolejce priorytetowej
struct CompareNode 
{
	bool operator() (Node* lhs, Node* rhs) 
	{
		return lhs->occurrences > rhs->occurrences;
	}
};


//Przejade przez cale drzewo i jak bedzie lisc to odczytam literke i w argumencie funkcji rekurencyjnnej bede dopisywal 0 albo 1 w zalznosci czy pojde w prawo czy w lewo

/*
* Funkcja tworzy drzewo wed�ug algorytmu Huffmana tak, by w kolejce priorytetowej zosta� tylko jeden w�ze� b�d�cy korzeniem
* @param nodesQueue - kolejka priorytetowa w�z�ow, z kt�rych powsatnie drzewo binarne
*/
void f_createTree(priority_queue<Node*, vector<Node*>, CompareNode>& nodesQueue);

/*
* Funkcja wypisuje kody prefiksowe danych liter znajduj�cych si� w li�ciach drzewa
* @param node - korze� powsta�ego drzewa z algorytmu Huffmana
* @param code - aktualny stan kodu prefiksowego. Wypisywany kiedy dojdziemy do liscia (je�li idziemy w lewo to dopisujemy 0, je�li w prawo to dopisujemy 1)
*/
void f_printPrefixCode(Node* node, string code);

/*
* Funkcja wypisuje strukture drzewa
* @param node - aktualny w�ze�, kt�rego dane b�d� wypisane
* @param indent - wci�cie, kt�re zmienia si� w zale�no�ci od g��boko�ci i czy rozwa�amy prawy w�ze�, czy lewy
* @param last - m�wi, czy na danym poziomie to ostatni w�ze�
*/
void printTree(Node* node, string indent, bool last);