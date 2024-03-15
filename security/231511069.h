#ifndef HILLCIPHER_ENKRIPSI_H
#define HILLCIPHER_ENKRIPSI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

std::string enkripsi_text(int data);
std::string enkripsi_text(const std::string &text);

void dekripsi_text(const std::string &text);
void dekripsi_text(int data);


#endif /* HILLCIPHER_ENKRIPSI_H */