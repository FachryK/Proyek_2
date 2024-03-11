#ifndef HILLCIPHER_DEKRIPSI_H
#define HILLCIPHER_DEKRIPSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_MIN 32
#define ASCII_MAX 126
#define RANGE_ASCII (ASCII_MAX - ASCII_MIN + 3)

void dekripsi_text(char *text)
{
    // int key[2][2]={{3,7},{5,11}};
    
    int panjang_text = strlen(text);


     int invkey[2][2] = {{93, -26}, {-94, 29}};

    for (int i = 0; i < panjang_text; i += 2)
    {
        int ciper1 = text[i] - ASCII_MIN;
        int ciper2 = text[i+1] - ASCII_MIN;

        int dekripsi1 = (invkey[0][0] * ciper1 + invkey[0][1] * ciper2) % RANGE_ASCII + ASCII_MIN;
        int dekripsi2 = (invkey[1][0] * ciper1 + invkey[1][1] * ciper2) % RANGE_ASCII + ASCII_MIN;

        printf("%c%c",dekripsi1,dekripsi2);
    }
    
}

#endif /* HILLCIPHER_DEKRIPSI_H */
