#pragma once
#include "Przeksztalcenie.h"
#include <vector>
using namespace std;

class ZlozeniePrzeksztalcen : public Przeksztalcenie
{
private:
	vector<Przeksztalcenie*> transformations;
public:
	void przeksztalc(Bitmapa& bitmap);
	void dodajPrzeksztalcenie(Przeksztalcenie* p);
};

