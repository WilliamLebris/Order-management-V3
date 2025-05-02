//
// Created by William Tissi on 5/1/25.
//
#include "../include/setupCustomerFields.h"
#include "../include/globalVariable.h"
#include "../include/getValidInt.h"
#include <iostream>
using namespace std;

//Setup Customer Fields (e.g., Name, Phone). I use 5 max the max for this program but we can always increase it
void setCustomerDeclaration::setupCustomerFields() {
    cout << "How many details should customers provide? (e.g., Name, Phone) Max 5: ";
    numFields = intValidation::getValidInt(1, 5);  // make sure it is between 1 and 5


    // we can't use for ranged based loop here because we need to stop after the loop depending on the user answer
    for (int i = 0; i < numFields; i++) {
        while (true) {
            cout << "Enter field #" << i + 1 << " (e.g., Name, Phone, ID #): ";
            getline(cin, customerFields[i]);

            int result = intValidation::validateLettersOrDigits(customerFields[i]);

            if (result == 1) {
                cout << "Accepted: All letters (e.g., Name).\n";
                break;
            } else if (result == 2) {
                cout << "Accepted: All digits (e.g., ID/Phone).\n";
                break;
            } else {
                cout << "Invalid input. Please enter only letters or only digits.\n";
            }
        }
    }

}
