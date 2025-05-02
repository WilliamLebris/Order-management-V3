//
// Created by William Tissi on 5/1/25.
//

#include "../include/displayOrders.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace displayOrderDeclaration {

    void displayOrders() {
        std::ifstream inputFile("data/ordersFile.csv");

        if (!inputFile.is_open()) {
            std::cout << "Error opening file: ordersFile.csv\n";
            return;
        }

        std::string line;
        std::string orderBuffer;

        while (std::getline(inputFile, line)) {
            // Detect the start of a new order
            if (line == "====================") {
                if (!orderBuffer.empty()) {
                    // Print the collected order details
                    std::cout << orderBuffer << "\n";
                    orderBuffer.clear(); // Reset for the next order
                }
            } else {
                orderBuffer += line + "\n"; // Add the line to the current order
            }
        }

        // Print the last order if any
        if (!orderBuffer.empty()) {
            std::cout << orderBuffer << "\n";
        }

        inputFile.close();
    }

}
