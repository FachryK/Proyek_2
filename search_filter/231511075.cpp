#include <iostream>
#include <string>
#include "../input_output/231511084.h"

class Student
{
private:
    std::string name;

public:
    Student(const std::string &name) : name(name) {}

    std::string getName() const
    {
        return name;
    }
};

// Fungsi pencarian mahasiswa berdasarkan nama
Student searchStudentByName(const Student *students, int size, const std::string &name)
{
    for (int i = 0; i < size; ++i)
    {
        if (students[i].getName() == name)
        {
            return students[i];
        }
    }
    // Jika mahasiswa tidak ditemukan, kembalikan objek dengan nama kosong
    return Student("");
}

int main()
{
    
    Siswa siswa;
    std::string bebas;
    // Buat objek student dan inisialisasi array students
    
    cout << "Masukkan Nama yang dicari : ";
    cin >> bebas;


    const int studentCount = 1; // Menggunakan array dengan satu elemen saja
    Student students[studentCount] = {Student(siswa.NAMA)};
    // Pencarian mahasiswa berdasarkan NAMA
    std::string searchName = siswa.NAMA;

    std::ifstream readFile("siswa.txt");
    if (readFile.is_open())
    {
        if (bebas == siswa.NAMA)
        {
            std::cout << "Mahasiswa dengan NAMA " << siswa.NAMA << " ditemukan." << std::endl;
        }
        else
        {
            std::cout << "Mahasiswa dengan NAMA " << siswa.NAMA << " tidak ditemukan." << std::endl;
        }
        
        
        Student result = searchStudentByName(students, studentCount, searchName);

        // if (result.getName() != "")
        // {
            
        // }
        // else
        // {
            
        // }
        // readFile.close();
    }

    // Student result = searchStudentByName(students, studentCount, searchName);

    // if (result.getName() != "")
    // {
    //     std::cout << "Mahasiswa dengan nama " << siswa.Nama << " ditemukan." << std::endl;
    // }
    // else
    // {
    //     std::cout << "Mahasiswa dengan nama " << searchName << " tidak ditemukan." << std::endl;
    // }

    return 0;
}
