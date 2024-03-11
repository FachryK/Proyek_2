#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "231511084.h"
#include "hillcipher_enkripsi.hpp"

    Siswa siswa;

    void inputdata() 
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

        string nik = enkripsi_text(siswa.NIK);
        string kk = enkripsi_text(siswa.No_KK);
        string alamat = enkripsi_text(siswa.ALAMAT_RUMAH);

        ofstream outputFile("siswa.txt", ios::app);
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
            cout << "Input data siswa telah disimpan dalam siswa.txt\n";
            cout << "-----------------------------------------------\n";
        } 
        else 
        {
            cerr << "Filenya tidak bisa dibuka.\n";
        }
    }

    void outputdata()
    {

        ifstream inputFile("siswa.txt");
        string line;

        if (inputFile.is_open()) 
        {
            cout << "-----------------------------------------------\n";
            cout << "                 Data Siswa:\n";
            cout << "-----------------------------------------------\n";
            while (getline(inputFile, line)) 
            { 
                istringstream iss(line); 
                string field; 
                while (getline(iss, field, ',')) 
                {
                    cout << field << endl; 
                }
                cout << endl; 
            }
            inputFile.close();
        } 
        else 
        {
            cerr << "Filenya tidak bisa dibuka.\n";
        }
    }
