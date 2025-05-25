#include "../include/UserDatabase.h"
#include "../include/NameValidation.h"
#include <iostream>
#include <cctype>

using namespace std;

bool UserDatabase::isInitialized() {
    return !users.empty();
}

bool UserDatabase::isValidPassword(const string& password) {
    bool hasDigit = false, hasAlpha = false;
    for (char c : password) {
        if (isdigit(c)) hasDigit = true;
        if (isalpha(c)) hasAlpha = true;
    }
    return hasDigit && hasAlpha;
}

string UserDatabase::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void UserDatabase::createFirstAccount() {
    string firstName, lastName, password;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;

    do {
        cout << "Password (must contain letter and number): ";
        cin >> password;
    } while (!isValidPassword(password));

    users[toLowerCase(firstName + lastName)] = password;
    cout << "Admin account created successfully!\n";
}

bool UserDatabase::login() {
    string firstName, lastName, password;
    cout << "Login:\nFirst Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Password: ";
    cin >> password;

    string fullName = toLowerCase(firstName + lastName);
    if (users.find(fullName) != users.end() && users[fullName] == password) {
        loggedIn = true;
        cout << "Login successful!\n";
        return true;
    }
    cout << "Invalid credentials.\n";
    return false;
}

void UserDatabase::addNewUser() {
    if (!loggedIn) {
        cout << "You must be logged in to add users.\n";
        return;
    }

    string firstName, lastName, password;
    cout << "Add new user:\nFirst Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;

    do {
        cout << "Password (must contain letter and number): ";
        cin >> password;
    } while (!isValidPassword(password));

    users[toLowerCase(firstName + lastName)] = password;
    cout << "New user added successfully!\n";
}

// just to verify
bool UserDatabase::isLoggedIn() {
    return loggedIn;
}