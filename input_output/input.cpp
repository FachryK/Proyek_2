#include <iostream>
#include <fstream>
#include <string>
#include "input.h"

int main() {
    std::string NIS = "12345";
    std::string NISN = "67890";
    std::string NAMA = "John Doe";
    std::string JENIS_KELAMIN = "Male";
    std::string TTL = "City, DD/MM/YYYY";
    std::string NIK = "1234567890";
    std::string NO_KK = "0987654321";
    std::string AGAMA = "Islam";
    std::string ALAMAT_RUMAH = "123 Street, City";
    std::string NO_HP = "123456789";
    std::string ALAMAT_EMAIL = "john.doe@example.com";
    std::string filename = "user_info.txt";
 
    SaveUserInfoToTxt(NIS, NISN, NAMA, JENIS_KELAMIN, TTL, NIK, NO_KK, AGAMA, ALAMAT_RUMAH, NO_HP, ALAMAT_EMAIL, filename);
 
    return 0;
}