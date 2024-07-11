#ifndef LIBARRAY_H
#define LIBARRAY_H 

#include<iostream>

/*
* Funkcja tworzy tablice jednowymiarowa dynamiczna
* @param sizeArray rozmiar tablicy
* @return adres utworzonej tablicy
*/
int* f_createArray(int sizeArray);
/*
* Funkcja tworzy tablice dwuwymiarow� dynamiczn� typu double
* @param sizeArrayRow ilo�� wierszy w tablicy
* @param sizeArrayColumn ilo�� kolumn w tablicy
* @return adres utworzonej tablicy
*/
double** f_createArrayDouble(int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja tworzy kopie tablicy przekazanej 
* @param tab tablica do skopiowania
* @param sizeArrayRow ilo�� wierszy w tablicy
* @param sizeArrayColumn ilo�� kolumn w tablicy
* @return wska�nik do nowo powsta�ej tablicy
*/
double** f_copyArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja usuwa z pami�ci tablice dwuwymiarow� dynamiczn� typu double
* @param tab tablica do usuni�cia
* @param sizeArrayRow ilo�� wierszy w tablicy
* @param sizeArrayColumn ilo�� kolumn w tablicy
*/
void f_deleteArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja wypisuje tablice dwuwymiarow� dynamiczn� typu double
* @param tab tablica do wypisania
* @param sizeArrayRow ilo�� wierszy w tablicy
* @param sizeArrayColumn ilo�� kolumn w tablicy
*/
void f_printArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja wypisuje tablice dynamiczn� typu int
* @param tab tablica do wypisania
* @param sizeArray rozmiar tablicy
*/
void f_printArray(int* tab, int sizeArray);
#endif