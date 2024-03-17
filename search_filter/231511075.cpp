#include "231511075.h" // Sertakan file header yang diperlukan
#include "../security/231511069.h"
#include <sstream>   // Sertakan header yang diperlukan untuk stringstream
#include <cctype>    // Sertakan header yang diperlukan untuk isupper
#include <algorithm> // Sertakan header yang diperlukan untuk transform

// Fungsi untuk membersihkan karakter tersembunyi dari string
void cleanHiddenCharacters(std::string &str)
{
    for (char &c : str)
    {
        if (!isprint(static_cast<unsigned char>(c)))
        {            // Periksa apakah karakter tidak dapat dicetak
            c = ' '; // Ganti karakter tersembunyi dengan spasi
        }
    }
}

// Fungsi untuk mengonversi string menjadi huruf kecil
std::string toLowercase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

// Fungsi untuk memeriksa apakah nama di file cocok dengan nama yang dicari sampai bagian pertama dari nama yang dicari
bool isPartialMatch(const std::string &nama_in_file, const std::string &nama_dicari)
{
    // Mengonversi kedua nama menjadi huruf kecil untuk perbandingan yang tidak bersifat case-sensitive
    std::string lowercase_nama_in_file = toLowercase(nama_in_file);
    std::string lowercase_nama_dicari = toLowercase(nama_dicari);

    // Memeriksa apakah bagian pertama dari nama di file cocok dengan nama yang dicari
    return lowercase_nama_in_file.find(lowercase_nama_dicari) != std::string::npos;
}

void searchByName(const std::string &user, const std::string &nama)
{
    std::ifstream inputFile(user + ".txt");
    Siswa siswa;
    std::string nik_dekripsi, kk_dekripsi, alamat_dekripsi;

    if (inputFile.is_open())
    {
        bool found = false;
        std::string line;
        int count = 0;

        // Deklarasi variabel dekripsi di sini
        std::string nik_dekripsi, kk_dekripsi, alamat_dekripsi;

        // Membersihkan nama yang dicari dari karakter tersembunyi
        std::string cleaned_nama = nama;
        cleanHiddenCharacters(cleaned_nama);

        // Loop melalui setiap baris dalam file
        while (getline(inputFile, line))
        {
            count++;
            std::istringstream ss(line); // Ubah menjadi std::istringstream

            // Membaca data siswa dari setiap baris
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

            // Membersihkan dan mengonversi nama siswa dari karakter tersembunyi dan huruf besar
            std::string cleaned_siswa_nama = siswa.NAMA;
            cleanHiddenCharacters(cleaned_siswa_nama);

            // Jika nama yang dicari ditemukan, tampilkan data siswa tersebut
            if (isPartialMatch(cleaned_siswa_nama, cleaned_nama))
            {
                found = true;
                std::cout << "---------------------------------------\n";
                std::cout << "Data siswa dengan nama '" << nama << "' ditemukan:\n";
                std::cout << "---------------------------------------\n";
                std::cout << "NIS: " << siswa.NIS << std::endl;
                std::cout << "NISN: " << siswa.NISN << std::endl;
                std::cout << "Nama: " << siswa.NAMA << std::endl;
                std::cout << "Jenis Kelamin: " << siswa.JENIS_KELAMIN << std::endl;
                std::cout << "TTL: " << siswa.TTL << std::endl;
                std::cout << "NIK: " << nik_dekripsi << std::endl;
                std::cout << "No.KK: " << kk_dekripsi << std::endl;
                std::cout << "Agama: " << siswa.AGAMA << std::endl;
                std::cout << "Alamat Rumah: " << alamat_dekripsi << std::endl;
                std::cout << "No.HP: " << siswa.No_HP << std::endl;
                std::cout << "Email: " << siswa.Email << std::endl;
                std::cout << std::endl;
                break; // Keluar dari loop setelah menemukan nama yang dicari
            }
        }

        // Jika nama tidak ditemukan
        if (!found)
        {
            std::cout << "---------------------------------------\n";
            std::cout << "Data siswa dengan nama '" << nama << "' tidak ditemukan.\n";
            std::cout << "---------------------------------------\n";
        }

        inputFile.close();
    }
    else
    {
        std::cerr << "Filenya tidak bisa dibuka.\n";
    }
}