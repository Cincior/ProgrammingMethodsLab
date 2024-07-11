#include "libSubset.h"
#include "libArray.h"


/*
* Funkcja pomocnicza.
* Wpisuje do pliku dany podzial liczby n
* Jeœli nie, dopisuje automatycznie
* @param S tablica podzialu
* @param R tablica podzialu
* @param d ilosc podzialow
*/
void printParts(int* S, int* R, int d, ofstream& fileWrite)
{
    for (int i = 1; i <= d; ++i) {
        for (int j = 0; j < R[i]; ++j) {
            fileWrite << S[i] << " ";
        }
    }
    fileWrite << "\n";
}

bool f_getAllSubsets(int n)
{
    ofstream fileWrite = f_openFileToWrite("wyniki.txt");
    if (!fileWrite.is_open())
    {
        return false;
    }

    int* B = f_createArray(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        B[i] = 0;
    }

    int i = 0, p, j;
    do
    {
        for (int index = 1; index < n + 1; index++)
        {
            fileWrite << B[index] << "";
        }
        fileWrite << "\n";
        i += 1;
        p = 1;
        j = i;
        while (j % 2 == 0)
        {
            j = j / 2;
            p = p + 1;
        }
        if (p <= n)
        {
            B[p] = 1 - B[p];
        }
    } while (p <= n);
    fileWrite.close();
    delete[] B;
    return true;
}

bool f_getKSubsets(int n, int k)
{
    std::ofstream fileWrite = f_openFileToWrite("wyniki2.txt");
    if (!fileWrite.is_open())
    {
        return false;
    }

    int* A = f_createArray(k + 1);
    for (int i = 1; i <= k; i++)
    {
        A[i] = i;
    }
    int p = k;
    while (p >= 1)
    {
        for (int i = 1; i <= k; i++)
        {
            fileWrite << A[i] << " ";
        }
        fileWrite << "\n";

        if (A[k] == n)
        {
            p = p - 1;
        }
        else
        {
            p = k;
        }

        if (p >= 1)
        {
            for (int i = k; i >= p; i--)
            {
                A[i] = A[p] + i - p + 1;
            }
        }
    }

    fileWrite.close();
    delete[] A;
    return true;
}

bool f_getPartsN(int n)
{
    ofstream fileWrite = f_openFileToWrite("wyniki3.txt");
    if (!fileWrite.is_open())
    {
        return false;
    }
    int* S = f_createArray(n + 1);
    int* R = f_createArray(n + 1);
    int d = 1, sum, l;
    S[1] = n;
    R[1] = 1;

    printParts(S, R, d, fileWrite);

    while (S[1] > 1)
    {
        sum = 0;
        if (S[d] == 1)
        {
            sum = sum + R[d];
            d -= 1;
        }
        sum = sum + S[d];
        R[d] = R[d] - 1;
        l = S[d] - 1;
        if (R[d] > 0)
        {
            d = d + 1;
        }
        S[d] = l;
        R[d] = sum / l;
        l = sum % l;
        if (l != 0)
        {
            d = d + 1;
            S[d] = l;
            R[d] = 1;
        }
        printParts(S, R, d, fileWrite);
    }

    fileWrite.close();
    delete[] S;
    delete[] R;
    return true;
}
