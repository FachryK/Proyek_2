#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#ifndef _231511084_H
#define _231511084_H

struct Siswa{
    string NAMA;
    string JENIS_KELAMIN;
    string TTL;
    string AGAMA;
    string ALAMAT_RUMAH;
    string Email;
    string NIS;
    string NISN;
    string NIK;
    string No_KK;
    string No_HP;
};
 
void inputdata(const string &user); 
void outputdata(const string &user);
void pilihan(const string &user); 

#endif //231511084.h