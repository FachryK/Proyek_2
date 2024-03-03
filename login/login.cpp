#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fungsi untuk membuat akun baru
void createAccount() {
    string username, password;

    // Meminta pengguna memasukkan username dan password
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Menyimpan username dan password ke dalam file
    ofstream file("accounts.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Akun berhasil dibuat!\n";
}

// Fungsi untuk login
void login() {
    string username, password, u, p;

    // Meminta pengguna memasukkan username dan password
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    // Membuka file dan mencocokkan username dan password
    ifstream file("accounts.txt");
    bool found = false;
    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    // Menampilkan pesan sesuai hasil pencarian
    if (found) {
        cout << "Login berhasil!\n";
    } else {
        cout << "Username atau password salah.\n";
    }
}

int main() {
    int choice;

    do {
        // Menampilkan menu
        cout << "Menu:\n";
        cout << "1. Buat akun baru\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 3);

    return 0;
}
