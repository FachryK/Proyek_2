#include "231511069.h"
#include <sstream>
#include <iostream>

#define ASCII_MIN 32
#define ASCII_MAX 126
#define RANGE_ASCII (ASCII_MAX - ASCII_MIN + 1)


std::string enkripsi_text(const std::string &text)
{
    std::string modifiedText = text;
    if (text.length() % 2 != 0)
    {
        modifiedText += ' '; // Menambahkan satu karakter ' ' jika panjang teks ganjil
    }
    const unsigned char *input = (const unsigned char *)modifiedText.c_str();
    int panjang_text = modifiedText.length();

    int key[2][2] = {{6,5},{3,4}};//kunci matriks 2x2

    std::ostringstream hasil_enkripsi;

    //proses enkripsi
    for (int i = 0; i < panjang_text; i += 2)
    {
        int plain1 = input[i] - ASCII_MIN;
        int plain2 = input[i + 1] - ASCII_MIN;

        int enkripsi1 = (key[0][0] * plain1 + key[0][1] * plain2) % RANGE_ASCII + ASCII_MIN;
        int enkripsi2 = (key[1][0] * plain1 + key[1][1] * plain2) % RANGE_ASCII + ASCII_MIN;

        hasil_enkripsi << (char)enkripsi1 << (char)enkripsi2; //menampung hasil enkripsi
    }

    return hasil_enkripsi.str(); //hasil enkripsi dikembalikan sebagai string
}

std::string dekripsi_text(const std::string &text)
{
    const unsigned char *input = (const unsigned char *)text.c_str();
    int panjang_text = text.length();
    int invkey[2][2] = {{11, 10}, {63, 64}}; //invers kunci 2x2
    std::ostringstream hasil_dekripsi;

    //proses dekripsi
    for (int i = 0; i < panjang_text; i += 2) 
    {
        int ciper1 = input[i] - ASCII_MIN;
        int ciper2 = input[i + 1] - ASCII_MIN;

        int dekripsi1 = (invkey[0][0] * ciper1 + invkey[0][1] * ciper2) % RANGE_ASCII + ASCII_MIN;
        int dekripsi2 = (invkey[1][0] * ciper1 + invkey[1][1] * ciper2) % RANGE_ASCII + ASCII_MIN;

        hasil_dekripsi << (char)dekripsi1 << (char)dekripsi2;
    }
    std::string hasil = hasil_dekripsi.str();

    // Hapus karakter ' ' terakhir jika ada
    if (hasil.length() > 0 && hasil[hasil.length() - 1] == ' ') 
    {
        hasil.erase(hasil.length() - 1);
    }
    return hasil;
}
