#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Siswa{
    string NAMA;
    string JENIS_KELAMIN;
    string TTL;
    string AGAMA;
    string ALAMAT_RUMAH;
    string Email;
    int NIS;
    int NISN;
    int NIK;
    int No_KK;
    int No_HP;
};
 
void inputdata(const string &user); 
void outputdata(const string &user);
void pilihan(const string &user); 
