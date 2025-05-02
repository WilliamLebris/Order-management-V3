//
// Created by William Tissi on 5/1/25.
//

#include "../include/addOrder.h"
#include "../include/globalVariable.h"
#include <iomanip>
#include "../include/getValidInt.h"

#include <fstream> // Include for file writing
#include <filesystem> // Include for checking current directory

using namespace std;

void addOrderDeclaration::addOrder() {
    if (orderCount >= MAX_ORDERS) {
        cout << "Order limit reached! You may want to delete some really old orders.\n";
        return;
    }

    filesystem::create_directories("data"); // just in case it doesn't exist

    cout << "Enter order details:\n";
    unique_ptr<Order> newOrder = make_unique<Order>();

    for (int i = 0; i < numFields; i++) {
        cout << customerFields[i] << ": ";
        getline(cin, newOrder->customerInfo[i]);
    }

    do {
        cout << "Enter order date (YYYY-MM-DD): ";
        getline(cin, newOrder->date);
        if (!intValidation::isValidDate(newOrder->date)) {
            cout << "Invalid date format or range. Please try again.\n";
        }
    } while (!intValidation::isValidDate(newOrder->date));


    double total = 0;
    cout << "Enter product quantities:\n";
    newOrder->productQuantities.clear();

    for (const auto& product : productMap) {
        cout << product.first << " ($" << fixed << setprecision(2) << product.second << " each): ";
        int quantity = intValidation::getValidInt(0, 1000);
        newOrder->productQuantities[product.first] = quantity;
        total += quantity * product.second;
    }

    // Offer special products
    cout << "Would you like to see our special products? (yes/no): ";
    string choice;
    getline(cin, choice);

    if (choice == "yes" || choice == "Yes") {
        for (auto& special : specialProducts) {
            cout << "How many of \"" << special->name << "\" ($" << fixed << setprecision(2) << special->price << ") would you like? ";

            int qty = intValidation::getValidInt(0, 100);
            if (qty > 0) {
                newOrder->productQuantities[special->name] += qty;
                total += qty * special->price;
            }
        }
    }

    newOrder->totalPrice = total;
    newOrder->isActive = true;
    totalRevenue += total;

    Order* rawOrder = newOrder.get();
    int currentOrderIndex = orders.size();
    orders.push_back(std::move(newOrder));
    orderCount++;

    cout << "Order added successfully! Thanks!  Total due: $" << fixed << setprecision(2) << total << "\n";

    ofstream outputFile("data/ordersFile.csv", ios::app);
    if (outputFile.is_open()) {
        if (outputFile.tellp() == 0) {
            outputFile << "====================\n";
            outputFile << "List of all orders:\n";
        }

        outputFile << "Order #" << currentOrderIndex + 1 << " (Date: " << rawOrder->date << ")\n";
        for (int i = 0; i < numFields; i++) {
            outputFile << customerFields[i] << ": " << rawOrder->customerInfo[i] << "\n";
        }
        for (const auto& product : rawOrder->productQuantities) {
            outputFile << product.first << ": " << product.second << "\n";
        }
        outputFile << "Total Price: $" << fixed << setprecision(2) << rawOrder->totalPrice << "\n";
        outputFile << "-------------------------\n";
        outputFile.close();
    }

    ofstream binaryFile("data/ordersFile.bin", ios::binary | ios::app);
    if (binaryFile.is_open()) {
        size_t nameLength = rawOrder->customerInfo[0].size();
        binaryFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        binaryFile.write(rawOrder->customerInfo[0].c_str(), nameLength);

        size_t phoneLength = rawOrder->customerInfo[1].size();
        binaryFile.write(reinterpret_cast<char*>(&phoneLength), sizeof(phoneLength));
        binaryFile.write(rawOrder->customerInfo[1].c_str(), phoneLength);

        size_t dateLength = rawOrder->date.size();
        binaryFile.write(reinterpret_cast<char*>(&dateLength), sizeof(dateLength));
        binaryFile.write(rawOrder->date.c_str(), dateLength);

        size_t productCount = rawOrder->productQuantities.size();
        binaryFile.write(reinterpret_cast<char*>(&productCount), sizeof(productCount));
        for (const auto& product : rawOrder->productQuantities) {
            size_t productLength = product.first.size();
            binaryFile.write(reinterpret_cast<char*>(&productLength), sizeof(productLength));
            binaryFile.write(product.first.c_str(), productLength);
            binaryFile.write(reinterpret_cast<const char*>(&product.second), sizeof(product.second));
        }

        binaryFile.write(reinterpret_cast<char*>(&rawOrder->totalPrice), sizeof(rawOrder->totalPrice));
        binaryFile.close();
    }
}

