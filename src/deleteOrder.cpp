//
// Created by William Tissi on 5/1/25.
//

#include "../include/deleteOrder.h"
#include "../include/globalVariable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert string to lowercase for case-insensitive comparison
string toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to trim leading and trailing spaces
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

// Delete an Order from the ordersFile.csv
void deleteOrderDeclaration::deleteOrder() {
    string name;
    cout << "Enter the customer name to delete the order: ";
    getline(cin, name);

    // Trim and convert name to lowercase
    name = trim(name);
    string lowerCaseName = toLowerCase(name);

    ifstream inFile("data/ordersFile.csv");
    if (!inFile) {
        cout << "Error opening orders file!" << endl;
        return;
    }

    ofstream tempFile("data/temp.csv");
    if (!tempFile) {
        cout << "Error creating temporary file!" << endl;
        return;
    }

    string line;
    bool found = false;
    int linesToSkip = 0;  // To keep track of how many lines to skip (numFields + 1 + (numProducts - 1))

    // Read the file line by line
    while (getline(inFile, line)) {
        stringstream ss(line);
        string customerName;

        // Check if the line starts with "name:" and extract the name after it
        if (line.find("name:") != string::npos) {
            size_t startPos = line.find("name:") + 5; // Skip past "name:"
            size_t endPos = line.find("phone:"); // Assuming "phone:" comes after the name field
            customerName = line.substr(startPos, endPos - startPos); // Extract name substring
            customerName = trim(customerName); // Clean up any spaces around the name

            // If the customer name matches the one to be deleted
            if (toLowerCase(customerName) == lowerCaseName) {
                found = true;
                cout << "Order for " << name << " found. Deleting order..." << endl;

                // Skip numFields + 1 + (numProducts - 1) rows
                linesToSkip = numFields + 1 + (numProducts - 1);
                continue; // Skip writing this line (the name line) to the temp file
            }
        }

        // If we are not skipping the current line, write it to the temporary file
        if (linesToSkip == 0) {
            tempFile << line << endl;
        } else {
            linesToSkip--;  // Decrease the skip counter
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the updated file (without the deleted order)
        remove("data/ordersFile.csv");
        rename("data/temp.csv", "data/ordersFile.csv");
    } else {
        cout << "Order not found." << endl;
    }
}


