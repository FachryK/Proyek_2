#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    // Konstruktor
    Student(const std::string &name);

    // Getter untuk nama mahasiswa
    std::string getName() const;

private:
    // Properti pribadi
    std::string name;
};

#endif // STUDENT_H
