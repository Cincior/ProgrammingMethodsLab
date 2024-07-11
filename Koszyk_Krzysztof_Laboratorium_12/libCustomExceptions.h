#pragma once
#include <stdexcept>
#include <fstream>
#include <exception>
using namespace std;

namespace CustomExceptions
{
    class FileOpenException : public std::runtime_error
    {
    public:
        FileOpenException() : std::runtime_error("Blad otwarcia pliku")
        {

        }
        FileOpenException(std::string msg) : std::runtime_error(msg.c_str())
        {

        }
    };

    class VariableError : public std::runtime_error
    {
    public:
        VariableError() : std::runtime_error("Niepoprawna zmienna")
        {

        }
        VariableError(std::string msg) : std::runtime_error(msg.c_str())
        {

        }
    };

    class SortError : public std::runtime_error
    {
    public:
        SortError() : std::runtime_error("Blad sortowania")
        {

        }
        SortError(std::string msg) : std::runtime_error(msg.c_str())
        {

        }
    };

    class DivisionError : public runtime_error
    {
    public:
        DivisionError() : runtime_error("Nie mozna wykonac dzielenia")
        {

        }
        DivisionError(string msg) : runtime_error(msg.c_str())
        {

        }
    };

}


