//
// Created by William Tissi on 5/1/25.
//
//instead of creating a inout validator everytime, I thought about creating it once as a function and whenever you want to use it, you just send the range that you want the user input to be in, and this function handle that problem. keep asking the user to enter the correc value until the user execute

#include "../include/getValidInt.h"
#include <iostream>

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