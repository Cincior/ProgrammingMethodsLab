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
* Funkcja tworzy tablice dwuwymiarow¹ dynamiczn¹ typu double
* @param sizeArrayRow iloœæ wierszy w tablicy
* @param sizeArrayColumn iloœæ kolumn w tablicy
* @return adres utworzonej tablicy
*/
double** f_createArrayDouble(int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja tworzy kopie tablicy przekazanej 
* @param tab tablica do skopiowania
* @param sizeArrayRow iloœæ wierszy w tablicy
* @param sizeArrayColumn iloœæ kolumn w tablicy
* @return wskaŸnik do nowo powsta³ej tablicy
*/
double** f_copyArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja usuwa z pamiêci tablice dwuwymiarow¹ dynamiczn¹ typu double
* @param tab tablica do usuniêcia
* @param sizeArrayRow iloœæ wierszy w tablicy
* @param sizeArrayColumn iloœæ kolumn w tablicy
*/
void f_deleteArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);
/*
* Funkcja usuwa z pamiêci tablice dwuwymiarow¹ dynamiczn¹ typu double
* @param tab tablica do usuniêcia
* @param sizeArrayRow iloœæ wierszy w tablicy
* @param sizeArrayColumn iloœæ kolumn w tablicy
*/
void f_printArrayDouble(double** tab, int sizeArrayRow, int sizeArrayColumn);

#endif