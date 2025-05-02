//
// Created by William Tissi on 5/1/25.
//

#include "../include/UserDatabase.h"
#include "../include/NameValidation.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>


using namespace std;


unordered_map<string, string> userDatabase;
bool loggedIn = false;


// Helper function to validate password
bool isValidPassword(const string& password) {
    bool hasDigit = false, hasAlpha = false;
    for (char c : password) {
        if (isdigit(c)) hasDigit = true;
        if (isalpha(c)) hasAlpha = true;
    }
    return hasDigit && hasAlpha;
}

// Create first account
void createFirstAccount() {
    string firstName, lastName, password;
    cout << "Create your first account.\n";
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;

    do {
        cout << "Password (must contain letter and number): ";
        cin >> password;
    } while (!isValidPassword(password));

    userDatabase[firstName + lastName] = password;
   cout << "Account created successfully!\n";
}

// Login function
bool login() {
    string firstName, lastName, password;
    cout << "Login:\n";

    cout << "First Name: ";
    cin >> firstName;
    if (!isAllLetters(firstName)) {
        cout << "First name must contain only letters.\n";
        return false;
    }

    cout << "Last Name: ";
    cin >> lastName;
    if (!isAllLetters(lastName)) {
        cout << "Last name must contain only letters.\n";
        return false;
    }

    cout << "Password: ";
    cin >> password;

    string fullName = toLowerCase(firstName + lastName);
    if (userDatabase.find(fullName) != userDatabase.end() && userDatabase[fullName] == password) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}

// Add new user (only if logged in)
void addNewUser() {
    string firstName, lastName, password;
    cout << "Add a new user:\n";

    cout << "First Name: ";
    cin >> firstName;
    if (!isAllLetters(firstName)) {
        cout << "First name must contain only letters.\n";
        return;
    }

    cout << "Last Name: ";
    cin >> lastName;
    if (!isAllLetters(lastName)) {
        cout << "Last name must contain only letters.\n";
        return;
    }

    do {
        cout << "Password (must contain letter and number): ";
        cin >> password;
    } while (!isValidPassword(password));

    string fullName = toLowerCase(firstName + lastName);
    userDatabase[fullName] = password;
    cout << "New user created successfully!\n";
}
