#include <string>

// Struktur untuk menyimpan data
struct Data {
    std::string NIS;
    std::string NISN;
    std::string NAMA;
    std::string JENIS_KELAMIN;
    std::string TTL;
    std::string NIK;
    std::string NO_KK;
    std::string AGAMA;
    std::string ALAMAT_RUMAH;
    std::string NO_HP;
    std::string ALAMAT_EMAIL;
};

// Deklarasi fungsi untuk menyimpan data ke dalam file
void saveDataToFile(const std::string& filename, const Data& data);