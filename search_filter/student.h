#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    // Konstruktor
    Student(const std::string &name, int year);

    // Getter untuk nama mahasiswa
    std::string getName() const;

    // Getter untuk tahun masuk mahasiswa
    int getYear() const;

private:
    // Properti pribadi
    std::string name;
    int year;
};

#endif // STUDENT_H
