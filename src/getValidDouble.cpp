//
// Created by William Tissi on 5/1/25.
//

#include "../include/getValidDouble.h"

#include<iostream>


using namespace std;

// Function to handle double (price) input safely. we need to make sure that the user can't crash the program and enter the right expecting input

double doubleValidation::getValidDouble(double min) {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail() || value < min) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip characters (number of character depend) or until a newline
            cout << "Invalid input! Please enter a valid price (>= " << min << "): ";
        } else {
            cin.ignore();
            return value;
        }
    }
}
