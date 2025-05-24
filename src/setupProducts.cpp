//
// Created by William Tissi on 5/1/25.
//

#include "../include/setupProducts.h"
#include "../include/getValidInt.h"
#include "../include/order_system.h"
#include "../include/getValidDouble.h"
#include <memory>  // For std::unique_ptr and std::shared_ptr
#include <vector>  // For std::vector


using namespace std;
// Step 1: Setup Products and Prices
// setupProducts.cpp
void setProductsDeclaration::setupProducts() {
    cout << "Enter the number of products you have (max " << OrderSystem::MAX_PRODUCTS << "): ";
    int numProducts = intValidation::getValidInt(1, OrderSystem::MAX_PRODUCTS);

    for (int i = 0; i < numProducts; i++) {
        string productName;
        double productPrice;

        cout << "Enter product #" << i + 1 << ": ";
        getline(cin, productName);

        cout << "Enter price for " << productName << ": $";
        productPrice = doubleValidation::getValidDouble(0.01);

        OrderSystem::addProduct(productName, productPrice);
    }

    // Special products
    cout << "Do you have special products (e.g., champagne, menu du jour)? How many? ";
    int numSpecial = intValidation::getValidInt(0, 10);

    for (int i = 0; i < numSpecial; i++) {
        string specialName;
        double specialPrice;

        cout << "Enter special product #" << i + 1 << ": ";
        getline(cin, specialName);

        cout << "Enter price for " << specialName << ": $";
        specialPrice = doubleValidation::getValidDouble(0.01);

        OrderSystem::addSpecialProduct(make_shared<SpecialProduct>(specialName, specialPrice));
    }
}