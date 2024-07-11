#include "libValidate.h"
#include <iostream>

bool f_validateInteger(long long value, long long startLimit, long long endLimit)
{
	if (value < startLimit || value > endLimit)
	{
		std::cout << "Niepoprawna liczba!";
		return false;
	}
	else
	{
		return true;
	}
}
