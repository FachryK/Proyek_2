#include "231511096.h"
#include <cstdlib>

void LoginManager::saveToFile(const std::unordered_map<std::string, std::string>& accounts) {
    std::ofstream file("accounts.txt");
    if (file.is_open()) {
        for (const auto& account : accounts) {
            file << account.first << " " << account.second << std::endl;
        }
        file.close();
    }
}

std::unordered_map<std::string, std::string> LoginManager::readFromFile() {
    std::unordered_map<std::string, std::string> accounts;
    std::ifstream file("accounts.txt");
    if (file.is_open()) {
        std::string username, password;
        while (file >> username >> password) {
            accounts[username] = password;
        }
        file.close();
    }
    return accounts;
}

bool LoginManager::login(const std::unordered_map<std::string, std::string>& accounts, const std::string& username, const std::string& password) {
    auto it = accounts.find(username);
    if (it != accounts.end() && it->second == password) {
        return true; // Login berhasil
    }
    return false; // Login gagal
}

void LoginManager::createAccount(std::unordered_map<std::string, std::string>& accounts) {
    std::string username, password;

    // Meminta pengguna memasukkan username dan password baru
    std::cout << "Masukkan username baru: ";
    std::cin >> username;

    // Memeriksa apakah username sudah ada
    if (accounts.find(username) != accounts.end()) {
        std::cout << "Username sudah digunakan. Buat akun dengan username yang lain.\n";
        return;
    }

    std::cout << "Masukkan password baru: ";
    std::cin >> password;

    // Menambahkan akun baru ke dalam unordered_map
    accounts[username] = password;
    std::cout << "Akun berhasil dibuat!\n";

    // Menyimpan ke dalam file
    saveToFile(accounts);
}

void LoginManager::changePassword(std::unordered_map<std::string, std::string>& accounts, const std::string& username) {
    std::string newPassword;

    // Meminta pengguna memasukkan password baru
    std::cout << "Masukkan password baru: ";
    std::cin >> newPassword;

    // Mengganti password
    accounts[username] = newPassword;
    std::cout << "Password berhasil diganti!\n";

    // Menyimpan ke dalam file
    saveToFile(accounts);
}
