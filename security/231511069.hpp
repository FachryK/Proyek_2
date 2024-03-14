#ifndef HILLCIPHER_ENKRIPSI_H
#define HILLCIPHER_ENKRIPSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <sstream>

#define ASCII_MIN 32
#define ASCII_MAX 126
#define RANGE_ASCII (ASCII_MAX - ASCII_MIN + 1)



// Fungsi enkripsi_text dengan overload
std::string enkripsi_text(int data) {
    std::ostringstream textStream;
    textStream << data;
    std::string text = textStream.str();
    
    const unsigned char *input = (const unsigned char *)text.c_str();
    int panjang_text = text.length();
    int key[2][2] = {{6,5},{3,4}};

    std::ostringstream hasil_enkripsi;

    // Menambahkan spasi jika panjang_teks bukan kelipatan 2
    if (panjang_text % 2 != 0) {
        panjang_text++;
    }

    for (int i = 0; i < panjang_text; i += 2) {
        int plain1 = input[i] - ASCII_MIN;
        int plain2 = input[i + 1] - ASCII_MIN;

        int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
        int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

        hasil_enkripsi << (char)enkripsi1 << (char)enkripsi2;
    }

    return hasil_enkripsi.str();
}


std::string enkripsi_text(const std::string &text) {
    const unsigned char *input = (const unsigned char *)text.c_str();
    int panjang_text = text.length();
    int key[2][2] = {{1,2},{3,1}};

    std::ostringstream hasil_enkripsi;

    // Menambahkan spasi jika panjang_teks bukan kelipatan 2
    if (panjang_text % 2 != 0)
    {
        panjang_text++;
    }

    for (int i = 0; i < panjang_text; i += 2)
    {
        int plain1 = input[i] - ASCII_MIN;
        int plain2 = input[i + 1] - ASCII_MIN;

        int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
        int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

        hasil_enkripsi << (char)enkripsi1 << (char)enkripsi2;
    }

    return hasil_enkripsi.str();
}







// typedef struct {
//     int integerData;
//     char charData;
//     char *stringData;
// } EncryptionData;

// void enkripsi_text(void *data, int data_type) {
//     int key[2][2] = {{1,2},{3,1}};
//     char *text;
//     int panjang_text;

//     switch (data_type) {
//         case 0: // Integer
//             text = (char*)&((EncryptionData*)data)->integerData;
//             panjang_text = sizeof(int);
//             break;
//         case 1: // Char
//             text = &((EncryptionData*)data)->charData;
//             panjang_text = 1;
//             break;
//         case 2: // String
//             text = ((EncryptionData*)data)->stringData;
//             panjang_text = strlen(text);

//             // Membuat salinan string dan menambahkan spasi jika perlu
//             if (panjang_text % 2 != 0) {
//                 char *new_text = malloc((panjang_text + 2) * sizeof(char));
//                 if (new_text == NULL) {
//                     printf("Memory allocation error\n");
//                     return;
//                 }
//                 strcpy(new_text, text);
//                 new_text[panjang_text] = ' ';
//                 new_text[panjang_text + 1] = '\0';
//                 text = new_text;
//                 panjang_text += 1; // Panjang teks termasuk spasi
//             }
//             break;
//         default:
//             printf("Unsupported data type\n");
//             return;
//     }

//     // Proses enkripsi
//     for (int i = 0; i < panjang_text; i += 2) {
//         int plain1 = text[i] - ASCII_MIN;
//         int plain2 = text[i + 1] - ASCII_MIN;

//         int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
//         int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

//         printf("%c%c", enkripsi1, enkripsi2);  
//     }
// }






















// void enkripsi_text(char *text)
// {
//     int panjang_text = strlen(text);
//     int key[2][2] = {{1,2},{3,1}};

//     //menambahkan spasi jika panjang_teks bukan kelipatan 2
//     if (panjang_text %2 != 0)
//     {
//         text[panjang_text] = ' ';
//         panjang_text++;
//         text[panjang_text] =  '\0';
//     }
    
//     int panjang_hasil = panjang_text * 2 + 1;

//     for (int i = 0; i < panjang_text; i += 2)
//     {
//         int plain1 = text[i] - ASCII_MIN;
//         int plain2 = text[i + 1] - ASCII_MIN;

//         int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
//         int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

//         printf("%c%c",enkripsi1,enkripsi2);
//     }
// }

//typedef struct {
    int integerData;
    char charData;
    char *stringData;
//} EncryptionData;

/*void enkripsi_text(const EncryptionData *data)
{
    const unsigned char *text = (const unsigned char *)data->stringData;
    int panjang_text = strlen(data->stringData); // Menggunakan panjang stringData
    int key[2][2] = {{1,2},{3,1}};

    //menambahkan spasi jika panjang_teks bukan kelipatan 2
    if (panjang_text %2 != 0)
    {
        panjang_text++;
    }
    
    int panjang_hasil = panjang_text * 2 + 1;

    for (int i = 0; i < panjang_text; i += 2)
    {
        int plain1 = text[i] - ASCII_MIN;
        int plain2 = text[i + 1] - ASCII_MIN;

        int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
        int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

        printf("%c%c",enkripsi1,enkripsi2);
    }*/
    

#endif /* HILLCIPHER_ENKRIPSI_H */