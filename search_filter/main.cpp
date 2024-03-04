    #include <iostream>
    #include <vector>
    #include "student.h"

    // Fungsi pencarian mahasiswa berdasarkan nama
    Student searchStudentByName(const std::vector<Student> &students, const std::string &name)
    {
        for (const Student &student : students)
        {
            if (student.getName() == name)
            {
                return student;
            }
        }
        // Jika mahasiswa tidak ditemukan, kembalikan objek dengan nama kosong dan tahun -1
        return Student("", -1);
    }

    // Fungsi filter mahasiswa berdasarkan tahun masuk
    std::vector<Student> filterStudentsByYear(const std::vector<Student> &students, int year)
    {
        std::vector<Student> filteredStudents;
        for (const Student &student : students)
        {
            if (student.getYear() == year)
            {
                filteredStudents.push_back(student);
            }
        }
        return filteredStudents;
    }

    int main()
    {
        // Contoh penggunaan
        std::vector<Student> students;
        students.push_back(Student("Fakhrie Rizdan", 2022));
        students.push_back(Student("Fachry Khair", 2023));
        students.push_back(Student("Alvito Nova", 2022));

        // Pencarian mahasiswa berdasarkan nama
        std::string searchName = "Fachry Khair";
        Student result = searchStudentByName(students, searchName);

        if (result.getName() != "")
        {
            std::cout << "Mahasiswa dengan nama " << searchName << " ditemukan. Tahun masuk: " << result.getYear() << std::endl;
        }
        else
        {
            std::cout << "Mahasiswa dengan nama " << searchName << " tidak ditemukan." << std::endl;
        }

        // Filter mahasiswa berdasarkan tahun masuk
        int filterYear = 2022;
        std::vector<Student> filteredStudents = filterStudentsByYear(students, filterYear);

        if (!filteredStudents.empty())
        {
            std::cout << "Mahasiswa yang masuk tahun " << filterYear << ":" << std::endl;
            for (const Student &student : filteredStudents)
            {
                std::cout << "- " << student.getName() << std::endl;
            }
        }
        else
        {
            std::cout << "Tidak ada mahasiswa yang masuk tahun " << filterYear << "." << std::endl;
        }

        return 0;
    }
