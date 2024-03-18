#include "231511096.h"
#include "../security/231511069.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string login() // Mendefinisikan fungsi login yang mengembalikan string
{
    int count = 0; // Mendeklarasikan variabel count dan menginisialisasikannya dengan nilai 0
    string userId, password, id, pass, tes;
    system("cls"); // Memanggil perintah sistem untuk membersihkan layar konsol
    cout << "\n\n\t----------Silahkan Masukkan Username dan Password Anda----------\n";
    cout << "\t Username : ";
    cin >> userId;
    cout << "\t Password : ";
    cin >> password;

    ifstream input("record.txt"); // Membuka file record.txt untuk dibaca

    if (input.is_open()) // Memeriksa apakah file berhasil dibuka
    {
        while (getline(input, id, ',') && getline(input, pass)) // Membaca data dari file baris per baris
        {
            string decryptedPass = dekripsi_text(pass); // Mendekripsi password yang dibaca dari file
            if (id == userId && decryptedPass == password) // Memeriksa apakah username dan password cocok
            {
                count = 1; // Mengubah nilai count menjadi 1
                system("cls");
                break; // Keluar dari loop
            }
        }
        input.close(); // Menutup file setelah selesai membacanya
    }

    if (count == 1) // Jika count sama dengan 1
    {
        string user;
        cout <<"\n"<< userId << "\n----------Login berhasil!----------\n\n";
        user = userId;
        return user;
    } 
    else // Jika count tidak sama dengan 1
    {
        cout << "\n----------Login eror! Cek Username dan Password yang anda masukkan----------\n\n";
        tes = " ";
        return tes;
    }
}

void registrasi() //Mendeskripsikan fungsi registrasi
{
    string ruserId, rpassword, encryptedpass;
    system("cls");
    cout << "\n\n\t----------Silahkan Buat Akun Anda----------\n";
    cout << "\t Username : ";
    cin >> ruserId;
    cout << "\t Password : ";
    cin >> rpassword;
    encryptedpass = enkripsi_text(rpassword); //Untuk mengenkripsi password sebelum menyimpannya

    ifstream checkFile("record.txt");
    string id, line;
    bool usernameExists = false;

    if (checkFile.is_open()) {
        while (getline(checkFile, line)) 
        {
            stringstream ss(line); // Membuat stringstream dari baris yang dibaca
            string storedUsername; // Mendeklarasikan variabel bertipe string
            getline(ss, storedUsername, ','); // Mengambil username dari token pertama

            // Membandingkan username dari file dengan username yang ingin dicek
            if (storedUsername == ruserId) 
            {
                usernameExists = true;  // Mengubah nilai usernameExists menjadi true
                checkFile.close();
                 // Username sudah ada dalam file
            }
        }
        checkFile.close();
    }
    // Jika username sudah ada, tampilkan pesan kesalahan
    if (usernameExists) 
    {
        cout << "\n\t\t ----------Username tidak bisa digunakan. Registrasi gagal----------\n\n";
    } 
    else 
    {
        // Jika username belum ada, lakukan registrasi
        ofstream f1("record.txt", ios::app); // Membuka file record.txt untuk ditambahkan data
        f1 << ruserId << ',' << encryptedpass << endl; // Menulis username dan password yang terenkripsi ke dalam file
        f1.close(); // Tutup file setelah selesai menulis
        ofstream outputFile(ruserId + ".txt", std::ios::app); // Bikin file sesuai dengan nama yang di input
        cout << "\n\t\t ----------Registrasi berhasil----------\n\n";
    }
}

void lupaPassword() //Mendeskripsikan fungsi lupaPassword
{
    int option;
    system("cls");
    cout << "\t\t\t Apakah anda lupa password? Jangan khawatir \n";
    cout << "Ketik 1 untuk mencari dengan username" << endl;
    cout << "Ketik 2 untuk keluar " << endl;
    cout << "\t Pilihan anda : ";
    cin >> option;

    switch (option) // Memeriksa nilai option
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
                decryptedPass = dekripsi_text(encryptedPass); // Mendekripsi password 
                if (sId == suserId) 
                {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1) 
            {
                cout << "\t\n----------Akun anda ditemukan!----------\n";
                cout << "\tPassword akun anda :" << decryptedPass << endl;
            } 
            else 
            {
                cout << "\t\n----------Maaf akun anda tidak ditemukan----------\n\n";
            }
            break;
        }      
        case 2:
            system ("cls");
            break;

        default:
            cout << "\t----------Pilihan tidak sesuai, silahkan klik enter untuk coba lagi----------\n\n";
            cin.ignore();
            cin.get();
            system ("cls");
            return lupaPassword();
    }
}