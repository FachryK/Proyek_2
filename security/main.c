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

    // char *hasil_enkripsi = NULL;
    enkripsi_text(text/*,hasil_enkripsi*/);

    
//    free(hasil_enkripsi);

    // printf("dekripsi text");
    // dekripsi_text(text , key );

    return 0;
}