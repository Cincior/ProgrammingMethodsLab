#include "Inwersja.h"

void Inwersja::przeksztalc(Bitmapa& bitmap)
{
    unsigned length = bitmap.length();
    unsigned width = bitmap.width();

    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            bool& pixel = bitmap(i, j);
            pixel = !pixel; // Inwersja piksela
        }
    }
}
