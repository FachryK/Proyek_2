#include "hillcipher_enkripsi.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int key[2][2] = {{1,2},{3,1}};
    char text[10];

    printf("Masukkan Text");
    scanf("%s",text);

    enkripsi_text(text , key);

    return 0;
}