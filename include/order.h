#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <map>
#include <array>
#include <vector>


// implementing classes and objects
class Order {
    // implementing encapsulation by Protecting data by restricting direct access.
private:
    std::array<std::string, 5> customerInfo;
    // composition by Building complex objects from simpler ones.
   // Order contains productQuantities rather than inheriting
    std::map<std::string, int> productQuantities; // Has-a relationship
    double totalPrice;
    std::string date;
    bool isActive;

public:
    Order(); // Default constructor

    // Setters
    void setCustomerInfo(const std::vector<std::string> &info);

    void setCustomerField(int index, const std::string &value);

    void addProduct(const std::string &name, int quantity);

    void setDate(const std::string &date);

    void setTotalPrice(double price);

    void setIsActive(bool active);

    // Getters
    const std::array<std::string, 5> &getCustomerInfo() const;

    const std::map<std::string, int> &getProductQuantities() const;

    const std::string &getDate() const;

    double getTotalPrice() const;

    bool getIsActive() const;
};

#endif

// the good thing is that :
//Data can't be modified without validation

//Getters/setters protect internal state