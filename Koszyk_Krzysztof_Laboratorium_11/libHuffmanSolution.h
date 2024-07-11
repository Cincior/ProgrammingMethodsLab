#pragma once
#include <iostream>
#include <queue>
using namespace std;

// struktura wêz³a w drzewie
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
* Funkcja tworzy drzewo wed³ug algorytmu Huffmana tak, by w kolejce priorytetowej zosta³ tylko jeden wêze³ bêd¹cy korzeniem
* @param nodesQueue - kolejka priorytetowa wêz³ow, z których powsatnie drzewo binarne
*/
void f_createTree(priority_queue<Node*, vector<Node*>, CompareNode>& nodesQueue);

/*
* Funkcja wypisuje kody prefiksowe danych liter znajduj¹cych siê w liœciach drzewa
* @param node - korzeñ powsta³ego drzewa z algorytmu Huffmana
* @param code - aktualny stan kodu prefiksowego. Wypisywany kiedy dojdziemy do liscia (jeœli idziemy w lewo to dopisujemy 0, jeœli w prawo to dopisujemy 1)
*/
void f_printPrefixCode(Node* node, string code);

/*
* Funkcja wypisuje strukture drzewa
* @param node - aktualny wêze³, którego dane bêd¹ wypisane
* @param indent - wciêcie, które zmienia siê w zale¿noœci od g³êbokoœci i czy rozwa¿amy prawy wêze³, czy lewy
* @param last - mówi, czy na danym poziomie to ostatni wêze³
*/
void printTree(Node* node, string indent, bool last);