//
// Created by William Tissi on 5/1/25.
//

#include "../include/setupProducts.h"
#include "../include/getValidInt.h"
#include "../include/globalVariable.h"
#include "../include/getValidDouble.h"

using namespace std;
// Step 1: Setup Products and Prices
void setProductsDeclaration::setupProducts() {
    cout << "Enter the number of products you have (max " << MAX_PRODUCTS << "): ";
    numProducts = intValidation::getValidInt(1, MAX_PRODUCTS);

    for (int i = 0; i < numProducts; i++) {
        string productName;
        double productPrice;

        cout << "Enter product #" << i + 1 << ": ";
        getline(cin, productName);

        cout << "Enter price for " << productName << ": $";
        productPrice = doubleValidation::getValidDouble(0.01);

        productMap[productName] = productPrice;
    }

    // Ask for special products
    int numSpecial;
    cout << "Do you have special products (e.g., champagne, menu du jour)? How many? ";
    numSpecial = intValidation::getValidInt(0, 10);

    for (int i = 0; i < numSpecial; i++) {
        string specialName;
        double specialPrice;

        cout << "Enter special product #" << i + 1 << ": ";
        getline(cin, specialName);

        cout << "Enter price for " << specialName << ": $";
        specialPrice = doubleValidation::getValidDouble(0.01);

        // Create and assign values before pushing
        std::shared_ptr<SpecialProduct> specialItem = std::make_shared<SpecialProduct>();
        specialItem->name = specialName;
        specialItem->price = specialPrice;

        specialProducts.push_back(specialItem);
    }

}
