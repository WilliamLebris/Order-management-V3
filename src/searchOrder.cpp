//
// Created by William Tissi on 5/1/25.
//

#include "../include/searchOrder.h"
#include "../include/globalVariable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to convert string to lowercase for case-insensitive comparison
string convertionLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to trim leading and trailing spaces
string Trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

// Search Order by Name or Date in ordersFile.csv
void searchOrderDeclaration::searchOrder() {
    string searchQuery;

    // Prompt user for search input: either name or date
    cout << "Enter customer name of the customer to search: ";
    getline(cin, searchQuery);

    // Convert search query to lowercase for case-insensitive search
    string lowerCaseSearchQuery = convertionLowerCase(Trim(searchQuery));

    ifstream inFile("data/ordersFile.csv");
    if (!inFile) {
        cout << "Error opening orders file!" << endl;
        return;
    }

    string line;
    bool found = false;

    // Variables to hold order details
    string customerName, orderDate, orderLine;
    string totalPrice;

    // Loop through each line in the file to search for a matching order
    while (getline(inFile, line)) {
        stringstream ss(line);

        // Check if the line contains "name:" and extract the customer name
        if (line.find("name:") != string::npos) {
            size_t startPos = line.find("name:") + 5;


            size_t endPos = line.find("phone:");
            customerName = line.substr(startPos, endPos - startPos);
            customerName = Trim(customerName);
        }

        // Check if the line contains the date
        if (line.find("Date:") != string::npos) {
            size_t startPos = line.find("Date:") + 5;
            orderDate = line.substr(startPos);
            orderDate = Trim(orderDate);
        }

        // Extract the total price
        if (line.find("Total Price:") != string::npos) {
            size_t startPos = line.find("Total Price:") + 12;
            totalPrice = line.substr(startPos);
            totalPrice = Trim(totalPrice);
        }

        // When we find a match, print the order details
        if (convertionLowerCase(customerName) == lowerCaseSearchQuery || convertionLowerCase(orderDate) == lowerCaseSearchQuery) {
            // Order found, print the order details
            cout << "Order Found!\n";
            cout << "Date: (" << orderDate << "\n";
            cout << "Name: " << customerName << "\n";

            bool OrderhasPhoneNum = false;
            for (int i = 0; i < 5; i++) {
                if (customerFields[i] == "phone" || customerFields[i] == "Phone") {
                    OrderhasPhoneNum = true;
                    break;
                }
            }
            if (OrderhasPhoneNum == true) {
                cout << "Phone: " << line.substr(line.find("phone:") + 6) << "\n";  // Extract phone number after "phone:"
            }

            cout << "Products:\n";

            // Now print the products (we're assuming that the next lines contain product details)
            string productLine;
            while (getline(inFile, productLine)) {
                if (productLine.find("Total Price:") != string::npos) break; // stop when we reach the total price line
                cout << productLine << "\n"; // print each product detail
            }

            //  Fixed totalPrice access from in-memory orders
            for (int i = 0; i < orderCount; ++i) {
                if (orders[i]->customerInfo[0] == customerName && orders[i]->date == orderDate) {
                    cout << "Total Price: " << orders[i]->totalPrice << "\n";
                    break;
                }
            }

            found = true;
            break;
        }
    }

    // If no order was found, notify the user
    if (!found) {
        cout << "No matching order found.\n";
    }
}
