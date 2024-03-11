#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class LoginManager {
public:
    void saveToFile(const std::unordered_map<std::string, std::string>& accounts);
    std::unordered_map<std::string, std::string> readFromFile();
    bool login(const std::unordered_map<std::string, std::string>& accounts, const std::string& username, const std::string& password);
    void createAccount(std::unordered_map<std::string, std::string>& accounts);
    void changePassword(std::unordered_map<std::string, std::string>& accounts, const std::string& username);
};

#endif // LOGIN_MANAGER_H
