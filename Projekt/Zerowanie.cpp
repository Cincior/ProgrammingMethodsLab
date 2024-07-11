#include "Zerowanie.h"

void Zerowanie::przeksztalc(Bitmapa& bitmap)
{
    for (unsigned i = 0; i < bitmap.length(); i++) 
    {
        for (unsigned j = 0; j < bitmap.width(); j++) 
        {
            bitmap(i, j) = false;
        }
    }
}
