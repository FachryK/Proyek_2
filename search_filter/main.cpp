#include <iostream>
#include <string>

class Student
{
private:
    std::string name;
    // Hapus atribut tahunMasuk
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
    // Buat objek student dan inisialisasi array students
    const int studentCount = 1; // Menggunakan array dengan satu elemen saja
    Student students[studentCount] = {Student("Fachry Khair")};

    // Pencarian mahasiswa berdasarkan nama
    std::string searchName = "Fachry Khair";
    Student result = searchStudentByName(students, studentCount, searchName);

    if (result.getName() != "")
    {
        std::cout << "Mahasiswa dengan nama " << searchName << " ditemukan." << std::endl;
    }
    else
    {
        std::cout << "Mahasiswa dengan nama " << searchName << " tidak ditemukan." << std::endl;
    }

    return 0;
}
