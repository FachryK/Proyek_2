#include "student.h"

// Implementasi kelas Student

// Konstruktor
Student::Student(const std::string &name, int year)
    : name(name), year(year)
{
}

// Getter untuk nama mahasiswa
std::string Student::getName() const
{
    return name;
}

// Getter untuk tahun masuk mahasiswa
int Student::getYear() const
{
    return year;
}
