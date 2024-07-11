#include "Erozja.h"

void Erozja::przeksztalc(Bitmapa& bitmap)
{
    unsigned length = bitmap.length();
    unsigned width = bitmap.width();

    // Tworzymy kopiê bitmapy
    BitmapaExt temp_bitmap(length, width);

    // Kopiujemy zawartoœæ oryginalnej bitmapy do tymczasowej
    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            temp_bitmap(i, j) = bitmap(i, j);
        }
    }

    // Iteracja po pikselach
    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            // Sprawdzamy, czy piksel jest czarny
            if (bitmap(i, j))
            {
                // Sprawdzamy, czy którykolwiek z s¹siadów piksela jest bia³y
                if ((i > 0 && !bitmap(i - 1, j)) || // Piksel nad nim
                    (i < length - 1 && !bitmap(i + 1, j)) || // Piksel pod nim
                    (j > 0 && !bitmap(i, j - 1)) || // Piksel po lewej
                    (j < width - 1 && !bitmap(i, j + 1))) // Piksel po prawej
                {
                    temp_bitmap(i, j) = false; // Ustawiamy piksel na czarny
                }
            }
        }
    }

    // Kopiujemy zmienion¹ bitmapê z powrotem do oryginalnej bitmapy
    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            bitmap(i, j) = temp_bitmap(i, j);
        }
    }
}
