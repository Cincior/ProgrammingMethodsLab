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
	* @param element warto��, kt�ra ma by� dodana do listy
	*/
	void addElementback(int element);
	/*
	* Funkcja usuwa dany element z listy
	* @param value warto��, kt�ra ma by� usuni�ta
	*/
	void deleteEelement(int value);
	/*
	* Funkcja wypisuje na konsole elementy z listy
	*/
	void printElements();
	/*
	* Funkcja zwraca aktualn� ilo�� element�w listy
	*/
	int length();
};