#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "231511084.h"
#include "../security/231511069.h"
#include "../login/231511096.h"
#include "../search_filter/231511075.h"

    void inputdata(const string &user) 
    {
        Siswa siswa;

        cout << "Masukkan NIS: ";
        cin >> siswa.NIS;
        cin.ignore(); // Membersihkan karakter newline dari buffer masukan
        cout << "Masukkan NISN: ";
        getline(cin, siswa.NISN);
        cout << "Masukkan Nama: ";
        getline(cin, siswa.NAMA);
        cout << "Masukkan Jenis Kelamin: ";
        getline(cin, siswa.JENIS_KELAMIN);
        cout << "Masukkan TTL: ";
        getline(cin, siswa.TTL);
        cout << "Masukkan NIK: ";
        getline(cin, siswa.NIK);
        cout << "Masukkan No.KK: ";
        getline(cin, siswa.No_KK);
        cout << "Masukkan Agama: ";
        getline(cin, siswa.AGAMA);
        cout << "Masukkan Alamat Rumah: ";
        getline(cin, siswa.ALAMAT_RUMAH);
        cout << "Masukkan No.HP: ";
        getline(cin, siswa.No_HP);
        cout << "Masukkan Email: ";
        getline(cin, siswa.Email);

        string nik_enkripsi = enkripsi_text(siswa.NIK);
        string kk_enkripsi = enkripsi_text(siswa.No_KK);
        string alamat_enkripsi = enkripsi_text(siswa.ALAMAT_RUMAH);

        // Menyimpan data ke dalam file
        ofstream outputFile(user + ".txt", ios::app);
        if (outputFile.is_open()) 
        {
            outputFile << siswa.NIS << ",";
            outputFile << siswa.NISN << ",";
            outputFile << siswa.NAMA << ",";
            outputFile << siswa.JENIS_KELAMIN << ",";
            outputFile << siswa.TTL << ",";
            outputFile << nik_enkripsi << ",";
            outputFile << kk_enkripsi << ",";
            outputFile << siswa.AGAMA << ",";
            outputFile << alamat_enkripsi << ",";
            outputFile << siswa.No_HP << ",";
            outputFile << siswa.Email << endl;

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
        Siswa siswa;

        if (inputFile.is_open()) 
        {
            cout << "\t-----------------------------------------------\n";
            cout << "\t                 Data Siswa:\n";
            cout << "\t-----------------------------------------------\n";

            string line, nik_dekripsi, kk_dekripsi, alamat_dekripsi;
            int count = 0; // Variabel untuk menghitung jumlah baris

            // Menghitung jumlah baris dalam file
            while (getline(inputFile, line)) 
            {
                count++;
            }

            // Mengembalikan posisi file ke awal
            inputFile.clear();
            inputFile.seekg(0, ios::beg);

            if (count == 0)
            {
                cout << "\t-----------------------------------------------\n";
                cout << "\t          Tidak Ada Data yang Diinput\n";
                cout << "\t-----------------------------------------------\n";
            }
            

            // Loop untuk setiap baris dalam file
            for (int i = 1; i <= count; i++) 
            {
                getline(inputFile, line);
                stringstream ss(line);

                getline(ss, siswa.NIS, ',');
                getline(ss, siswa.NISN, ',');
                getline(ss, siswa.NAMA, ',');
                getline(ss, siswa.JENIS_KELAMIN, ',');
                getline(ss, siswa.TTL, ',');
                getline(ss, siswa.NIK, ',');
                getline(ss, siswa.No_KK, ',');
                getline(ss, siswa.AGAMA, ',');
                getline(ss, siswa.ALAMAT_RUMAH, ',');
                getline(ss, siswa.No_HP, ',');
                getline(ss, siswa.Email, ',');

                nik_dekripsi = dekripsi_text(siswa.NIK);
                kk_dekripsi = dekripsi_text(siswa.No_KK);
                alamat_dekripsi = dekripsi_text(siswa.ALAMAT_RUMAH);

                // Menampilkan data siswa dengan nomor baris
                cout << "\t-----------------------------------------------\n";
                cout << "\t                 Siswa ke " << i << endl;
                cout << "\t-----------------------------------------------\n";
                cout << "NIS: " << siswa.NIS << endl;
                cout << "NISN: " << siswa.NISN << endl;
                cout << "Nama: " << siswa.NAMA << endl;
                cout << "Jenis Kelamin: " << siswa.JENIS_KELAMIN << endl;
                cout << "TTL: " << siswa.TTL << endl;
                cout << "NIK: " << nik_dekripsi << endl;
                cout << "No.KK: " << kk_dekripsi << endl;
                cout << "Agama: " << siswa.AGAMA << endl;
                cout << "Alamat Rumah: " << alamat_dekripsi << endl;
                cout << "No.HP: " << siswa.No_HP << endl;
                cout << "Email: " << siswa.Email << endl;
                cout << endl;
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
        string nama;
        do
        {
            cout << "\t(1) Memasukkan Data Siswa \n";
            cout << "\t(2) Menampilkan Data Siswa \n";
            cout << "\t(3) Pencarian Berdasarkan Nama \n";
            cout << "\t(4) Keluar \n";
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
            case 3:
                cout << "Masukkan Nama Siswa yang ingin dicari: ";
                cin.ignore();
                getline(cin,nama);
                searchByName(user,nama);
                break;
            case 4:
                system("cls");
                break;
            default:
                cout << "\t----------------------\n";
                cout << "\t Pilihan tidak valid\n";
                cout << "\t----------------------\n";
                break;
            }
        } while (choice != 4);
        
    }
