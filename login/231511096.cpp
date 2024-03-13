#include "231511096.h" // Include file header yang berisi deklarasi fungsi yang digunakan dalam program.
#include <iostream> // Include library untuk operasi standar input-output.
#include <fstream> // Include library untuk operasi file input-output.
#include <sstream> // Include library untuk operasi string stream.
#include <cstdio> // Include library untuk menggunakan fungsi remove() dan rename().

void login() // Fungsi untuk menampilkan layar selamat datang dan menu login.
{
    system("cls"); // Menghapus semua teks sebelumnya dari layar/terminal.

    std::cout << "============================================================" << std::endl;
    std::cout << "|                   SELAMAT DATANG DI                      |" << std::endl;
    std::cout << "|                APLIKASI SAVE DATA SISWA                  |" << std::endl;
    std::cout << "============================================================" << std::endl;
}

bool login(const std::string& username, const std::string& password) // Fungsi untuk login dengan memeriksa username dan password.
{
    std::ifstream readFile("data-pengguna.txt"); // Buka file "data-pengguna.txt" untuk membaca data pengguna.

    if (readFile.is_open()) // Jika file berhasil dibuka.
    {
        std::string data, cekUsername, cekPassword; // Deklarasikan variabel untuk menyimpan data username dan password dari file.
        bool cariUsername = false; // Variabel untuk menunjukkan apakah username ditemukan.

        while (getline(readFile, data) && !cariUsername) // Selama ada baris data yang dibaca dan belum menemukan username.
        {
            std::istringstream iss(data); // Buat objek stringstream untuk memproses baris teks.
            getline(iss, cekUsername, ','); // Baca username dari baris teks yang dipisahkan oleh koma.
            getline(iss, cekPassword, ','); // Baca password dari baris teks yang dipisahkan oleh koma.

            if (username == cekUsername) // Jika username yang dimasukkan cocok dengan username dalam file.
            {
                cariUsername = true; // Set variabel menjadi true karena username ditemukan.

                if (password == cekPassword) // Jika password yang dimasukkan cocok dengan password dalam file.
                {
                    login(); // Panggil fungsi login untuk menampilkan layar selamat datang.
                    std::cout << "=============================================================" << std::endl;
                    std::cout << "|                                                           |" << std::endl;
                    std::cout << "|                      LOGIN BERHASIL!                      |" << std::endl;
                    std::cout << "|                                                           |" << std::endl;
                    std::cout << "=============================================================" << std::endl;
                    return true; // Kembalikan nilai true karena login berhasil.
                }
                else // Jika password yang dimasukkan tidak cocok dengan password dalam file.
                {
                    std::cout << "============================================================" << std::endl;
                    std::cout << "|                                                           |" << std::endl;
                    std::cout << "|                      PASSWORD SALAH!                      |" << std::endl;
                    std::cout << "|                                                           |" << std::endl;
                    std::cout << "============================================================" << std::endl;
                    return false; // Kembalikan nilai false karena password salah.
                }
            }
        }

        if (!cariUsername) // Jika username tidak ditemukan dalam file.
        {
            login(); // Panggil fungsi login untuk menampilkan layar selamat datang.
            std::cout << "=============================================================" << std::endl;
            std::cout << "|                                                           |" << std::endl;
            std::cout << "|                  USERNAME TIDAK DITEMUKAN!                |" << std::endl;
            std::cout << "|                                                           |" << std::endl;
            std::cout << "=============================================================" << std::endl;
            return false; // Kembalikan nilai false karena username tidak ditemukan.
        }

        readFile.close(); // Tutup file setelah selesai membacanya.
    }
    else // Jika gagal membuka file.
    {
        std::cout << "Gagal mengakses data pengguna"; // Tampilkan pesan kesalahan.
    }

    return false; // Kembalikan nilai false jika tidak terjadi login.
}

