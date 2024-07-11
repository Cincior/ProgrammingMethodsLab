#include "libFile.h"
#include <iostream>

using namespace std;
/*
* Funkcja pomocnicza.
* Sprawdza czy nazwa zawiera rozszerzenie .txt.
* Je?li nie, dopisuje automatycznie
* @param fileN Nazwa pliku
* @return poprawna nazwa pliku jako string
*/
string checkFileExtension(string fileN)
{
    if (fileN.length() > 4)
    {
        string extension = fileN.substr(fileN.length() - 4);
        if (extension != ".txt")
        {
            fileN += ".txt";
        }
    }
    else
    {
        fileN += ".txt";
    }
    return fileN;
}

ifstream f_openFileToRead(string fileName)
{
    ifstream fileHandler;
    fileName = checkFileExtension(fileName);

    fileHandler.open(fileName);


    return fileHandler;
}

ofstream f_openFileToWrite(string fileName)
{
    ofstream fileHandler;
    fileName = checkFileExtension(fileName);

    fileHandler.open(fileName);


    return fileHandler;
}