//
// Created by William Tissi on 5/1/25.
//
#include "../include/setupCustomerFields.h"
#include "../include/order_system.h"
#include "../include/getValidInt.h"
#include <iostream>
using namespace std;

//Setup Customer Fields (e.g., Name, Phone). I use 5 max the max for this program but we can always increase it
// setupCustomerFields.cpp
void setCustomerDeclaration::setupCustomerFields() {
    cout << "How many details should customers provide? (e.g., Name, Phone) Max "
         << OrderSystem::MAX_CUSTOMER_FIELDS << ": ";
    int numFields = intValidation::getValidInt(1, OrderSystem::MAX_CUSTOMER_FIELDS);

    vector<string> fields;
    for (int i = 0; i < numFields; i++) {
        while (true) {
            string fieldName;
            cout << "Enter field #" << i + 1 << " (e.g., Name, Phone, ID #): ";
            getline(cin, fieldName);

            int result = intValidation::validateLettersOrDigits(fieldName);

            if (result == 1) {
                cout << "Accepted: All letters (e.g., Name).\n";
                fields.push_back(fieldName);
                break;
            } else if (result == 2) {
                cout << "Accepted: All digits (e.g., ID/Phone).\n";
                fields.push_back(fieldName);
                break;
            } else {
                cout << "Invalid input. Please enter only letters or only digits.\n";
            }
        }
    }

    OrderSystem::setCustomerFields(fields);
}
