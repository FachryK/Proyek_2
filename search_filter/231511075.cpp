#include "231511075.h" // Sertakan file header yang diperlukan
#include "../security/231511069.h"
#include <sstream> // Sertakan header yang diperlukan untuk stringstream

void searchByName(const std::string &user, const std::string &nama)
{
    std::ifstream inputFile(user + ".txt");
    Siswa siswa;

    if (inputFile.is_open())
    {
        bool found = false;
        std::string line;
        int count = 0;

        // Deklarasi variabel dekripsi di sini
        std::string nik_dekripsi, kk_dekripsi, alamat_dekripsi;

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
                // Dekripsi data yang diperlukan
                nik_dekripsi = dekripsi_text(siswa.NIK);
            kk_dekripsi = dekripsi_text(siswa.No_KK);
            alamat_dekripsi = dekripsi_text(siswa.ALAMAT_RUMAH);

            // Jika nama yang dicari ditemukan, tampilkan data siswa tersebut
            if (siswa.NAMA == nama)
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