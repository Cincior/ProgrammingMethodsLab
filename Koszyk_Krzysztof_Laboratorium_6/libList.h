#pragma once
using namespace std;

struct elementOfList
{
	int point;
	elementOfList* next;
	elementOfList(int value);
};

struct listStruct
{
	elementOfList* head = nullptr;
	/*
	* Funkcja dodaje element na koniec listy
	* @param element wartoœæ, która ma byæ dodana do listy
	*/
	void addElementback(int element);
	/*
	* Funkcja usuwa dany element z listy
	* @param value wartoœæ, która ma byæ usuniêta
	*/
	void deleteEelement(int value);
	/*
	* Funkcja wypisuje na konsole elementy z listy
	*/
	void printElements();
	/*
	* Funkcja zwraca aktualn¹ iloœæ elementów listy
	*/
	int length();
};