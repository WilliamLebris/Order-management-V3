#ifndef USER_DATABASE_H
#define USER_DATABASE_H

#include <string>
#include <unordered_map>

class UserDatabase {
private:
    static inline std::unordered_map<std::string, std::string> users;
    static inline bool loggedIn = false;

    static bool isValidPassword(const std::string& password);
    static bool isAllLetters(const std::string& str);
    static std::string toLowerCase(const std::string& str);

public:
    static bool isInitialized();
    static void createFirstAccount();
    static bool login();
    static void addNewUser();
    static bool isLoggedIn();
};

#endif