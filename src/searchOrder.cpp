#include "../include/searchOrder.h"
#include "../include/order_system.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string toLowerCase(const string &str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

string trim(const string &str) {
    auto first = str.find_first_not_of(' ');
    auto last = str.find_last_not_of(' ');
    return (first == string::npos) ? "" : str.substr(first, (last - first + 1));
}

void searchOrderDeclaration::searchOrder() {
    cout << "Enter customer name or date to search: ";
    string query;
    getline(cin, query);
    string searchTerm = toLowerCase(trim(query));

    ifstream inFile("data/ordersFile.csv");
    if (!inFile) {
        throw runtime_error("Could not open orders file");
    }

    bool found = false;
    string line, customerName, orderDate;

    while (getline(inFile, line)) {
        if (line.find("name:") != string::npos) {
            size_t start = line.find("name:") + 5;
            size_t end = line.find("phone:");
            customerName = trim(line.substr(start, end - start));
        } 
        else if (line.find("Date:") != string::npos) {
            orderDate = trim(line.substr(line.find("Date:") + 5));
        }

        if (toLowerCase(customerName) == searchTerm || toLowerCase(orderDate) == searchTerm) {
            cout << "\nOrder Found:\n";
            cout << "Date: " << orderDate << "\n";
            cout << "Name: " << customerName << "\n";

            // Check for phone field
            const auto& fields = OrderSystem::getCustomerFields();
            bool hasPhone = any_of(fields.begin(), fields.end(), [](const string& f) {
                return toLowerCase(f) == "phone";
            });

            if (hasPhone && line.find("phone:") != string::npos) {
                cout << "Phone: " << line.substr(line.find("phone:") + 6) << "\n";
            }

            // Print products
            cout << "Products:\n";
            string productLine;
            while (getline(inFile, productLine) && 
                  productLine.find("Total Price:") == string::npos) {
                cout << productLine << "\n";
            }
            cout << productLine << "\n"; // Print total price
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching order found.\n";
    }
}