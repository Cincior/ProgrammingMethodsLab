#pragma once
#include <exception>
#include <fstream>

using namespace std;

class MyExceptions : public runtime_error
{
public:
	MyExceptions() : runtime_error("Nieznany blad!")
	{

	}
	MyExceptions(string error) : runtime_error(error.c_str())
	{

	}
};

