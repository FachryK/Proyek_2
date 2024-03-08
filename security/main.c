#include "hillcipher_enkripsi.h"
#include "hillcipher_dekripsi.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int key[2][2] = {{3,7},{5,11}};
    char *text = NULL;
    size_t text_length = 0;


    printf("Masukkan Text ");
    getline(&text,&text_length,stdin);
    text[strcspn(text, "\n")] =  '\0';
    enkripsi_text(text);
    free(text);
    return 0;
}