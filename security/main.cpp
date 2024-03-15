#include "231511069.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    
    char *text = NULL;
    size_t text_length = 0;

    printf("Masukkan Text ");
    getline(&text,&text_length,stdin);
    text[strcspn(text, "\n")] =  '\0';

    //std::string encryptedString = enkripsi_text("al");
    //std::cout << "Encrypted String: " << encryptedString << std::endl;
    printf("Teks terenkripsi : ");
    enkripsi_text(text);
    printf("\nTeks terdekripsi : ");
    dekripsi_text(text);
    //free(text);

    return 0;

}