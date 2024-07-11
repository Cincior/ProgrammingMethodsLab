#pragma once
#include <cmath>
using namespace std;

/*
* Funkcja oblicza wartoœæ wielomianu stopnia N dla danego x
* @param N stopien rozpatrywanego wielomianu
* @param a wskaŸnik na pierwszy element tablicy ze wspó³czynnikami wielomianu
* @param x argument dla którego obliczamy wartoœæ wielomianu
* @return wynik dodawania elementów wielomianu
*/
int f_wielomian(int N, const int* a, int x);
/*
* Funkcja znajduje najwieksz¹ wartoœæ w tablicy
* @param N rozmiar tablicy
* @param t wskaŸnik do tablicy
* @return adres przechowuj¹cy najwiêkszy element tablicy
*/
const int* f_maximum(int N, const int* t);
/*
* Funkcja oblicza wartoœæ symbolu Newtona
* @param N rozmiar tablicy
* @param t wskaŸnik do tablicy
* @return adres przechowuj¹cy najwiêkszy element tablicy
*/
int f_newton(int N, int K);
/*
* Funkcja oblicza wartoœæ silni
* @param n liczba, dla której oblicza siê silnie
* @return silnia n
*/
long long silnia(int n);
/*
* Funkcja sprawdzam która z liczb jest wiêksza
* @param a liczba pierwsza
* @param b liczba druga
* @return wskaŸnik do wiêkszej z liczb 
*/
const int* f_porownaj(int* a, const int* b);
/*
* Funkcja oblicza srednia warunkowa i sprawdza ile liczb spelnia warunek w funkcji f
* @param s przechwuje obliczon¹ œredni¹
* @param f wskaŸnik do funkcji sprawdzajacej
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @return ilosc elementów zakresu [b, e), dla których wartoœæ f jest równa true
*/
unsigned int f_sredniaWarunkowa(double& s, bool (*f)(int), const int* b, const int* e);
/*
* Funkcja pomocnicza
* @param x liczba ca³kowita
* @return true
*/
bool f(int x);
/*
* Funkcja pomocnicza
* @param x liczba ca³kowita
* @return false
*/
bool f2(int x);
/*
* Funkcja oblicza sumê wa¿on¹
* @param s przechwuje sumê\
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @param a wskaŸnik do tablicy danych
* @return ilosc elementów zakresu [b, e), dla których wartoœæ f jest równa true
*/
bool f_sumaWazona(double& s, double* b, double* e, double* a);
/*
* Funkcja pomocnicza która oblicza sume iloczynów liczb z danego zakresu
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @param a wskaŸnik do tablicy danych
* @return suma iloczynów elementów od 0 do n, gdzie n to iloœæ liczb w zakresie [b, e)
*/
double f_sumaIloczynowZakresu(double* b, double* e, double* a);
/*
* Funkcja oblicza sumê elementów z danego zakresu
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @return suma wszystkich elementów z zakresu [b, e)
*/
double f_sumaZakresu(double* b, double* e);
/*
* Funkcja sprawdza, czy w danym zakresie liczb wystêpuje liczba ujemna
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @return true jeœli wystêpuje liczba ujemna
*/
bool f_wystapienieUjemnychWZakresie(double* b, double* e);
/*
* Funkcja oblicza sumê tylko tych elementów, które zwróæ¹ true w funkcji f
* @param f wskaŸnik do funkcji sprawdzajacej
* @param b pocz¹tek zakresu
* @param e koniec zakresu
* @param iloscSpelniajacaWarunek iloœæ elementów które spe³niaja warunek czyli takie liczby, które przekazane do funkcji f spowoduj¹ zwrócenie true przez tê funkcjê
* @return iloœæ liczb spe³niaj¹cyh warunek
*/
int f_sumaWarunkowa(bool (*f)(int), const int* b, const int* e, int& iloscSpelniajacaWarunek);