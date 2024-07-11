#pragma once
#include <string>
#include <cctype>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

/*
* Funkcja czy�ci wyra�enie z niepotrzebnych znak�w
* @param expression wyra�enie do wyczyszczenia 
* @return wyczyszczone wyra�enie
*/
string f_cleanExpression(string expression);
/*
* Funkcja czy�ci wyra�enie w notacji ONP z niepotrzebnych znak�w
* @param expression wyra�enie do wyczyszczenia
* @return wyczyszczone wyra�enie
*/
string f_cleanExpressionONP(vector<string> expression);
/*
* Funkcja zamienia zapis ONP na INF
* @param expression wyra�enie do zmiany
* @return zmienione wyra�enie
*/
string f_ONP_To_INF(vector<string> expression);
/*
* Funkcja zamienia zapis INF na ONP
* @param expression wyra�enie do zmiany
* @return zmienione wyra�enie
*/
string f_INF_To_ONP(string expression);
/*
* Funkcja sprawdza priorytet znaku
* @param sign znak do sprawdzenia
* @return priorytet znaku
*/
int f_checkPriority(char sign);
/*
* Funkcja sprawdza ��czno�� operatora
* @param sign operator do sprawdzenia
* @return 1 - prawostronnie ��czny; 2 - lewostronnie ��czny
*/
int f_checkConnection(char sign);
/*
* Funkcja sprawdza poprawno�� zapisu infiksowego
* @param expression wyra�enie do sprawdzenia
* @return true je�li wyra�enie jest poprawne
*/
bool f_validateINF(string expression);
/*
* Funkcja sprawdza poprawno�� zapisu w notacji ONP
* @param expression wyra�enie do sprawdzenia
* @return true je�li wyra�enie jest poprawne
*/
bool f_validateONP(vector<string> expression);
/*
* Funkcja sprawdza czy w danym stringu zawarte s� tylko litery
* @param input ci�g do sprawdzenia
* @return true je�li wyra�enie zawiera tylko litery
*/
bool f_containsLetters(string input);