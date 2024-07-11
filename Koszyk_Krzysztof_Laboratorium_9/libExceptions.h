#pragma once
#include <iostream>
#include <string>

using namespace std;

// Typy b³êdów
enum EXCEPTION_CODE
{
	openError,
	readError,
	lackOfMemoryError,
	outOfRangeError,
	numberError
};

/*
* Wyœwietla zaistnia³e wyj¹tki
* @param error - typ b³êdu
*/
void showException(EXCEPTION_CODE error);