void registrasi() // Fungsi untuk melakukan registrasi akun baru.
{
    login(); // Tampilkan layar selamat datang dan menu login.

    std::string username, password; // Deklarasikan variabel untuk menyimpan username dan password baru.

    std::cout << "Registrasi Akun Baru" << std::endl;
    std::cout << "Username (Username harus tanpa kapital dan spasi): ";
    std::cin >> username; // Minta pengguna memasukkan username baru.
    std::cout << "Password (Password tidak boleh mengandung unsur username) : ";
    std::cin >> password; // Minta pengguna memasukkan password baru.

    std::ifstream readFile("data-pengguna.txt"); // Buka file "data-pengguna.txt" untuk membaca data pengguna.

    if (readFile.is_open()) // Jika file berhasil dibuka.
    {
        std::string data, cekUsername; // Deklarasikan variabel untuk menyimpan data username dari file.
        bool usernameSama = false; // Variabel untuk menunjukkan apakah username sudah ada.

        while (getline(readFile, data)) // Selama ada baris data yang dibaca.
        {
            std::istringstream iss(data); // Buat objek stringstream untuk memproses baris teks.
            getline(iss, cekUsername, ','); // Baca username dari baris teks yang dipisahkan oleh koma.

            if (username == cekUsername) // Jika username yang dimasukkan sudah ada dalam file.
            {
                usernameSama = true; // Set variabel menjadi true karena username sudah ada.
                break; // Keluar dari loop karena sudah tidak perlu mencari lagi.
            }
        }

        if (!usernameSama) // Jika username belum ada dalam file.
        {
            std::ofstream writeFile("data-pengguna.txt", std::ios::app); // Buka file "data-pengguna.txt" untuk menulis data pengguna baru.

            if (writeFile.is_open()) // Jika file berhasil dibuka.
            {
                writeFile << username << "," << password << std::endl; // Tulis username dan password ke file.
                login(); // Tampilkan layar selamat datang dan menu login.
                std::cout << "=============================================================" << std::endl;
                std::cout << "|                                                            |" << std::endl;
                std::cout << "|                   REGISTRASI BERHASIL!                     |" << std::endl;
                std::cout << "|                                                            |" << std::endl;
                std::cout << "=============================================================" << std::endl;
                writeFile.close(); // Tutup file setelah selesai menulis.
            }
            else // Jika gagal membuka file.
            {
                std::cout << "Gagal mengakses data pengguna"; // Tampilkan pesan kesalahan.
            }
        }
        else // Jika username sudah ada dalam file.
        {
            std::cout << "Username sudah digunakan. Registrasi gagal." << std::endl; // Tampilkan pesan bahwa username sudah digunakan.
        }

        readFile.close(); // Tutup file setelah selesai membacanya.
    }
    else // Jika gagal membuka file.
    {
        std::cout << "Gagal mengakses data pengguna"; // Tampilkan pesan kesalahan.
    }
}

