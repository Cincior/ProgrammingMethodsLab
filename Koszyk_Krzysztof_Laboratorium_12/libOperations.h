#pragma once
#include <iostream>
#include <stdexcept>
#include <cstring>
#include "libCustomExceptions.h"

using namespace std;

template<typename type, typename returnType>
inline returnType fsub(type element1, type element2)
{
    return element1 - element2;
}


template<typename type, typename returnType>
inline returnType fdiv(type element1, type element2)
{
    try
    {
        if (element2 == 0)
        {
            throw CustomExceptions::DivisionError("NIE DZIEL PRZEZ 0");
        }
        else
        {
            return (element1 / element2);
        }
    }
    catch (const exception& e)
    {
        cout << e.what();
        return 0;
    }
    
}

//DLA CHAR*
template<typename type>
inline double fdiv(type element1, type element2)
{
    try
    {
        if (*element2 == 0)
        {
            throw CustomExceptions::DivisionError("NIE DZIEL PRZEZ 0");
        }
        else
        {
            return (*element1 / *element2);
        }
    }
    catch (const exception& e)
    {
        cout << e.what();
        return 0;
    }
}

template<typename type, typename returnType>
inline returnType fadd(type element1, type element2)
{
    return element1 + element2;
}

template<typename type, typename returnType>
inline returnType fmul(type element1, type element2)
{
    if (element1 == 0 || element2 == 0)
    {
        throw std::runtime_error("Nie mo¿na mno¿yæ przez zero!");
    }
    else
    {
        return element1 * element2;
    }
}

template<typename type, typename returnType>
inline returnType flen(type element1, type element2)
{
    if (element1 == nullptr || element2 == nullptr)
    {
        throw std::invalid_argument("Pusty wskaŸnik!");
    }
    return strlen(element1) + strlen(element2);
}

