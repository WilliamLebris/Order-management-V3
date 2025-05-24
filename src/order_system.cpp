//
// Created by William Tissi on 5/1/25.
//
#include "../include/order_system.h"
#include "setupProducts.h"
#include "../include/product.h"
/*
using namespace std;
double totalRevenue = 0;


int numProducts = 0, numFields = 0, orderCount = 0;

map<string, double> productMap;

string customerFields[5];
vector<unique_ptr<Order> > orders; // now using unique pointer for my orders, Let'ss gooo
vector<shared_ptr<SpecialProduct> > specialProducts; // and share pointer for out special product, like a 500K wine
// order_system.cpp

*/
#include "../include/order_system.h"
#include "../include/order_system.h"
#include "../include/order.h"
#include "../include/menu.h"

#include "../include/product.h"
#include "../include/exception.h"
#include <map>
#include <vector>
#include <memory>
#include<iostream>


void OrderSystem::initialize() {
    // Initialize with default values if needed
    customerFields.reserve(MAX_CUSTOMER_FIELDS);
    orders.reserve(MAX_ORDERS);
}
void OrderSystem::run() {
    try {
        // Check if system is properly initialized
        if (!hasProducts()) {
            throw OrderException("No products configured - run setupProducts first");
        }
        if (!hasCustomerFields()) {
            throw OrderException("No customer fields configured - run setupCustomerFields first");
        }

        // Start the main menu
        menuDeclaration::menu();

    } catch (const OrderException& e) {
        std::cerr << "System Error: " << e.what() << std::endl;
        // You could add recovery logic here if needed
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
}

// Revenue methods
double OrderSystem::getTotalRevenue() {
    return totalRevenue;
}

void OrderSystem::addToRevenue(double amount) {
    if (amount < 0) {
        throw OrderException("Cannot add negative revenue");
    }
    totalRevenue += amount;
}

// Product methods
const std::map<std::string, double>& OrderSystem::getProductMap() {
    return productMap;
}

void OrderSystem::addProduct(const std::string& name, double price) {
    if (productMap.size() >= MAX_PRODUCTS) {
        throw OrderException("Maximum product limit reached");
    }
    if (price <= 0) {
        throw OrderException("Product price must be positive");
    }
    productMap[name] = price;
}

// Customer fields methods
const std::vector<std::string>& OrderSystem::getCustomerFields() {
    return customerFields;
}

void OrderSystem::setCustomerFields(const std::vector<std::string>& fields) {
    if (fields.size() > MAX_CUSTOMER_FIELDS) {
        throw OrderException("Exceeded maximum customer fields");
    }
    customerFields = fields;
}

// Order methods
const std::vector<std::unique_ptr<Order>>& OrderSystem::getOrders() {
    return orders;
}

void OrderSystem::addOrder(std::unique_ptr<Order> order) {
    if (orderCount >= MAX_ORDERS) {
        throw OrderException("Maximum order limit reached");
    }
    if (!order) {
        throw OrderException("Invalid order object");
    }
    orders.push_back(std::move(order));
    orderCount++;
}

bool OrderSystem::removeOrder(const std::string& customerName) {
    auto it = std::find_if(orders.begin(), orders.end(),
        [&](const std::unique_ptr<Order>& o) {
            return o->getCustomerInfo()[0] == customerName;
        });

    if (it != orders.end()) {
        orders.erase(it);
        orderCount--;
        return true;
    }
    return false;
}

// Special products methods
const std::vector<std::shared_ptr<Product>>& OrderSystem::getSpecialProducts() {
    return specialProducts;
}

void OrderSystem::addSpecialProduct(std::shared_ptr<Product> product) {
    if (!product) {
        throw OrderException("Invalid product object");
    }
    specialProducts.push_back(product);
}

// Helper methods
int OrderSystem::getOrderCount() {
    return orderCount;
}

bool OrderSystem::canAddMoreOrders() {
    return orderCount < MAX_ORDERS;
}

bool OrderSystem::hasProducts() {
    return !productMap.empty();
}

bool OrderSystem::hasCustomerFields() {
    return !customerFields.empty();
}