#include "order_system.h"
#include "../include/UserDatabase.h"
#include "include/setupProducts.h"
#include "include/setupCustomerFields.h"
#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
    try {
        // Fancy welcome message
        srand(time(0));
        int numChars = 53 + (rand() % 2);
        std::cout << std::setfill('*') << std::setw(numChars) << "" << std::endl << std::endl;
        std::cout << "* Welcome to the Customizable Order Management System! *\n" << std::endl;
        std::cout << std::setfill('*') << std::setw(numChars) << "" << std::endl << std::endl;

        // Initialize system
        OrderSystem::initialize();

        /*
        // User authentication
        if (!UserDatabase::isInitialized()) {
            std::cout << "=== CREATE ADMIN ACCOUNT ===\n";
            UserDatabase::createFirstAccount();
        }

        while (!UserDatabase::login()) {
            std::cout << "Login failed. Try again.\n";
        }
*/
        // First-time setup
        if (!OrderSystem::hasProducts()) {
            std::cout << "\n=== PRODUCT SETUP ===\n";
            setProductsDeclaration::setupProducts();
        }

        if (!OrderSystem::hasCustomerFields()) {
            std::cout << "\n=== CUSTOMER FIELDS SETUP ===\n";
            setCustomerDeclaration::setupCustomerFields();
        }

        // Main program loop
        OrderSystem::run();

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}