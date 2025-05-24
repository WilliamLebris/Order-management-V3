//
// Created by William Tissi on 5/1/25.
//
#include "../include/order_system.h"
#include "setupProducts.h"
#include "../include/product.h"

#include "../include/order_system.h"
#include "../include/order_system.h"
#include "../include/order.h"
#include "../include/menu.h"

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

// this is called once we finished setting up the customer field and set up product, it is just to make sure that
//we didnt bypass the code, so before displaying the menu, we make sure that we have products and customer field set up
void OrderSystem::run() {
    std::cout << "using run in order_system..." << std::endl;
    try {
        // Check if system is properly initialized
        if (!hasProducts()) {
            throw OrderException("No products configured - run setupProducts first");
        }
        if (!hasCustomerFields()) {
            throw OrderException("No customer fields configured - run setupCustomerFields first");
        }

        // calling the main menu now
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
    std::cout<< "using add product in order_system"<<std::endl;

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

// just use to save the customer field  (called by setup customer field .cpp after retrieving the field
void OrderSystem::setCustomerFields(const std::vector<std::string>& fields) {
    std::cout <<"using set customer field in order_system"<<std::endl;

    if (fields.size() > MAX_CUSTOMER_FIELDS) {
        throw OrderException("Exceeded maximum customer fields");
    }
    customerFields = fields;
}

// Order methods
const std::vector<std::unique_ptr<Order>>& OrderSystem::getOrders() {
    return orders;
}

// so addorder.cpp succesfully created the order now call this add order below to make sure we are not out of range
//then move the ownership and save the order into a vector
void OrderSystem::addOrder(std::unique_ptr<Order> order) {
    std::cout<< "using add order in order_system"<<std::endl;
    if (orderCount >= MAX_ORDERS) {
        throw OrderException("Maximum order limit reached");
    }
    if (!order) {
        throw OrderException("Invalid order object");
    }
    orders.push_back(std::move(order));
    orderCount++;
}


// Special products methods
const std::vector<std::shared_ptr<Product>>& OrderSystem::getSpecialProducts() {
    return specialProducts;
}

// once we set up the special product in SetupProduct.cpp, this is being called to save it into the shared pointer vector
void OrderSystem::addSpecialProduct(std::shared_ptr<Product> product) {
    std::cout << "using add special product in order_system"<<std::endl;


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
