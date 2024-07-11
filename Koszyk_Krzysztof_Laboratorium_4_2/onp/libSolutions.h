#pragma once
#include <string>
#include <cctype>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

/*
* Funkcja czyœci wyra¿enie z niepotrzebnych znaków
* @param expression wyra¿enie do wyczyszczenia 
* @return wyczyszczone wyra¿enie
*/
string f_cleanExpression(string expression);
/*
* Funkcja czyœci wyra¿enie w notacji ONP z niepotrzebnych znaków
* @param expression wyra¿enie do wyczyszczenia
* @return wyczyszczone wyra¿enie
*/
string f_cleanExpressionONP(vector<string> expression);
/*
* Funkcja zamienia zapis ONP na INF
* @param expression wyra¿enie do zmiany
* @return zmienione wyra¿enie
*/
string f_ONP_To_INF(vector<string> expression);
/*
* Funkcja zamienia zapis INF na ONP
* @param expression wyra¿enie do zmiany
* @return zmienione wyra¿enie
*/
string f_INF_To_ONP(string expression);
/*
* Funkcja sprawdza priorytet znaku
* @param sign znak do sprawdzenia
* @return priorytet znaku
*/
int f_checkPriority(char sign);
/*
* Funkcja sprawdza ³¹cznoœæ operatora
* @param sign operator do sprawdzenia
* @return 1 - prawostronnie ³¹czny; 2 - lewostronnie ³¹czny
*/
int f_checkConnection(char sign);
/*
* Funkcja sprawdza poprawnoœæ zapisu infiksowego
* @param expression wyra¿enie do sprawdzenia
* @return true jeœli wyra¿enie jest poprawne
*/
bool f_validateINF(string expression);
/*
* Funkcja sprawdza poprawnoœæ zapisu w notacji ONP
* @param expression wyra¿enie do sprawdzenia
* @return true jeœli wyra¿enie jest poprawne
*/
bool f_validateONP(vector<string> expression);
/*
* Funkcja sprawdza czy w danym stringu zawarte s¹ tylko litery
* @param input ci¹g do sprawdzenia
* @return true jeœli wyra¿enie zawiera tylko litery
*/
bool f_containsLetters(string input);