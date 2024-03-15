#include "231511069.h"
#include <iostream>

int main() {
    std::string encrypted1 = enkripsi_text("alvito");
    std::string encrypted2 = enkripsi_text(2323);

    std::cout << "Encrypted 1: " << encrypted1 << std::endl;
    std::cout << "Encrypted 2: " << encrypted2 << std::endl;

    // Dekripsi teks
    std::cout << "Dekripsi 1: ";
    dekripsi_text(encrypted1);
    std::cout << std::endl;

    std::cout << "Dekripsi 2: ";
    dekripsi_text(encrypted2);
    std::cout << std::endl;

    return 0;
}
