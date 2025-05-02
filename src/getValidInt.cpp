//
// Created by William Tissi on 5/1/25.
//
//instead of creating a inout validator everytime, I thought about creating it once as a function and whenever you want to use it, you just send the range that you want the user input to be in, and this function handle that problem. keep asking the user to enter the correc value until the user execute

#include "../include/getValidInt.h"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>


using namespace std;

// Function to handle integer input safely,
int intValidation::getValidInt(int min, int max) {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(); // to handle new line charachter after cin
            return value;   //You cannot use the ternary operator (? :) to replace return value; directly because it must be in a statement by itself.
        }
    }
}


bool intValidation::isValidDate(const string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    string yearStr = date.substr(0, 4);
    string monthStr = date.substr(5, 2);
    string dayStr = date.substr(8, 2);

    // Check digits only
    for (char c : yearStr + monthStr + dayStr) {
        if (!isdigit(c)) return false;
    }

    int year = stoi(yearStr);
    int month = stoi(monthStr);
    int day = stoi(dayStr);

    return year < 2025 && month >= 1 && month <= 12 && day >= 1 && day <= 31;
}

int intValidation::validateLettersOrDigits(const std::string& input) {
    if (input.empty()) return 0;

    bool allLetters = true, allDigits = true;
    for (char ch : input) {
        if (!isalpha(ch)) allLetters = false;
        if (!isdigit(ch)) allDigits = false;
    }

    if (allLetters) return 1;
    if (allDigits) return 2;
    return 0; // Mixed or contains symbols/spaces
}