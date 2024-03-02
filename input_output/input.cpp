#include <iostream>
#include "data.h"

using namespace std;

int main() {
    Data data; // Variabel untuk menyimpan data

    // Meminta input dari pengguna
    cout << "Masukkan NIS: ";
    getline(cin, data.NIS);
    cout << "Masukkan NISN: ";
    getline(cin, data.NISN);
    cout << "Masukkan Nama: ";
    getline(cin, data.NAMA);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, data.JENIS_KELAMIN);
    cout << "Masukkan TTL: ";
    getline(cin, data.TTL);
    cout << "Masukkan NIK: ";
    getline(cin, data.NIK);
    cout << "Masukkan No. KK: ";
    getline(cin, data.NO_KK);
    cout << "Masukkan Agama: ";
    getline(cin, data.AGAMA);
    cout << "Masukkan Alamat Rumah: ";
    getline(cin, data.ALAMAT_RUMAH);
    cout << "Masukkan No. HP: ";
    getline(cin, data.NO_HP);
    cout << "Masukkan Alamat Email: ";
    getline(cin, data.ALAMAT_EMAIL);

    // Memanggil fungsi untuk menyimpan data ke dalam file
    saveDataToFile("data.txt", data);

    return 0;
}
