#include <iostream>
#include <fstream>
#include <string>

void SaveUserInfoToTxt(const std::string& NIS, const std::string& NISN, const std::string& NAMA, const std::string& JENIS_KELAMIN,
                       const std::string& TTL, const std::string& NIK, const std::string& NO_KK, const std::string& AGAMA,
                       const std::string& ALAMAT_RUMAH, const std::string& NO_HP, const std::string& ALAMAT_EMAIL, const std::string& filename) {
    std::ofstream file(filename);
 
    if (file.is_open()) {
        file << "NIS: " << NIS << "\n";
        file << "NISN: " << NISN << "\n";
        file << "NAMA: " << NAMA << "\n";
        file << "JENIS KELAMIN: " << JENIS_KELAMIN << "\n";
        file << "TTL: " << TTL << "\n";
        file << "NIK: " << NIK << "\n";
        file << "NO.KK: " << NO_KK << "\n";
        file << "AGAMA: " << AGAMA << "\n";
        file << "ALAMAT RUMAH: " << ALAMAT_RUMAH << "\n";
        file << "NO.HP: " << NO_HP << "\n";
        file << "ALAMAT EMAIL: " << ALAMAT_EMAIL << "\n";
 
        file.close();
        std::cout << "User information saved to " << filename << " successfully.\n";
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}