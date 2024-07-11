#include "cTablica.h"

void f_swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void cTablica::resetCounters()
{
    comparisons = 0;
    swaps = 0;
}


void cTablica::shakerSort(int* tab, int n)
{
    resetCounters();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            comparisons++;
            if (tab[i] > tab[i + 1])
            {
                swap(tab[i], tab[i + 1]);
                swaps++;
                swapped = true;
            }
        }

        if (!swapped) // jesli nie zmieniono zadnego elementu, to zbiór jest posortowany
        {
            break;
        }

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; --i)
        {
            comparisons++;
            if (tab[i] > tab[i + 1])
            {
                swap(tab[i], tab[i + 1]);
                swaps++;
                swapped = true;
            }
        }

        start++;
    }
}

void cTablica::quickSortLomuto(int* tab, int start, int end)
{
    if (start < end)
    {
        int q = lomutoPartition(tab, start, end);

        quickSortLomuto(tab, start, q - 1);
        quickSortLomuto(tab, q + 1, end);
    }
    return;
}

void cTablica::quickSortHoare(int* tab, int start, int end)
{
    if (start < end)
    {
        int q = hoarePartition(tab, start, end);

        quickSortHoare(tab, start, q);
        quickSortHoare(tab, q + 1, end);
    }
    return;
}

int cTablica::lomutoPartition(int* tab, int start, int end)
{
    int pivot = tab[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++)
    {
        comparisons++;
        if (tab[j] <= pivot)
        {
            i++;
            swap(tab[i], tab[j]);
            swaps++;
        }
    }
    swap(tab[i + 1], tab[end]);
    swaps++;
    return i + 1;
}

int cTablica::hoarePartition(int* tab, int start, int end)
{
    int pivot = tab[start];
    int i = start - 1;
    int j = end + 1;

    while (true)
    {
        do
        {
            j--;
            comparisons++;
        } while (tab[j] > pivot);

        do
        {
            i++;
            comparisons++;
        } while (tab[i] < pivot);

        comparisons++;
        if (i < j)
        {
            swap(tab[i], tab[j]);
            swaps++;
        }
        else
        {
            return j;
        }
    }
}

void cTablica::heapify(int* tab, int n, int i)
{
    int largest = i; // Inicjalizacja largest jako korzenia
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // Jeœli lewy potomek jest wiêkszy od korzenia
    comparisons++;
    if (left < n && tab[left] > tab[largest])
        largest = left;

    // Jeœli prawy potomek jest wiêkszy od najwiêkszego dotychczas
    comparisons++;
    if (right < n && tab[right] > tab[largest])
        largest = right;

    // Jeœli largest nie jest korzeniem
    if (largest != i) {
        swap(tab[i], tab[largest]);
        swaps++;

        // Rekurencyjnie heapify na dotkniêtym poddrzewie
        heapify(tab, n, largest);
    }
}

void cTablica::heapSort(int* tab, int n)
{
    resetCounters();

    // Budowanie kopca (przekszta³canie tablicy)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(tab, n, i);

    // Jeden po drugim wyodrêbnianie elementu z kopca
    for (int i = n - 1; i > 0; i--) {
        // Przenoszenie obecnego korzenia na koniec
        swap(tab[0], tab[i]);
        swaps++;

        // Wywo³anie heapify na zredukowanym kopcu
        heapify(tab, i, 0);
    }
}

// Implementacja metod zwracaj¹cych statystyki
unsigned long long cTablica::getComparisons() const {
    return comparisons;
}

unsigned long long cTablica::getSwaps() const {
    return swaps;
}

void cTablica::printTab(int* tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
    cout << "Liczba porownan: " << comparisons << "\nLiczba przestawien: " << swaps << "\n";
}