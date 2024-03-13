#ifndef SAVE_DATA_SISWA_H
#define SAVE_DATA_SISWA_H

#include <string> // Mengimpor header file <string> yang menyediakan kelas string dan fungsi-fungsi terkait yang akan digunakan dalam deklarasi fungsi

void login();
bool login(const std::string& username, const std::string& password);
void registrasi();
void gantiSandi();
void pilihan();

#endif // SAVE_DATA_SISWA_H