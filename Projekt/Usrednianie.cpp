#include "Usrednianie.h"

void Usrednianie::przeksztalc(Bitmapa& bitmap)
{
    unsigned length = bitmap.length();
    unsigned width = bitmap.width();

    // Tworzymy now¹ bitmapê, która bêdzie przechowywaæ wynik
    BitmapaExt new_bitmap(length, width);

    // Iteracja po pikselach oryginalnej bitmapy
    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            // Liczymy liczbê bia³ych i czarnych s¹siadów piksela w oryginalnej bitmapie
            int white_neighbors = 0;
            int black_neighbors = 0;

            // Sprawdzamy piksele nad, pod, po lewej i po prawej stronie
            if (i > 0 && bitmap(i - 1, j))
                white_neighbors++;
            if (i < length - 1 && bitmap(i + 1, j))
                white_neighbors++;
            if (j > 0 && bitmap(i, j - 1))
                white_neighbors++;
            if (j < width - 1 && bitmap(i, j + 1))
                white_neighbors++;

            if (i > 0 && !bitmap(i - 1, j))
                black_neighbors++;
            if (i < length - 1 && !bitmap(i + 1, j))
                black_neighbors++;
            if (j > 0 && !bitmap(i, j - 1))
                black_neighbors++;
            if (j < width - 1 && !bitmap(i, j + 1))
                black_neighbors++;

            // Sprawdzamy, czy piksel spe³nia warunek
            if (bitmap(i, j) && black_neighbors > 2)
                new_bitmap(i, j) = false; // Zmieniamy piksel na czarny
            else if (!bitmap(i, j) && white_neighbors > 2)
                new_bitmap(i, j) = true; // Zmieniamy piksel na bia³y
            else
                new_bitmap(i, j) = bitmap(i, j); // Zachowujemy oryginaln¹ wartoœæ piksela
        }
    }

    // Kopiujemy wynik do oryginalnej bitmapy
    for (unsigned i = 0; i < length; ++i)
    {
        for (unsigned j = 0; j < width; ++j)
        {
            bitmap(i, j) = new_bitmap(i, j);
        }
    }
}
