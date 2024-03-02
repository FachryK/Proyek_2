#include <iostream>
#include <fstream>
#include <string>
 
// Module for handling user input and saving to a text file
namespace UserInputModule {

    void GetUserInputAndSaveToFile() {
        std::string NIS, NISN, NAMA, JENIS_KELAMIN, TTL, NIK, NO_KK, AGAMA, ALAMAT_RUMAH, NO_HP, ALAMAT_EMAIL;
 
        // Getting user input for student details
        std::cout << "Enter NIS: ";
        std::cin >> NIS;
        std::cout << "Enter NISN: ";
        std::cin >> NISN;
        std::cout << "Enter NAMA: ";
        std::cin.ignore(); // Ignore the newline character left in the stream
        std::getline(std::cin, NAMA);
        std::cout << "Enter JENIS KELAMIN: ";
        std::cin >> JENIS_KELAMIN;
        std::cout << "Enter TTL: ";
        std::cin.ignore();
        std::getline(std::cin, TTL);
        std::cout << "Enter NIK: ";
        std::cin >> NIK;
        std::cout << "Enter NO.KK: ";
        std::cin >> NO_KK;
        std::cout << "Enter AGAMA: ";
        std::cin >> AGAMA;
        std::cout << "Enter ALAMAT RUMAH: ";
        std::cin.ignore();
        std::getline(std::cin, ALAMAT_RUMAH);
        std::cout << "Enter NO.HP: ";
        std::cin >> NO_HP;
        std::cout << "Enter ALAMAT EMAIL: ";
        std::cin >> ALAMAT_EMAIL;
 
        // Saving the student details to a text file
        std::ofstream outputFile("student_details.txt");
        if (outputFile.is_open()) {
            outputFile << "NIS: " << NIS << "\n";
            outputFile << "NISN: " << NISN << "\n";
            outputFile << "NAMA: " << NAMA << "\n";
            outputFile << "JENIS KELAMIN: " << JENIS_KELAMIN << "\n";
            outputFile << "TTL: " << TTL << "\n";
            outputFile << "NIK: " << NIK << "\n";
            outputFile << "NO.KK: " << NO_KK << "\n";
            outputFile << "AGAMA: " << AGAMA << "\n";
            outputFile << "ALAMAT RUMAH: " << ALAMAT_RUMAH << "\n";
            outputFile << "NO.HP: " << NO_HP << "\n";
            outputFile << "ALAMAT EMAIL: " << ALAMAT_EMAIL << "\n";
            outputFile.close();
            std::cout << "Student details saved to student_details.txt\n";
        } else {
            std::cerr << "Unable to open file for writing.\n";
        }
    }
}