//
// Created by William Tissi on 5/1/25.
//
#include "../include/NameValidation.h"
#include <iostream>

using namespace std;

string convertToLowerCase(const string& nameReceived) {
    string resultCopy = nameReceived;
    for (char& z : resultCopy) {
        z = tolower(z);
    }
    return resultCopy;
}

// Helper: check if a string is all letters
bool isAllLetters(const string& s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

