#include "BitmapaExt.h"
#include "MyExceptions.h"

BitmapaExt::BitmapaExt(unsigned length, unsigned width)
{
	try
	{
		if (length > 100000 || width > 100000) // nie sprawdzam, czy s¹ mniejsze od 0, bo s¹ typu unsigned
		{
			throw MyExceptions("Bledne dane inicjujace bitmape. Ustawiam obie zmienne na 10\n");
		}
	}
	catch (const exception& error)
	{
		cerr << error.what();
		// Jeœli wyst¹pi b³ad, ustawiam obie zmienne na 10
		this->gridLength = 10;
		this->gridWidth = 10;
	}
	this->gridLength = length;
	this->gridWidth = width;
	
	// Inicjalizacja bitmapy
	grid = new bool* [this->length()];
	for (unsigned i = 0; i < this->length(); i++) 
	{
		grid[i] = new bool[this->width()];
		for (unsigned j = 0; j < this->width(); ++j)
		{
			grid[i][j] = false;
		}
	}
}

unsigned BitmapaExt::length() const
{
	return this->gridLength;
}

unsigned BitmapaExt::width() const
{
	return this->gridWidth;
}

bool& BitmapaExt::operator()(unsigned x, unsigned y)
{
	try
	{
		if (x >= this->length() || y >= this->width())
		{
			throw MyExceptions("Niepoprawny index\n");
		}
	}
	catch (const exception& error)
	{
		cerr << error.what();
		return grid[0][0];
	}
	return grid[x][y];
}

bool BitmapaExt::operator()(unsigned x, unsigned y) const
{
	try
	{
		if (x >= this->length() || y >= this->width())
		{
			throw MyExceptions("Niepoprawny index\n");
		}
	}
	catch (const exception& error)
	{
		cerr << error.what();
		return grid[0][0];
	}

	return grid[x][y];
}

BitmapaExt::~BitmapaExt()
{
	for (unsigned i = 0; i < this->length(); i++) 
	{
		delete[] grid[i];
	}
	delete[] grid;
	//cout << "Usunieto bitmape!";
}

ostream& operator<<(ostream& os, const BitmapaExt& bitmap)
{
	for (unsigned i = 0; i < bitmap.length(); i++)
	{
		for (unsigned j = 0; j < bitmap.width(); j++)
		{
			os << bitmap(i, j) << " ";
		}
		os << "\n";
	}
	os << "\n";
	return os;
}

