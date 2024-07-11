#pragma once
#include <vector>
#include <iostream>

using namespace std;

class cTablica
{
    unsigned long long comparisons;
    unsigned long long swaps;
    void resetCounters();
    void heapify(int* tab, int n, int i); // Deklaracja metody pomocniczej dla sortowania przez kopcowanie

public:
    cTablica() : comparisons(0), swaps(0) {}

    void shakerSort(int* tab, int n);
    void quickSortLomuto(int* tab, int start, int end);
    void quickSortHoare(int* tab, int start, int end);
    void heapSort(int* tab, int n); // Deklaracja metody sortowania przez kopcowanie
    int lomutoPartition(int* tab, int start, int end);
    int hoarePartition(int* tab, int start, int end);
    void printTab(int* tab, int n);
    // Deklaracje metod zwracaj¹cych statystyki
    unsigned long long getComparisons() const;
    unsigned long long getSwaps() const;
};