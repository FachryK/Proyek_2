#include <iostream>
#include <fstream>
#include <string>
 
namespace UserInput {

    void inputdata() {
        std::string NAMA, JENIS_KELAMIN, TTL, AGAMA, ALAMAT_RUMAH, Email;
        int NIS, NISN, NIK, No_KK, No_HP;
 
        std::cout << "Masukkan NIS: ";
        std::cin >> NIS;
        std::cout << "Masukkan NISN: ";
        std::cin >> NISN;
        std::cout << "Masukkan Nama: ";
        std::cin.ignore(); 
        std::getline(std::cin, NAMA);
        std::cout << "Masukkan Jenis Kelamin: ";
        std::cin >> JENIS_KELAMIN;
        std::cout << "Masukkan TTL: ";
        std::cin.ignore();
        std::getline(std::cin, TTL);
        std::cout << "Masukkan NIK: ";
        std::cin >> NIK;
        std::cout << "Masukkan No.KK: ";
        std::cin >> No_KK;
        std::cout << "Masukkan Agama: ";
        std::cin >> AGAMA;
        std::cout << "Masukkan Alamat Rumah: ";
        std::cin.ignore();
        std::getline(std::cin, ALAMAT_RUMAH);
        std::cout << "Masukkan No.HP: ";
        std::cin >> No_HP;
        std::cout << "Masukkan Email: ";
        std::cin >> Email;

        std::ofstream outputFile("siswa.txt", std::ios::app);
        if (outputFile.is_open()) {
            outputFile << "NIS: " << NIS << "\n";
            outputFile << "NISN: " << NISN << "\n";
            outputFile << "Nama: " << NAMA << "\n";
            outputFile << "Jenis Kelamin: " << JENIS_KELAMIN << "\n";
            outputFile << "TTL: " << TTL << "\n";
            outputFile << "NIK: " << NIK << "\n";
            outputFile << "No.KK: " << No_KK << "\n";
            outputFile << "Agama: " << AGAMA << "\n";
            outputFile << "Alamat Rumah: " << ALAMAT_RUMAH << "\n";
            outputFile << "No.HP: " << No_HP << "\n";
            outputFile << "Email: " << Email << "\n";
            outputFile.close();
            std::cout << "Input data siswa telah disimpan dalam siswa.txt\n";
        } else {
            std::cerr << "Filenya tidak bisa dibuka.\n";
        }
    }
}