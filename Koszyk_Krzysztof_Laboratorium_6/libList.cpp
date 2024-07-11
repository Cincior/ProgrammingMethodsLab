#include "libList.h"
#include <iostream>

void listStruct::addElementback(int element)
{
	elementOfList* newElement = new elementOfList(element);
	newElement->point = element;
	if (head == nullptr)
	{
		head = newElement;
	}
	else
	{
		elementOfList* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newElement;
		newElement->next = nullptr;
	}
}

void listStruct::printElements()
{
	elementOfList* temp = head;
	while (temp)
	{
		std::cout << temp->point << " ";
		temp = temp->next;
	}
}

elementOfList::elementOfList(int value)
{
	this->point = value;
	this->next = nullptr;
}

int listStruct::length()
{
	int length = 0;
	elementOfList* temp = head;
	while (temp)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

void listStruct::deleteEelement(int value)
{
	elementOfList* current = head;
	elementOfList* prev = nullptr;

	while (current != nullptr && current->point != value) 
	{
		prev = current;
		current = current->next;
	}

	if (current == nullptr) 
	{
		cout << "Nie ma takiego elementu" << endl;
		return;
	}

	if (prev == nullptr)  // pierwszy element
	{
		head = current->next;
	}
	else 
	{
		prev->next = current->next;
	}

	delete current;
}
