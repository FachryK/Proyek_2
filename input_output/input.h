#include <iostream>
#include <fstream>
#include <string>

struct Siswa{
    std::string NAMA;
    std::string JENIS_KELAMIN;
    std::string TTL;
    std::string AGAMA;
    std::string ALAMAT_RUMAH;
    std::string Email;
    int NIS;
    int NISN;
    int NIK;
    int No_KK;
    int No_HP;
};
 
namespace UserInput {

    void inputdata() {

        Siswa siswa;
 
        std::cout << "Masukkan NIS: ";
        std::cin >> siswa.NIS;
        std::cout << "Masukkan NISN: ";
        std::cin >> siswa.NISN;
        std::cout << "Masukkan Nama: ";
        std::cin.ignore(); 
        std::getline(std::cin, siswa.NAMA);
        std::cout << "Masukkan Jenis Kelamin: ";
        std::cin >> siswa.JENIS_KELAMIN;
        std::cout << "Masukkan TTL: ";
        std::cin.ignore();
        std::getline(std::cin, siswa.TTL);
        std::cout << "Masukkan NIK: ";
        std::cin >> siswa.NIK;
        std::cout << "Masukkan No.KK: ";
        std::cin >> siswa.No_KK;
        std::cout << "Masukkan Agama: ";
        std::cin >> siswa.AGAMA;
        std::cout << "Masukkan Alamat Rumah: ";
        std::cin.ignore();
        std::getline(std::cin, siswa.ALAMAT_RUMAH);
        std::cout << "Masukkan No.HP: ";
        std::cin >> siswa.No_HP;
        std::cout << "Masukkan Email: ";
        std::cin >> siswa.Email;

        std::ofstream outputFile("siswa.txt", std::ios::app);
        if (outputFile.is_open()) {
            outputFile << "NIS: " << siswa.NIS << "\n";
            outputFile << "NISN: " << siswa.NISN << "\n";
            outputFile << "Nama: " << siswa.NAMA << "\n";
            outputFile << "Jenis Kelamin: " << siswa.JENIS_KELAMIN << "\n";
            outputFile << "TTL: " << siswa.TTL << "\n";
            outputFile << "NIK: " << siswa.NIK << "\n";
            outputFile << "No.KK: " << siswa.No_KK << "\n";
            outputFile << "Agama: " << siswa.AGAMA << "\n";
            outputFile << "Alamat Rumah: " << siswa.ALAMAT_RUMAH << "\n";
            outputFile << "No.HP: " << siswa.No_HP << "\n";
            outputFile << "Email: " << siswa.Email << "\n";
            outputFile.close();
            std::cout << "Input data siswa telah disimpan dalam siswa.txt\n";
        } else {
            std::cerr << "Filenya tidak bisa dibuka.\n";
        }
    }
}