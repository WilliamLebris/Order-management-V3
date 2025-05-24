#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
protected:
    std::string name;
    double price;

public:
    Product(const std::string& productName, double productPrice);
    virtual ~Product() = default;
    
    virtual std::string getType() const = 0;
    std::string getName() const;
    double getPrice() const;
    void setPrice(double newPrice);
};

class RegularProduct : public Product {
public:
    RegularProduct(const std::string& name, double price);
    std::string getType() const override;
};

class SpecialProduct : public Product {
public:
    SpecialProduct(const std::string& name, double price);
    std::string getType() const override;
};

#endif