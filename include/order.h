#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <map>
#include <array>
#include <vector>

class Order {
private:
    std::array<std::string, 5> customerInfo;
    std::map<std::string, int> productQuantities;
    double totalPrice;
    std::string date;
    bool isActive;

public:
    Order(); // Default constructor

    // Setters
    void setCustomerInfo(const std::vector<std::string>& info);
    void setCustomerField(int index, const std::string& value);
    void addProduct(const std::string& name, int quantity);
    void setDate(const std::string& date);
    void setTotalPrice(double price);
    void setIsActive(bool active);

    // Getters
    const std::array<std::string, 5>& getCustomerInfo() const;
    const std::map<std::string, int>& getProductQuantities() const;
    const std::string& getDate() const;
    double getTotalPrice() const;
    bool getIsActive() const;
};

#endif