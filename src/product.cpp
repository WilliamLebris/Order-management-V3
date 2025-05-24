//
// Created by William Tissi on 5/23/25.
//
#include "../include/product.h"

// Base Product class
Product::Product(const std::string& productName, double productPrice)
    : name(productName), price(productPrice) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double newPrice) {
    if (newPrice <= 0) {
        throw std::invalid_argument("Price must be positive");
    }
    price = newPrice;
}

// RegularProduct implementation
RegularProduct::RegularProduct(const std::string& name, double price)
    : Product(name, price) {}

std::string RegularProduct::getType() const {
    return "Regular";
}

// SpecialProduct implementation
SpecialProduct::SpecialProduct(const std::string& name, double price)
    : Product(name, price) {}

std::string SpecialProduct::getType() const {
    return "Special";
}