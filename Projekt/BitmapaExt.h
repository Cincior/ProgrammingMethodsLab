#pragma once
#include "Bitmapa.h"
#include <vector>
#include <iostream>

using namespace std;

class BitmapaExt : public Bitmapa
{
private:
	unsigned gridLength;
	unsigned gridWidth;
	bool** grid;
public:
	BitmapaExt(unsigned length, unsigned width);
	unsigned length() const override;
	unsigned width() const override;
	bool& operator()(unsigned x, unsigned y) override;
	bool operator()(unsigned x, unsigned y) const override;
	~BitmapaExt() override;

	friend ostream& operator<<(ostream& os, const BitmapaExt& bitmap);
};

