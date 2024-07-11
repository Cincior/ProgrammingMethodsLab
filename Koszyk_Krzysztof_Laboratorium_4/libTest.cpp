#include "libTest.h"

void f_testArrayStack()
{
	ifstream fileRead = f_openFileToRead("wejscie");
	int n = 0, v = 0;
	fileRead >> n;

	cout << "TEST IMPLEMENTACJI STOSU ZA POMOCA TABLICY DYNAMICZNEJ:\n";
	StackArray stackA(n);
	cout << "Przed dodaniem elementow do stosu:\n";
	stackA.isEmpty();
	cout << "Po dodaniu:\n";
	for (int i = 0; i < n; i++)
	{
		fileRead >> v;
		stackA.push(v);
	}
	cout << "Ilosc elementow: " << stackA.amountOfElements() << " Wartosc szczytowego: " << stackA.getTop();
	stackA.pop();
	cout << "\nWartosc szczytowego po usunieciu jednego elementu: " << stackA.getTop();
	fileRead.close();
}

void f_testListStack()
{
	ifstream fileRead2 = f_openFileToRead("wejscie");
	int n = 0, v = 0;
	fileRead2 >> n;
	cout << "\n\nTEST IMPLEMENTACJI STOSU ZA POMOCA KOLEJKI:\n";
	Element* top = nullptr;
	cout << "Stos jest pusty: " << (f_isEmpty(top) ? "TAK" : "NIE") << " Aktualna ilosc elementow: " << f_amountOfElements(top);
	for (int i = 0; i < n; i++)
	{
		fileRead2 >> v;
		f_push(top, v);
	}

	cout << "\nTop element po dodaniu 5. elementow: " << f_getTop(top) << endl;
	std::cout << "Aktualna ilosc elementow: " << f_amountOfElements(top) << endl;

	f_pop(top);
	f_pop(top);
	f_pop(top);
	f_pop(top);
	cout << "Top element po usunieciu 4. elementow: " << f_getTop(top) << endl;
	cout << "Aktualna ilosc elementow: " << f_amountOfElements(top) << endl;
}

void f_testAdapterStack()
{
	ifstream fileRead2 = f_openFileToRead("wejscie");
	int n = 0, v = 0;
	fileRead2 >> n;

	stack<int> head;
	cout << "\nTEST IMPLEMENTACJI STOSU ZA POMOCA ADAPTERA:\n";
	cout << "Stos jest pusty: " << (head.empty() ? "Tak" : "Nie");
	cout << "\nAktualna ilosc elementow: " << head.size();

	for (int i = 0; i < n; i++)
	{
		fileRead2 >> v;
		head.push(v);
	}
	cout << "\nTop element po dodaniu 5. elementow: " << head.top() << endl;
	std::cout << "Aktualna ilosc elementow: " << head.size() << endl;
	head.pop();
	cout << "Top element po usunieciu jednego elementu: " << head.top() << endl;
	cout << "Aktualna ilosc elementow: " << head.size() << endl;
}
