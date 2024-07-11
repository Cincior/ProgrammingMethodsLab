#pragma once
#include <cmath>
using namespace std;

/*
* Funkcja oblicza warto�� wielomianu stopnia N dla danego x
* @param N stopien rozpatrywanego wielomianu
* @param a wska�nik na pierwszy element tablicy ze wsp�czynnikami wielomianu
* @param x argument dla kt�rego obliczamy warto�� wielomianu
* @return wynik dodawania element�w wielomianu
*/
int f_wielomian(int N, const int* a, int x);
/*
* Funkcja znajduje najwieksz� warto�� w tablicy
* @param N rozmiar tablicy
* @param t wska�nik do tablicy
* @return adres przechowuj�cy najwi�kszy element tablicy
*/
const int* f_maximum(int N, const int* t);
/*
* Funkcja oblicza warto�� symbolu Newtona
* @param N rozmiar tablicy
* @param t wska�nik do tablicy
* @return adres przechowuj�cy najwi�kszy element tablicy
*/
int f_newton(int N, int K);
/*
* Funkcja oblicza warto�� silni
* @param n liczba, dla kt�rej oblicza si� silnie
* @return silnia n
*/
long long silnia(int n);
/*
* Funkcja sprawdzam kt�ra z liczb jest wi�ksza
* @param a liczba pierwsza
* @param b liczba druga
* @return wska�nik do wi�kszej z liczb 
*/
const int* f_porownaj(int* a, const int* b);
/*
* Funkcja oblicza srednia warunkowa i sprawdza ile liczb spelnia warunek w funkcji f
* @param s przechwuje obliczon� �redni�
* @param f wska�nik do funkcji sprawdzajacej
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @return ilosc element�w zakresu [b, e), dla kt�rych warto�� f jest r�wna true
*/
unsigned int f_sredniaWarunkowa(double& s, bool (*f)(int), const int* b, const int* e);
/*
* Funkcja pomocnicza
* @param x liczba ca�kowita
* @return true
*/
bool f(int x);
/*
* Funkcja pomocnicza
* @param x liczba ca�kowita
* @return false
*/
bool f2(int x);
/*
* Funkcja oblicza sum� wa�on�
* @param s przechwuje sum�\
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @param a wska�nik do tablicy danych
* @return ilosc element�w zakresu [b, e), dla kt�rych warto�� f jest r�wna true
*/
bool f_sumaWazona(double& s, double* b, double* e, double* a);
/*
* Funkcja pomocnicza kt�ra oblicza sume iloczyn�w liczb z danego zakresu
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @param a wska�nik do tablicy danych
* @return suma iloczyn�w element�w od 0 do n, gdzie n to ilo�� liczb w zakresie [b, e)
*/
double f_sumaIloczynowZakresu(double* b, double* e, double* a);
/*
* Funkcja oblicza sum� element�w z danego zakresu
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @return suma wszystkich element�w z zakresu [b, e)
*/
double f_sumaZakresu(double* b, double* e);
/*
* Funkcja sprawdza, czy w danym zakresie liczb wyst�puje liczba ujemna
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @return true je�li wyst�puje liczba ujemna
*/
bool f_wystapienieUjemnychWZakresie(double* b, double* e);
/*
* Funkcja oblicza sum� tylko tych element�w, kt�re zwr�� true w funkcji f
* @param f wska�nik do funkcji sprawdzajacej
* @param b pocz�tek zakresu
* @param e koniec zakresu
* @param iloscSpelniajacaWarunek ilo�� element�w kt�re spe�niaja warunek czyli takie liczby, kt�re przekazane do funkcji f spowoduj� zwr�cenie true przez t� funkcj�
* @return ilo�� liczb spe�niaj�cyh warunek
*/
int f_sumaWarunkowa(bool (*f)(int), const int* b, const int* e, int& iloscSpelniajacaWarunek);