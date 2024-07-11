#pragma once
#include <vector>
#include <iostream>
#include "libFile.h"

using namespace std;

// Opis przedmiotu, kt�ry mo�e zosta� zapakowany do plecaka
struct Item
{
    double P;
    double W;
    double ratioPW;

    Item()
    {
        ratioPW = 0;
        P = 0;
        W = 0;
    }
};

// Opis w�z�a, kt�ry symbolizuje aktualnie badane upakowanie
struct Node
{
    double profit;
    double weight;
    double maxProfit;
    double bound;
    Node* left;
    Node* right;
    Node* up;
    bool promising;
    int position;
    int depth;

    Node(double p = 0, double w = 0, double maxP = 0, double b = 0, Node* l = nullptr, Node* r = nullptr, bool promising = true, int position = 0, int depth = 0, Node* up = nullptr);

};


/*
* Funkcja oblicza bound potrzebny do okre�lenia, czy dany w�ze� jest obiecuj�cy
* @param items - mo�liwe do upakowania przedmioty
* @param W - maksymalna no�no�� plecaka
* @param node - wska�nik na w�ze�, kt�rego dane aktualnie wykorzystujemy do obliczania bound
* @param lvl poziom drzewa na kt�rym aktualnie si� znajdujemy
* @return obliczony bound
*/
double f_getBound(vector<Item> items, double W, Node* node, int lvl);

/*
* Funkcja oblicza index K potrzebny do wzoru
* @param remainingItems - mo�liwe do upakowania przedmioty bez przedmiotu, kt�ry nie jest brany pod uwag� przy pakowaniu (jego wartosc to 0)
* @param W - maksymalna no�no�� plecaka
* @return obliczone K
*/
int f_getK(vector<Item> remainingItems, double W);

/*
* Funkcja oblicza totalWeight potrzebne do wzoru na bound
* @param j - aktualnie rozpatrywany poziom drzewa + 1
* @param k - obliczone k za pomoc� funkcji getK
* @param items - mo�liwe do upakowania przedmioty
* @param node - wska�nik na w�ze�, kt�rego dane aktualnie wykorzystujemy do obliczania 
* @param W - maksymalna no�no�� plecaka
* @return obliczony totalWeight
*/
double f_getTotW(int j, int k, vector<Item> items, Node* node, double W);

/*
* Funkcja tworzy kopi� tablicy przedmiot�w w celu poprawnego obliczania danych w prawych gal�ziach drzewa, gdzie pewne przedmioty nie s� brane pod uwag�
* @param items - mo�liwe do upakowania przedmioty
* @param lvl poziom drzewa na kt�rym aktualnie si� znajdujemy
* @return przedmioty, gdzie warto�� przedmotu nie branego pod uwag� wynosi 0
*/
vector<Item> f_createItemsCopy(vector<Item> items, int lvl);

/*
* Funkcja tworzy drzewo stan�w pozwalaj�ce sprawdzi� jakie upakowanie b�dzie najkorzystniejsze
* @param depth g��boko�� drzewa
* @param lvl poziom drzewa na kt�rym aktualnie si� znajdujemy
* @param previousNode w�ze� nadrz�dny (znajduj�cy sie wy�ej)
* @param items - mo�liwe do upakowania przedmioty
* @param W - maksymalna no�no�� plecaka
* @param answer - wska�nik na w�ze�, kt�ry wskazywa� b�dzie najlepsze upakowanie
*/
void f_createTree(int depth, int lvl, Node* previousNode, vector<Item> items, double W, Node*& answer);

/*
* Funkcja wypisuje strukture drzewa
* @param previousNode w�ze� nadrz�dny (znajduj�cy sie wy�ej)
* @param n - ilo�� poziom�w drzewa
*/
void f_printTree(Node* previousNode, int n);

/*
* @param items - mo�liwe do upakowania przedmioty
* @param W - maksymalna no�no�� plecaka
*/
Node* f_initializeRoot(vector<Item> items, double W);

/*
* Funkcja tworzy lewy w�ze� danego poddrzewa
* @param lvl poziom drzewa na kt�rym aktualnie si� znajdujemy
* @param previousNode w�ze� nadrz�dny (znajduj�cy sie wy�ej)
* @param items - mo�liwe do upakowania przedmioty
* @param W - maksymalna no�no�� plecaka
* @param maxProfitOverall - wska�nik na zmienna statyczn�, kt�ra przechowuje najlepszy dotychczas osi�gni�ty profit
* @param positions - wska�nik do tablicy, kt�ra przechowuje ilo�� wyst�pie� w�z�ow na danym poziomie (index to poziom a warto�� pod tym indeksem to ilo�� ju� stworzonych na tym poziomie w�z�ow)
* @param answer wska�nik na w�ze�, kt�ry przechowuje adres w�z�a reprezentuj�cego najlepsze upakowanie
*/
Node* f_createLeftNode(int lvl, Node* previousNode, vector<Item> items, double W, double* maxProfitOverall, vector<int>* positions, Node*& answer);

/*
* Funkcja tworzy prawy w�ze� danego poddrzewa
* @param lvl poziom drzewa na kt�rym aktualnie si� znajdujemy
* @param previousNode w�ze� nadrz�dny (znajduj�cy sie wy�ej)
* @param itemsCopy - mo�liwe do upakowania przedmioty (bez odrzuconych)
* @param W - maksymalna no�no�� plecaka
* @param maxProfitOverall - wska�nik na zmienna statyczn�, kt�ra przechowuje najlepszy dotychczas osi�gni�ty profit
* @param positions - wska�nik do tablicy, kt�ra przechowuje ilo�� wyst�pie� w�z�ow na danym poziomie (index to poziom a warto�� pod tym indeksem to ilo�� ju� stworzonych na tym poziomie w�z�ow)
*/
Node* f_createRightNode(int lvl, Node* previousNode, vector<Item> itemsCopy, double W, double* maxProfitOverall, vector<int>* positions);


