//
// Created by William Tissi on 5/2/25.
//
#include"../include/printStoreOrders.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include"../include/addOrder.h"
using namespace std;

// now here is where we read form the binary file, since the binary file contains all of the store's orders, we just print them
void readAllOrdersFromBinary() {
    ifstream binaryFile("data/ordersFile.bin", ios::binary);

    // check if opening
    if (!binaryFile.is_open()) {
        cout << "No binary file found or failed to open.\n";
        return;
    }

    int orderNumber = 1;
    // as long as we are not at the end of the file, ...
    while (binaryFile.peek() != EOF) {
        //now since we are going to read from the file, we have to save it somewhere before priting out from that place

        string name, phone, date;

        unordered_map<string, int> productQuantities;
        double totalPrice;

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
            productQuantities[productName] = quantity;
        }

        // Read total price
        binaryFile.read(reinterpret_cast<char*>(&totalPrice), sizeof(totalPrice));

        // Display the order
        cout << "\nOrder #" << orderNumber++ << " (Date: " << date << ")\n";
        cout << "Name: " << name << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "Products:\n";

        for (const auto& item : productQuantities) {
            cout << "  " << item.first << ": " << item.second << "\n";
        }

        cout << "Total: $" << fixed << setprecision(2) << totalPrice << "\n";
        cout << "-------------------------\n";
    }

    binaryFile.close();
}
