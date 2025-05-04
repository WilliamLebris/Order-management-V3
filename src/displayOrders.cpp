//
// Created by William Tissi on 5/1/25.
//

#include "../include/displayOrders.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
namespace displayOrderDeclaration {
// here basically we are just reading from the csv file to print orders since they are saved there
    void displayOrders() {
        ifstream inputFile("data/ordersFile.csv");

        if (!inputFile.is_open()) {
            cout << "Sorry, Error opening file: ordersFile.csv\n";
            return;
        }

        string line;
        string orderBuffer;

        while (getline(inputFile, line)) {
            // Detect the start of a new order
            if (line == "====================") {
                if (!orderBuffer.empty()) {
                    // Print the collected order details
                    cout << orderBuffer << "\n";
                    orderBuffer.clear(); // Reset for the next order
                }
            } else {
                orderBuffer += line + "\n"; // Add the line to the current order
            }
        }

        // Print the last order if any
        if (!orderBuffer.empty()) {
            cout << orderBuffer << "\n";
        }

        inputFile.close();
    }

}
