#include "ZlozeniePrzeksztalcen.h"

void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& bitmap)
{
	for (int i = 0; i < transformations.size(); i++)
	{
		transformations[i]->przeksztalc(bitmap);
	}
}

void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
	this->transformations.push_back(p);
}
