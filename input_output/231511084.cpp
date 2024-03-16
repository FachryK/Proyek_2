#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "231511084.h"
#include "../security/231511069.h"
#include "../login/231511096.h"

    Siswa siswa;

    void inputdata(const string &user) 
    {
        cout << "Masukkan NIS: ";
        cin >> siswa.NIS;
        cout << "Masukkan NISN: ";
        cin >> siswa.NISN;
        cout << "Masukkan Nama: ";
        cin.ignore(); 
        getline(cin, siswa.NAMA);
        cout << "Masukkan Jenis Kelamin: ";
        cin >> siswa.JENIS_KELAMIN;
        cout << "Masukkan TTL: ";
        cin.ignore();
        getline(cin, siswa.TTL);
        cout << "Masukkan NIK: ";
        cin >> siswa.NIK;
        cout << "Masukkan No.KK: ";
        cin >> siswa.No_KK;
        cout << "Masukkan Agama: ";
        cin >> siswa.AGAMA;
        cout << "Masukkan Alamat Rumah: ";
        cin.ignore();
        getline(cin, siswa.ALAMAT_RUMAH);
        cout << "Masukkan No.HP: ";
        cin >> siswa.No_HP;
        cout << "Masukkan Email: ";
        cin >> siswa.Email;

        string nik = enkripsi_int(siswa.NIK);
        string kk = enkripsi_int(siswa.No_KK);
        string alamat = enkripsi_text(siswa.ALAMAT_RUMAH);

        ofstream outputFile(user + ".txt", ios::app);
        if (outputFile.is_open()) 
        {
            outputFile << "NIS: " << siswa.NIS << ", ";
            outputFile << "NISN: " << siswa.NISN << ", ";
            outputFile << "Nama: " << siswa.NAMA << ", ";
            outputFile << "Jenis Kelamin: " << siswa.JENIS_KELAMIN << ", ";
            outputFile << "TTL: " << siswa.TTL << ", ";
            outputFile << "NIK: " << nik << ", ";
            outputFile << "No.KK: " << kk << ", ";
            outputFile << "Agama: " << siswa.AGAMA << ", ";
            outputFile << "Alamat Rumah: " << alamat << ", ";
            outputFile << "No.HP: " << siswa.No_HP << ", ";
            outputFile << "Email: " << siswa.Email << endl;
            outputFile.close();
            cout << "-----------------------------------------------\n";
            cout << "Input data siswa telah disimpan dalam " << user << ".txt\n";
            cout << "-----------------------------------------------\n";
        } 
        else 
        {
            cerr << "Filenya tidak bisa dibuka.\n";
        }
    }

    void outputdata(const string &user)
{
    ifstream inputFile(user + ".txt");
    string line;

    if (inputFile.is_open()) 
    {
        cout << "-----------------------------------------------\n";
        cout << "                 Data Siswa:\n";
        cout << "-----------------------------------------------\n";
        
        // Membaca dan mencetak isi file baris demi baris
        while (getline(inputFile, line)) 
        {
            cout << line << endl;
        }
        
        inputFile.close();
    } 
    else 
    {
        cerr << "Filenya tidak bisa dibuka.\n";
    }
}

    void pilihan(const string &user)
    {
        int choice;
        do
        {
            cout << "\t(1) Memasukkan Data Siswa \n";
            cout << "\t(2) Menampilkan Data Siswa \n";
            cout << "\t(0) Keluar \n";
            cout << "\tOpsi      : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                inputdata(user);
                break;
            case 2:
                outputdata(user);
                break;
            case 0:
                system("cls");
                break;
            default:
                cout << "\tPilihan tidak valid";
                break;
            }
        } while (choice != 0);
        
    }
