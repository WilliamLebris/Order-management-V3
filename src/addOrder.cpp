#include "../include/addOrder.h"
#include "../include/order_system.h"
#include "../include/order.h"
#include "../include/product.h"
#include "../include/getValidInt.h"
#include <iomanip>
#include <memory>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace std;

namespace addOrderDeclaration {
    void addOrder() {
        try {
            if (!OrderSystem::canAddMoreOrders()) {
                throw runtime_error("Order limit reached! Delete old orders to add new ones.");
            }

            filesystem::create_directories("data");

            // Create new order
            auto newOrder = make_unique<Order>();
            const auto& customerFields = OrderSystem::getCustomerFields();

            // Get customer info
            for (size_t i = 0; i < customerFields.size() && i < 5; i++) {
                cout << customerFields[i] << ": ";
                string input;
                getline(cin, input);
                newOrder->setCustomerField(i, input);
            }

            // Validate date
            string date;
            do {
                cout << "Enter order date (YYYY-MM-DD): ";
                getline(cin, date);
            } while (!intValidation::isValidDate(date));
            newOrder->setDate(date);

            // Process products
            double total = 0;
            const auto& products = OrderSystem::getProductMap();

            for (const auto& [name, price] : products) {
                cout << name << " ($" << fixed << setprecision(2) << price << " each): ";
                int quantity = intValidation::getValidInt(0, 1000);
                if (quantity > 0) {
                    newOrder->addProduct(name, quantity);
                    total += quantity * price;
                }
            }

            // Process special products
            cout << "Would you like to see our special products? (yes/no): ";
            string choice;
            getline(cin, choice);

            if (choice == "yes" || choice == "Yes") {
                for (const auto& product : OrderSystem::getSpecialProducts()) {
                    cout << "How many of \"" << product->getName()
                         << "\" ($" << fixed << setprecision(2) << product->getPrice() << ")? ";
                    int qty = intValidation::getValidInt(0, 100);
                    if (qty > 0) {
                        newOrder->addProduct(product->getName(), qty);
                        total += qty * product->getPrice();
                    }
                }
            }

            // Finalize order
            newOrder->setTotalPrice(total);
            newOrder->setIsActive(true);

            // Save to files BEFORE moving the order
            saveOrderToFiles(*newOrder);

            // Add to OrderSystem (transfers ownership)
            OrderSystem::addOrder(std::move(newOrder));
            OrderSystem::addToRevenue(total);

            cout << "Order added successfully! Total due: $"
                 << fixed << setprecision(2) << total << "\n";

        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void saveOrderToFiles(const Order& order) {
        // CSV File Output
        ofstream outputFile("data/ordersFile.csv", ios::app);
        if (outputFile.is_open()) {
            if (outputFile.tellp() == 0) {
                outputFile << "====================\n";
                outputFile << "List of all orders:\n";
            }

            outputFile << "Order #" << OrderSystem::getOrderCount() + 1 << " (Date: " << order.getDate() << ")\n";

            const auto& customerInfo = order.getCustomerInfo();
            const auto& customerFields = OrderSystem::getCustomerFields();

            for (size_t i = 0; i < customerFields.size() && i < 5; i++) {
                outputFile << customerFields[i] << ": " << customerInfo[i] << "\n";
            }

            for (const auto& [product, quantity] : order.getProductQuantities()) {
                outputFile << product << ": " << quantity << "\n";
            }

            outputFile << "Total Price: $" << fixed << setprecision(2) << order.getTotalPrice() << "\n";
            outputFile << "-------------------------\n";
            outputFile.close();
        }

        // Binary File Output
        ofstream binaryFile("data/ordersFile.bin", ios::binary | ios::app);
        if (binaryFile.is_open()) {
            const auto& customerInfo = order.getCustomerInfo();

            // Write customer name
            size_t nameLength = customerInfo[0].size();
            binaryFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
            binaryFile.write(customerInfo[0].c_str(), nameLength);

            // Write phone (assuming it's the second field)
            size_t phoneLength = customerInfo[1].size();
            binaryFile.write(reinterpret_cast<char*>(&phoneLength), sizeof(phoneLength));
            binaryFile.write(customerInfo[1].c_str(), phoneLength);

            // Write date
            size_t dateLength = order.getDate().size();
            binaryFile.write(reinterpret_cast<char*>(&dateLength), sizeof(dateLength));
            binaryFile.write(order.getDate().c_str(), dateLength);

            // Write products
            const auto& products = order.getProductQuantities();
            size_t productCount = products.size();
            binaryFile.write(reinterpret_cast<char*>(&productCount), sizeof(productCount));

            for (const auto& [product, quantity] : products) {
                size_t productLength = product.size();
                binaryFile.write(reinterpret_cast<char*>(&productLength), sizeof(productLength));
                binaryFile.write(product.c_str(), productLength);
                binaryFile.write(reinterpret_cast<const char*>(&quantity), sizeof(quantity));
            }

            // Write total price
            double total = order.getTotalPrice();
            binaryFile.write(reinterpret_cast<char*>(&total), sizeof(total));
            binaryFile.close();
        }
    }
}