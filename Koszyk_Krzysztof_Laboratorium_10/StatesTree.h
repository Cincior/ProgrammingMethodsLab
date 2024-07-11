#pragma once
#include <vector>
#include <iostream>
#include "libFile.h"

using namespace std;

// Opis przedmiotu, który mo¿e zostaæ zapakowany do plecaka
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

// Opis wêz³a, który symbolizuje aktualnie badane upakowanie
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
* Funkcja oblicza bound potrzebny do okreœlenia, czy dany wêze³ jest obiecuj¹cy
* @param items - mo¿liwe do upakowania przedmioty
* @param W - maksymalna noœnoœæ plecaka
* @param node - wskaŸnik na wêze³, którego dane aktualnie wykorzystujemy do obliczania bound
* @param lvl poziom drzewa na którym aktualnie siê znajdujemy
* @return obliczony bound
*/
double f_getBound(vector<Item> items, double W, Node* node, int lvl);

/*
* Funkcja oblicza index K potrzebny do wzoru
* @param remainingItems - mo¿liwe do upakowania przedmioty bez przedmiotu, który nie jest brany pod uwagê przy pakowaniu (jego wartosc to 0)
* @param W - maksymalna noœnoœæ plecaka
* @return obliczone K
*/
int f_getK(vector<Item> remainingItems, double W);

/*
* Funkcja oblicza totalWeight potrzebne do wzoru na bound
* @param j - aktualnie rozpatrywany poziom drzewa + 1
* @param k - obliczone k za pomoc¹ funkcji getK
* @param items - mo¿liwe do upakowania przedmioty
* @param node - wskaŸnik na wêze³, którego dane aktualnie wykorzystujemy do obliczania 
* @param W - maksymalna noœnoœæ plecaka
* @return obliczony totalWeight
*/
double f_getTotW(int j, int k, vector<Item> items, Node* node, double W);

/*
* Funkcja tworzy kopiê tablicy przedmiotów w celu poprawnego obliczania danych w prawych galêziach drzewa, gdzie pewne przedmioty nie s¹ brane pod uwagê
* @param items - mo¿liwe do upakowania przedmioty
* @param lvl poziom drzewa na którym aktualnie siê znajdujemy
* @return przedmioty, gdzie wartoœæ przedmotu nie branego pod uwagê wynosi 0
*/
vector<Item> f_createItemsCopy(vector<Item> items, int lvl);

/*
* Funkcja tworzy drzewo stanów pozwalaj¹ce sprawdziæ jakie upakowanie bêdzie najkorzystniejsze
* @param depth g³êbokoœæ drzewa
* @param lvl poziom drzewa na którym aktualnie siê znajdujemy
* @param previousNode wêze³ nadrzêdny (znajduj¹cy sie wy¿ej)
* @param items - mo¿liwe do upakowania przedmioty
* @param W - maksymalna noœnoœæ plecaka
* @param answer - wskaŸnik na wêze³, który wskazywa³ bêdzie najlepsze upakowanie
*/
void f_createTree(int depth, int lvl, Node* previousNode, vector<Item> items, double W, Node*& answer);

/*
* Funkcja wypisuje strukture drzewa
* @param previousNode wêze³ nadrzêdny (znajduj¹cy sie wy¿ej)
* @param n - iloœæ poziomów drzewa
*/
void f_printTree(Node* previousNode, int n);

/*
* @param items - mo¿liwe do upakowania przedmioty
* @param W - maksymalna noœnoœæ plecaka
*/
Node* f_initializeRoot(vector<Item> items, double W);

/*
* Funkcja tworzy lewy wêze³ danego poddrzewa
* @param lvl poziom drzewa na którym aktualnie siê znajdujemy
* @param previousNode wêze³ nadrzêdny (znajduj¹cy sie wy¿ej)
* @param items - mo¿liwe do upakowania przedmioty
* @param W - maksymalna noœnoœæ plecaka
* @param maxProfitOverall - wska¿nik na zmienna statyczn¹, która przechowuje najlepszy dotychczas osi¹gniêty profit
* @param positions - wskaŸnik do tablicy, która przechowuje iloœæ wyst¹pieñ wêz³ow na danym poziomie (index to poziom a wartoœæ pod tym indeksem to iloœæ ju¿ stworzonych na tym poziomie wêz³ow)
* @param answer wskaŸnik na wêze³, który przechowuje adres wêz³a reprezentuj¹cego najlepsze upakowanie
*/
Node* f_createLeftNode(int lvl, Node* previousNode, vector<Item> items, double W, double* maxProfitOverall, vector<int>* positions, Node*& answer);

/*
* Funkcja tworzy prawy wêze³ danego poddrzewa
* @param lvl poziom drzewa na którym aktualnie siê znajdujemy
* @param previousNode wêze³ nadrzêdny (znajduj¹cy sie wy¿ej)
* @param itemsCopy - mo¿liwe do upakowania przedmioty (bez odrzuconych)
* @param W - maksymalna noœnoœæ plecaka
* @param maxProfitOverall - wska¿nik na zmienna statyczn¹, która przechowuje najlepszy dotychczas osi¹gniêty profit
* @param positions - wskaŸnik do tablicy, która przechowuje iloœæ wyst¹pieñ wêz³ow na danym poziomie (index to poziom a wartoœæ pod tym indeksem to iloœæ ju¿ stworzonych na tym poziomie wêz³ow)
*/
Node* f_createRightNode(int lvl, Node* previousNode, vector<Item> itemsCopy, double W, double* maxProfitOverall, vector<int>* positions);


