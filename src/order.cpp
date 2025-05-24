#include "../include/order.h"
#include <stdexcept>

Order::Order() : totalPrice(0.0), isActive(true) {
    // Initialize all customer info fields to empty strings
    for (auto& field : customerInfo) {
        field = "";
    }
}

// Setters
void Order::setCustomerInfo(const std::vector<std::string>& info) {
    if (info.size() != 5) {
        throw std::invalid_argument("Customer info must contain exactly 5 elements");
    }
    for (size_t i = 0; i < 5; ++i) {
        customerInfo[i] = info[i];
    }
}

void Order::setCustomerField(int index, const std::string& value) {
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