#include "hillcipher_enkripsi.h"
#include "hillcipher_dekripsi.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int key[2][2] = {{3,7},{5,11}};
    char text[10];

    printf("Masukkan Text ");
    scanf("%s",text);

    enkripsi_text(text);
    return 0;
}