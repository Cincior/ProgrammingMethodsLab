#include "libStackList.h"

bool f_isEmpty(Element* top)
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int f_amountOfElements(Element* top)
{
	int count = 0;
	Element* temp = top;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int f_getTop(Element* top)
{
	if (!f_isEmpty(top))
	{
		return top->value;
	}
	else
	{
		cout << "Stos pusty!\n";
		return -1;
	}
}

void f_push(Element*& top, int v)
{
	Element* newEl = new Element;
	newEl->value = v;
	newEl->next = top;
	top = newEl;
}

int f_pop(Element*& top)
{
	if (!f_isEmpty(top))
	{
		int v = top->value;
		Element* temp = top;
		top = top->next;
		delete temp;
		return v;
	}
	else
	{
		cout << "Stos pusty!\n";
		return -1;
	}
	
}
