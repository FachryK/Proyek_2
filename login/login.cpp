#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cstdlib> // Untuk menggunakan fungsi exit()

using namespace std;

// Fungsi untuk menyimpan username dan password ke dalam file
void saveToFile(const unordered_map<string, string>& accounts) {
    ofstream file("accounts.txt");
    for (const auto& account : accounts) {
        file << account.first << " " << account.second << endl;
    }
    file.close();
}

// Fungsi untuk membaca username dan password dari file
unordered_map<string, string> readFromFile() {
    unordered_map<string, string> accounts;
    ifstream file("accounts.txt");
    if (file.is_open()) {
        string username, password;
        while (file >> username >> password) {
            accounts[username] = password;
        }
        file.close();
    }
    return accounts;
}

// Fungsi untuk melakukan login
bool login(const unordered_map<string, string>& accounts, const string& username, const string& password) {
    auto it = accounts.find(username);
    if (it != accounts.end() && it->second == password) {
        return true; // Login berhasil
    }
    return false; // Login gagal
}

// Fungsi untuk membuat akun baru
void createAccount(unordered_map<string, string>& accounts) {
    string username, password;

    // Meminta pengguna memasukkan username dan password baru
    cout << "Masukkan username baru: ";
    cin >> username;

    // Memeriksa apakah username sudah ada
    if (accounts.find(username) != accounts.end()) {
        cout << "Username sudah digunakan. Buat akun dengan username yang lain.\n";
        return;
    }

    cout << "Masukkan password baru: ";
    cin >> password;

    // Menambahkan akun baru ke dalam unordered_map
    accounts[username] = password;
    cout << "Akun berhasil dibuat!\n";

    // Menyimpan ke dalam file
    saveToFile(accounts);
}

// Fungsi untuk mengganti password
void changePassword(unordered_map<string, string>& accounts, const string& username) {
    string newPassword;

    // Meminta pengguna memasukkan password baru
    cout << "Masukkan password baru: ";
    cin >> newPassword;

    // Mengganti password
    accounts[username] = newPassword;
    cout << "Password berhasil diganti!\n";

    // Menyimpan ke dalam file
    saveToFile(accounts);
}

// Fungsi utama
int main() {
    int choice;
    string username, password;

    // Membaca username dan password dari file
    unordered_map<string, string> accounts = readFromFile();

    // Menu
    cout << "Selamat datang!\n";
    cout << "1. Login\n";
    cout << "2. Buat akun baru\n";
    cout << "3. Ganti password\n";
    cout << "4. Keluar\n";
    cout << "Pilih: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Meminta pengguna memasukkan username dan password untuk login
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            // Memeriksa login
            if (login(accounts, username, password)) {
                cout << "Login berhasil!\n";
            } else {
                cout << "Login gagal. Username atau password salah.\n";
            }
            break;
        case 2:
            // Membuat akun baru
            createAccount(accounts);
            break;
        case 3:
            // Mengganti password
            cout << "Masukkan username: ";
            cin >> username;
            if (accounts.find(username) != accounts.end()) {
                changePassword(accounts, username);
            } else {
                cout << "Username tidak ditemukan.\n";
            }
            break;
        case 4:
            // Keluar dari program
            cout << "Terima kasih! Sampai jumpa.\n";
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    return 0;
}
