#include "student.h"

// Implementasi kelas Student

// Konstruktor
Student::Student(const std::string &name)
    : name(name)
{
}

// Getter untuk nama mahasiswa
std::string Student::getName() const
{
    return name;
}
