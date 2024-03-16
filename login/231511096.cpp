#include "231511096.h"
#include "../security/231511069.cpp"
#include <iostream>
#include <fstream>

using namespace std;

void login();
void registrasi();
void lupaPassword();
void mainMenu() 
{
    int c;
    bool loggedIn = false; // Variable untuk menandai apakah pengguna telah login atau belum
    
    // Tampilkan pesan selamat datang hanya jika pengguna belum login
    if (!loggedIn) 
    {
        cout << "\t============================================================\n";
        cout << "\t|                   SELAMAT DATANG DI                      |\n";
        cout << "\t|                APLIKASI SAVE DATA SISWA                  |\n";
        cout << "\t============================================================\n";
    }

    cout << "\t___________________________ MENU ___________________________\n";
    cout << "\t Pilihan:" << endl;
    cout << "\t 1. Login" << endl;
    cout << "\t 2. Registrasi" << endl;
    cout << "\t 3. Lupa Password" << endl;
    cout << "\t Pilih opsi: ";
    cin >> c;
    cout << endl;

    switch (c) 
    {
        case 1:
            login();
            loggedIn = true; // Setelah login berhasil, tandai pengguna sebagai sudah login
            break;

        case 2:
            registrasi();
            break;

        case 3:
            lupaPassword();
            break;

        default:
            system("cls");
            cout << "\t ----------Silakan pilih dari opsi yang diberikan di atas----------\n" << endl;
            mainMenu();
    }
}

int main() 
{
    mainMenu();
    return 0;
}

void login() 
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t Username : ";
    cin >> userId;
    cout << "\t Password : ";
    cin >> password;

    ifstream input("record.txt");

    if (input.is_open()) 
    {
        while (getline(input, id, ',') && getline(input, pass)) 
        {
            string decryptedPass = dekripsi_text(pass);
            if (id == userId && decryptedPass == password) 
            {
                count = 1;
                system("cls");
                break;
            }
        }
        input.close();
    }

    if (count == 1) 
    {
        cout << userId << "\n----------Login berhasil!----------\n";
    } 
    else 
    {
        cout << "----------Login eror! Cek Username dan Password yang anda masukkan----------\n";
    }
}

void registrasi() 
{
    string ruserId, rpassword, encryptedpass;
    system("cls");
    cout << "\t Username : ";
    cin >> ruserId;
    cout << "\t Password : ";
    cin >> rpassword;
    encryptedpass = enkripsi_text(rpassword); // Anda perlu mengenkripsi password sebelum menyimpannya

    ifstream checkFile("record.txt");
    string id;
    bool usernameExists = false;

    // Memeriksa apakah username sudah ada dalam file
    while (getline(checkFile, id, ',')) 
    {
        if (id == ruserId) 
        {
            usernameExists = true;
            break;
        }
    }
    checkFile.close();

    // Jika username sudah ada, tampilkan pesan kesalahan
    if (usernameExists) 
    {
        cout << "\n\t\t ----------Username sudah digunakan. Registrasi gagal----------\n";
    } 
    else 
    {
        // Jika username belum ada, lakukan registrasi
        ofstream f1("record.txt", ios::app);
        f1 << ruserId << ',' << encryptedpass << endl;
        f1.close(); // Tutup file setelah selesai menulis
        system("cls");
        cout << "\n\t\t ----------Registrasi berhasil----------\n";
    }
}

void lupaPassword() 
{
    int option;
    system("cls");
    cout << "\t\t\t Apakah anda lupa password? Jangan khawatir \n";
    cout << "Ketik 1 untuk mencari dengan username" << endl;
    cout << "Ketik 2 untuk kembali menu utama " << endl;
    cout << "\t Pilihan anda : ";
    cin >> option;
    switch (option) 
    {
        case 1: 
        {
            int count = 0;
            string suserId, sId, encryptedPass;
            cout << "\t Masukkan Username anda : ";
            cin >> suserId;
            
            string decryptedPass; // Deklarasi variabel decryptedPass di luar loop
            
            ifstream f2("record.txt");
            while (getline(f2, sId, ',') && getline(f2, encryptedPass)) 
            {
                decryptedPass = dekripsi_text(encryptedPass); // Dekripsi password di sini
                if (sId == suserId) 
                {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1) 
            {
                cout << "\n\t----------Akun anda ditemukan!----------\n";
                cout << "\tPassword akun anda :" << decryptedPass << endl;
            } 
            else 
            {
                cout << "\n\t ----------Maaf akun anda tidak ditemukan---------- \n";
            }
            break;
        }

        case 2:
            break;

        default:
            cout << "\t----------Pilihan tidak sesuai, silahkan coba lagi----------";
            lupaPassword();
    }
}