void gantiSandi() // Fungsi untuk mengganti sandi pengguna.
{
    login(); // Tampilkan layar selamat datang dan menu login.

    std::string username, oldPassword, newPassword; // Deklarasikan variabel untuk menyimpan username, password lama, dan password baru.

    std::cout << "Ganti Sandi" << std::endl;
    std::cout << "Username : ";
    std::cin >> username; // Minta pengguna memasukkan username.
    std::cout << "Password Lama : ";
    std::cin >> oldPassword; // Minta pengguna memasukkan password lama.

    std::ifstream readFile("data-pengguna.txt"); // Buka file "data-pengguna.txt" dalam mode baca.
    std::ofstream tempFile("temp.txt"); // Buka file temporary untuk menulis data pengguna baru.

    if (readFile.is_open() && tempFile.is_open()) // Jika kedua file berhasil dibuka.
    {
        std::string data, cekUsername, cekPassword; // Deklarasikan variabel untuk menyimpan data yang dibaca dari file.
        bool cariUsername = false; // Variabel untuk menunjukkan apakah username ditemukan.
        bool passwordBenar = false; // Variabel untuk menunjukkan apakah password lama benar.

        while (getline(readFile, data)) // Baca setiap baris data dari file.
        {
            std::istringstream iss(data); // Buat objek stringstream untuk memproses baris teks.
            getline(iss, cekUsername, ','); // Baca username dari baris teks.
            getline(iss, cekPassword, ','); // Baca password dari baris teks.

            if (username == cekUsername) // Jika username yang dimasukkan cocok dengan username dalam file.
            {
                cariUsername = true; // Atur variabel menjadi true karena username ditemukan.

                if (oldPassword == cekPassword) // Jika password lama yang dimasukkan cocok dengan password dalam file.
                {
                    passwordBenar = true; // Atur variabel menjadi true karena password lama benar.
                    std::cout << "Password Baru : ";
                    std::cin >> newPassword; // Minta pengguna memasukkan password baru.
                    tempFile << username << "," << newPassword << std::endl; // Tulis username dan password baru ke file temporary.
                    std::cout << "Sandi berhasil diganti." << std::endl;
                }
                else // Jika password lama yang dimasukkan salah.
                {
                    // Salin data pengguna tanpa mengubah password jika password lama salah.
                    tempFile << data << std::endl;
                }
            }
            else // Jika username tidak cocok.
            {
                // Salin data pengguna yang tidak sesuai username.
                tempFile << data << std::endl;
            }
        }

        // Jika username tidak ditemukan, tampilkan pesan.
        if (!cariUsername)
        {
            std::cout << "Username tidak ditemukan. Gagal mengganti sandi." << std::endl;
        }
        else if (!passwordBenar) // Jika password lama salah, tampilkan pesan.
        {
            std::cout << "Password lama salah. Gagal mengganti sandi." << std::endl;
        }

        readFile.close(); // Tutup file baca.
        tempFile.close(); // Tutup file temporary.

        // Ganti nama file temporary menjadi file asli jika password benar.
        if (passwordBenar)
        {
            remove("data-pengguna.txt"); // Hapus file asli.
            rename("temp.txt", "data-pengguna.txt"); // Ganti nama file temporary menjadi file asli.
        }
        else // Hapus file temporary jika password salah.
        {
            remove("temp.txt");
        }
    }
    else // Jika gagal membuka salah satu atau kedua file.
    {
        std::cout << "Gagal mengakses data pengguna"; // Tampilkan pesan kesalahan.
    }
}

void pilihan() // Fungsi untuk menampilkan menu pilihan.
{
    login(); // Tampilkan layar selamat datang dan menu login.

    int choice; // Deklarasikan variabel untuk menyimpan pilihan pengguna.

    std::cout << "Pilihan:" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Registrasi" << std::endl;
    std::cout << "3. Ganti Sandi" << std::endl;
    std::cout << "Pilih opsi: ";
    std::cin >> choice; // Minta pengguna memilih opsi.

    switch (choice) // Periksa pilihan pengguna.
    {
    case 1: // Jika pengguna memilih untuk login.
    {
        std::string username, password; // Deklarasikan variabel untuk menyimpan username dan password.
        login(); // Tampilkan layar selamat datang dan menu login.
        std::cout << "Login" << std::endl;
        std::cout << "Username : ";
        std::cin >> username; // Minta pengguna memasukkan username.
        std::cout << "Password : ";
        std::cin >> password; // Minta pengguna memasukkan password.
        login(username, password); // Panggil fungsi login dengan username dan password yang dimasukkan.
        break;
    }
    case 2: // Jika pengguna memilih untuk registrasi.
        registrasi(); // Panggil fungsi registrasi.
        break;
    case 3: // Jika pengguna memilih untuk mengganti sandi.
        gantiSandi(); // Panggil fungsi untuk mengganti sandi.
        break;
    default: // Jika pengguna memilih opsi yang tidak valid.
        login(); // Tampilkan layar selamat datang dan menu login.
        std::cout << "Pilihan tidak valid." << std::endl;
        break;
    }
}

int main() // Fungsi utama program.
{
    pilihan(); // Panggil fungsi untuk menampilkan menu pilihan.
    return 0; // Kembalikan nilai 0 sebagai tanda program berakhir dengan sukses.
}
