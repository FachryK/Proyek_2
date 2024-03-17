#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // untuk transform()

// Struktur data untuk menyimpan informasi siswa
struct Siswa
{
    std::string NAMA;
    // Tambahkan atribut lain jika diperlukan
};

// Fungsi untuk membaca data siswa dari file teks
std::vector<Siswa> readSiswaFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<Siswa> siswaList;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            // Menghapus karakter yang tidak diinginkan (jika ada)
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); // Menghapus karakter '\r' jika ada
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); // Menghapus karakter '\n' jika ada

            // Transformasi nama menjadi lowercase (menghindari masalah perbedaan huruf besar/kecil)
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);

            Siswa siswa;
            siswa.NAMA = line;
            siswaList.push_back(siswa);
        }
        file.close();
    }

    return siswaList;
}

// Fungsi pencarian siswa berdasarkan nama
Siswa searchSiswaByName(const std::vector<Siswa> &siswaList, const std::string &name)
{
    std::string lowercaseName = name;
    // Mengubah input nama menjadi lowercase untuk membandingkan dengan nama dalam file
    std::transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

    for (const auto &siswa : siswaList)
    {
        // Mengubah nama dalam file menjadi lowercase dan membandingkannya dengan nama yang diinputkan
        if (siswa.NAMA == lowercaseName)
        {
            return siswa;
        }
    }
    // Jika siswa tidak ditemukan, kembalikan siswa dengan nama kosong
    return Siswa{"", /* tambahkan atribut lain jika diperlukan */};
}

int main()
{
    // Baca data siswa dari file teks
    std::vector<Siswa> siswaList = readSiswaFromFile("siswa.txt");

    std::string searchName;
    std::cout << "Masukkan Nama yang dicari : ";
    std::getline(std::cin, searchName); // Menggunakan std::getline untuk membaca spasi pada input

    // Cari siswa berdasarkan nama
    Siswa result = searchSiswaByName(siswaList, searchName);

    if (result.NAMA != "")
    {
        std::cout << "Mahasiswa dengan nama " << result.NAMA << " ditemukan." << std::endl;
    }
    else
    {
        std::cout << "Mahasiswa dengan nama " << searchName << " tidak ditemukan." << std::endl;
    }

    return 0;
}
