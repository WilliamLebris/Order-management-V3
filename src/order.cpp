#include "../include/order.h"
#include <stdexcept>
#include <iostream>

Order::Order() : totalPrice(0.0), isActive(true) {
    // Initialize all customer info fields to empty strings
    for (auto& field : customerInfo) {
        field = "";
    }
}

// Setters
void Order::setCustomerInfo(const std::vector<std::string>& info) {
    std::cout << "using set customer info in order.cpp"<<std::endl;
    if (info.size() != 5) {
        throw std::invalid_argument("Customer info must contain exactly 5 elements");
    }
    for (size_t i = 0; i < 5; ++i) {
        customerInfo[i] = info[i];
    }
}

// now that we have created some customer field, this is just adding some value to it such as the name of the customer
void Order::setCustomerField(int index, const std::string& value) {
    std::cout<< " using set customer field in order.cpp"<<std::endl;
    if (index >= 0 && index < 5) {
        customerInfo[index] = value;
    } else {
        throw std::out_of_range("Customer field index out of range");
    }
}

void Order::addProduct(const std::string& name, int quantity) {
    if (quantity > 0) {
        productQuantities[name] = quantity;
    }
}

void Order::setDate(const std::string& date) { this->date = date; }
void Order::setTotalPrice(double price) { totalPrice = price; }
void Order::setIsActive(bool active) { isActive = active; }

// Getters
const std::array<std::string, 5>& Order::getCustomerInfo() const { return customerInfo; }
const std::map<std::string, int>& Order::getProductQuantities() const { return productQuantities; }
const std::string& Order::getDate() const { return date; }
double Order::getTotalPrice() const { return totalPrice; }
bool Order::getIsActive() const { return isActive; }