#include <iostream>
#include "libArray.h"
#include "libFile.h"
#include "libGraph2.h"
#include "libList.h"
#include <list>

using namespace std;

int main()
{
    string fileName = "wejscie";
    int biggestNumber = f_biggestNumberOfGraphPoint(fileName);
    int amountOfConnections = f_amountOfConnectionsInGraph(fileName);

    list<int>* incidentTab = nullptr;
    incidentTab = f_incidentTabList(amountOfConnections, biggestNumber, fileName);

    cout << "Uzywajac std::list\n";
    for (int i = 0; i < biggestNumber; i++)
    {
        cout << (i + 1) << ": ";
        for (int point : incidentTab[i])
        {
            cout << point << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < biggestNumber; i++)
    {
        cout << "Stopien wierzcholka " << (i + 1) << ": ";
        cout << incidentTab[i].size(); 
        cout << "\n";
    }

    cout << "Uzywajac wlasnej listy zbudowanej na podstawie struct:\n";
    listStruct* incidentTab2 = f_incidentMyList(amountOfConnections, biggestNumber, fileName);
    
    for (int i = 0; i < biggestNumber; i++)
    {
        cout << (i + 1) << ": ";
        incidentTab2[i].printElements();
        cout << "\n";
    }
    for (int i = 0; i < biggestNumber; i++)
    {
        cout << "Stopien wierzcholka " << (i + 1) << ": ";
        cout << incidentTab2[i].length();
        cout << "\n";
    }

}