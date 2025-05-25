#include "../include/file_manager.h"
#include "../include/order_system.h"
#include "../include/getValidInt.h"
#include "../include/NameValidation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <iomanip>

using namespace std;

// Helper functions
string CSVFileManager::toLowerCase(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

string CSVFileManager::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

bool CSVFileManager::OrderHasPhoneNumber() const {
    const auto& fields = OrderSystem::getCustomerFields();
    return any_of(fields.begin(), fields.end(), [](const string& field) {
        return convertToLowerCase(field) == "phone";
    });
}

 //function used to delete orders
bool CSVFileManager::deleteOrder(const string& customerName) {

    cout << "using delete order in file manager "<<endl;


    ifstream inFile("data/ordersFile.csv");
    ofstream tempFile("data/temp.csv");
    
    if (!inFile || !tempFile) {
        throw runtime_error("Error opening files!");
    }

    string nameLower = toLowerCase(trim(customerName));
    string line;
    bool found = false;
    int linesToSkip = 0;
    const auto& fields = OrderSystem::getCustomerFields();

    while (getline(inFile, line)) {
        if (line.find("name:") != string::npos) {
            size_t start = line.find("name:") + 5;
            size_t end = line.find("phone:");
            string currentName = trim(line.substr(start, end - start));
            
            if (toLowerCase(currentName) == nameLower) {
                found = true;
                linesToSkip = fields.size() + 1; // fields + products + total
                continue;
            }
        }

        if (linesToSkip > 0) {
            linesToSkip--;
        } else {
            tempFile << line << "\n";
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        filesystem::remove("data/ordersFile.csv");
        filesystem::rename("data/temp.csv", "data/ordersFile.csv");
    }

    return found;
}

// the function used to display order
void CSVFileManager::displayOrders() {
    cout << "using the display order in csv file manager"<<endl;

    ifstream inputFile("data/ordersFile.csv");
    if (!inputFile) {
        throw runtime_error("Error opening orders file!");
    }

    string line, orderBuffer;
    while (getline(inputFile, line)) {
        if (line == "====================") {
            if (!orderBuffer.empty()) {
                cout << orderBuffer << "\n";
                orderBuffer.clear();
            }
        } else {
            orderBuffer += line + "\n";
        }
    }

    if (!orderBuffer.empty()) {
        cout << orderBuffer << "\n";
    }
}

// the function used to search order
void CSVFileManager::searchOrder() {

    cout << "using search order from file_manager "<<endl;

    string searchQuery;
    cout << "Enter customer name or date to search: ";
    getline(cin, searchQuery);

    string searchLower = toLowerCase(trim(searchQuery));
    ifstream inFile("data/ordersFile.csv");
    if (!inFile) {
        throw runtime_error("Error opening orders file!");
    }

    string line, customerName, orderDate;
    bool found = false;
    bool hasPhone = OrderHasPhoneNumber();

    while (getline(inFile, line)) {
        if (line.find("name:") != string::npos) {
            size_t start = line.find("name:") + 5;
            size_t end = line.find("phone:");
            customerName = trim(line.substr(start, end - start));
        } 
        else if (line.find("Date:") != string::npos) {
            orderDate = trim(line.substr(line.find("Date:") + 5));
        }

        if (toLowerCase(customerName) == searchLower || toLowerCase(orderDate) == searchLower) {
            cout << "\nOrder Found:\n";
            cout << "Date: " << orderDate << "\n";
            cout << "Name: " << customerName << "\n";
            
            if (hasPhone && line.find("phone:") != string::npos) {
                cout << "Phone: " << line.substr(line.find("phone:") + 6) << "\n";
            }

            cout << "Products:\n";
            string productLine;
            while (getline(inFile, productLine) && productLine.find("Total Price:") == string::npos) {
                cout << productLine << "\n";
            }
            cout << productLine << "\n"; // Print total price line
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching order found.\n";
    }
}

void CSVFileManager::printAllOrders() { // Implements the interface

    cout << "using print all order from file manager "<<endl;
    ifstream binaryFile("data/ordersFile.bin", ios::binary);
    if (!binaryFile) {
        throw runtime_error("Error opening binary orders file!");
    }

    int orderNum = 1;
    while (binaryFile.peek() != EOF) {
        string name, phone, date;
        unordered_map<string, int> products;
        double total;
        size_t length;

        // Read name
        binaryFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        name.resize(length);
        binaryFile.read(&name[0], length);

        // Read phone
        binaryFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        phone.resize(length);
        binaryFile.read(&phone[0], length);

        // Read date
        binaryFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        date.resize(length);
        binaryFile.read(&date[0], length);

        // Read products
        size_t productCount;
        binaryFile.read(reinterpret_cast<char*>(&productCount), sizeof(productCount));
        for (size_t i = 0; i < productCount; ++i) {
            string productName;
            int quantity;
            binaryFile.read(reinterpret_cast<char*>(&length), sizeof(length));
            productName.resize(length);
            binaryFile.read(&productName[0], length);
            binaryFile.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
            products[productName] = quantity;
        }

        // Read total
        binaryFile.read(reinterpret_cast<char*>(&total), sizeof(total));

        // Display order
        cout << "\nOrder #" << orderNum++ << " (Date: " << date << ")\n";
        cout << "Name: " << name << "\nPhone: " << phone << "\nProducts:\n";
        for (const auto& [name, qty] : products) {
            cout << "  " << name << ": " << qty << "\n";
        }
        cout << "Total: $" << fixed << setprecision(2) << total << "\n";
    }

    cout << "finished printing out order from file manager"<<endl;
}