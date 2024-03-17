#include "231511096.h"
#include "../security/231511069.h"
#include <iostream>
#include <fstream>

using namespace std;

string login() 
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
        string user;
        cout << userId << "\n\n----------Login berhasil!----------\n\n";
        user = userId;
        return user;
    } 
    else 
    {
        cout << "----------Login eror! Cek Username dan Password yang anda masukkan----------\n";
        return (" ");
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
        ofstream outputFile( ruserId + ".txt", std::ios::app); // Bikin file sesuai dengan nama yang di input
        cout << "\n\t\t ----------Registrasi berhasil----------\n";
    }
}

void lupaPassword() 
{
    int option;
    system("cls");
    cout << "\t\t\t Apakah anda lupa password? Jangan khawatir \n";
    cout << "Ketik 1 untuk mencari dengan username" << endl;
    cout << "Ketik 2 untuk keluar " << endl;
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