#ifndef HILLCIPHER_ENKRIPSI_H
#define HILLCIPHER_ENKRIPSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_MIN 32
#define ASCII_MAX 126
#define RANGE_ASCII (ASCII_MAX - ASCII_MIN + 1)

void enkripsi_text(char *text, int key[2][2])
{
    int panjang_text = strlen(text);

    //menambahkan spasi jika panjang_teks bukan kelipatan 2
    if (panjang_text %2 != 0)
    {
        text[panjang_text] = ' ';
        panjang_text++;
        text[panjang_text] =  '\0';
    }

    for (int i = 0; i < panjang_text; i += 2)
    {
        int plain1 = text[i] - ASCII_MIN;
        int plain2 = text[i + 1] - ASCII_MIN;

        int enkripsi1 = (key[0][0] * plain1 + key[0][0] * plain2) % RANGE_ASCII + ASCII_MIN;
        int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

        printf("%c%c",enkripsi1,enkripsi2);
    }
    printf("\n");
}

#endif /* HILLCIPHER_ENKRIPSI_H */