#pragma once
#include <iostream>
#include <string>

using namespace std;

// Typy b��d�w
enum EXCEPTION_CODE
{
	openError,
	readError,
	lackOfMemoryError,
	outOfRangeError,
	numberError
};

/*
* Wy�wietla zaistnia�e wyj�tki
* @param error - typ b��du
*/
void showException(EXCEPTION_CODE error);
