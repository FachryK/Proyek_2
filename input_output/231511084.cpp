#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "231511084.h"

    Siswa siswa;

    void inputdata() 
    {
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
        if (outputFile.is_open()) 
        {
            outputFile << "NIS: " << siswa.NIS << ", ";
            outputFile << "NISN: " << siswa.NISN << ", ";
            outputFile << "Nama: " << siswa.NAMA << ", ";
            outputFile << "Jenis Kelamin: " << siswa.JENIS_KELAMIN << ", ";
            outputFile << "TTL: " << siswa.TTL << ", ";
            outputFile << "NIK: " << siswa.NIK << ", ";
            outputFile << "No.KK: " << siswa.No_KK << ", ";
            outputFile << "Agama: " << siswa.AGAMA << ", ";
            outputFile << "Alamat Rumah: " << siswa.ALAMAT_RUMAH << ", ";
            outputFile << "No.HP: " << siswa.No_HP << ", ";
            outputFile << "Email: " << siswa.Email << std::endl;
            outputFile.close();
            std::cout << "-----------------------------------------------\n";
            std::cout << "Input data siswa telah disimpan dalam siswa.txt\n";
            std::cout << "-----------------------------------------------\n";
        } 
        else 
        {
            std::cerr << "Filenya tidak bisa dibuka.\n";
        }
    }

    void outputdata()
    {

        std::ifstream inputFile("siswa.txt");
        std::string line;

        if (inputFile.is_open()) 
        {
            std::cout << "-----------------------------------------------\n";
            std::cout << "                 Data Siswa:\n";
            std::cout << "-----------------------------------------------\n";
            while (std::getline(inputFile, line)) 
            { 
                std::istringstream iss(line); 
                std::string field; 
                while (std::getline(iss, field, ',')) 
                {
                    std::cout << field << std::endl; 
                }
                std::cout << std::endl; 
            }
            inputFile.close();
        } 
        else 
        {
            std::cerr << "Filenya tidak bisa dibuka.\n";
        }
    }
