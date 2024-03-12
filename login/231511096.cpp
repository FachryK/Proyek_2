#include <iostream>
#include <fstream>
#include <sstream>
#include "231511096.h"

void login()
{
    system("cls");

    std::cout << "============================================================" << std::endl;
    std::cout << "|                   SELAMAT DATANG DI                      |" << std::endl;
    std::cout << "|                APLIKASI SAVE DATA SISWA                  |" << std::endl;
    std::cout << "============================================================" << std::endl;
}

bool login(const std::string& username, const std::string& password)
{
    std::ifstream readFile("data-pengguna.txt");

    if (readFile.is_open()) {
        std::string data, cekUsername, cekPassword;
        bool cariUsername = false;

        while (getline(readFile, data) && !cariUsername) {
            std::istringstream iss(data);
            getline(iss, cekUsername, ',');
            getline(iss, cekPassword, ',');

            if (username == cekUsername) {
                cariUsername = true;
                if (password == cekPassword) {
                    login();
                    std::cout << "=============================================================" << std::endl;
                    std::cout << "|                      LOGIN BERHASIL!                      |" << std::endl;
        			std::cout << "=============================================================" << std::endl;
                    return true;
                } else {
                    login();
                    std::cout << "============================================================" << std::endl;
                    std::cout << "|                      PASSWORD SALAH!                     |" << std::endl;
        		    std::cout << "============================================================" << std::endl;	
                    return false;
                }
            }
        }

        if (!cariUsername) {
            login();
            std::cout << "============================================================" << std::endl;
            std::cout << "|                  USERNAME TIDAK DITEMUKAN!               |" << std::endl;
        	std::cout << "============================================================" << std::endl;
            return false;
        }

        readFile.close();
    } else {
        std::cout << "Gagal mengakses data pengguna";
    }

    return false;
}

void registrasi()
{
    login();

    std::string username, password;

    std::cout << "Registrasi Akun Baru" << std::endl;
    std::cout << "Username : ";
    std::cin >> username;
    std::cout << "Password : ";
    std::cin >> password;

    std::ofstream writeFile("data-pengguna.txt", std::ios::app);

    if (writeFile.is_open()) {
        writeFile << username << "," << password << std::endl;
        login();
        std::cout << "=============================================================" << std::endl;
        std::cout << "|                   REGISTRASI BERHASIL!                    |" << std::endl;
        std::cout << "=============================================================" << std::endl;
        writeFile.close();
    } else {
        std::cout << "Gagal mengakses data pengguna";
    }
}

void gantiSandi()
{
    login();

    std::string username, password;

    std::cout << "Ganti Sandi" << std::endl;
    std::cout << "Username : ";
    std::cin >> username;
    std::cout << "Password Lama : ";
    std::cin >> password;

    // implementasi ganti sandi disini sesuai kebutuhan
    // ...
}

void pilihan()
{
    login();

    int choice;

    std::cout << "Pilihan:" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Registrasi" << std::endl;
    std::cout << "3. Ganti Sandi" << std::endl;
    std::cout << "Pilih opsi: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::string username, password;
        login();
        std::cout << "Login" << std::endl;
        std::cout << "Username : ";
        std::cin >> username;
        std::cout << "Password : ";
        std::cin >> password;
        login(username, password);
        break;
    }
    case 2:
        registrasi();
        break;
    case 3:
        gantiSandi();
        break;
    default:
        login();
        std::cout << "Pilihan tidak valid." << std::endl;
        break;
    }
}

int main()
{
    pilihan();
    return 0;
}
