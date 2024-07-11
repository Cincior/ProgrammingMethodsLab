#pragma once
#include <fstream>
#include <exception>

using namespace std;

namespace CustomExceptions
{
	class FileOpenException : public runtime_error
	{
	public:
		FileOpenException() : runtime_error("Blad otwarcia pliku")
		{

		}
		FileOpenException(string msg) : runtime_error(msg.c_str()) 
		{

		}
	};

	class VariableError : public runtime_error
	{
	public:
		VariableError() : runtime_error("Niepoprawna zmienna")
		{

		}
		VariableError(string msg) : runtime_error(msg.c_str())
		{

		}
	};


}