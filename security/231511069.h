#ifndef HILLCIPHER_ENKRIPSI_H
#define HILLCIPHER_ENKRIPSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

std::string enkripsi_int(int data);
std::string enkripsi_text(const std::string &text);

std::string dekripsi_text(const std::string &text);
std::string dekripsi_int(int data);


#endif /* HILLCIPHER_ENKRIPSI_H */