//
// Created by William Tissi on 5/1/25.
//

#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <map>
#include <stdio.h>
#include <iostream>
using namespace std;

extern double totalRevenue; // Store’s total earnings

const int MAX_ORDERS = 100; // Max orders
const int MAX_PRODUCTS = 10; // Max products

// Struct for Order with a map for product quantities
struct Order {
    string customerInfo[5]; // Customer details (Name, Phone, etc.)
    map<string, int> productQuantities; // Map of product names to quantities
    double totalPrice; // Total price of the order
    string date;
    bool isActive;
};

// Global variables
extern map<string, double> productMap; // Map of product name to price

extern string customerFields[5]; // Customer details required
extern int numProducts, numFields, orderCount;
extern vector<unique_ptr<Order>> orders;

// Special product struct
struct SpecialProduct {
    std::string name;
    double price;
};

// Declare shared pointer vector globally
extern std::vector<std::shared_ptr<SpecialProduct>> specialProducts;

#endif //GLOBALVARIABLE_H
