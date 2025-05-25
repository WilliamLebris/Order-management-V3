#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
//base class
class Product {
protected:
    std::string name;
    double price;

    //derived classes
public:
    Product(const std::string& productName, double productPrice);
    virtual ~Product() = default;
    
    virtual std::string getType() const = 0;
    std::string getName() const;
    double getPrice() const;
    void setPrice(double newPrice);
};


//inheritance
class RegularProduct : public Product {
public:
    RegularProduct(const std::string& name, double price);
    std::string getType() const override;
};

class SpecialProduct : public Product {
    //SpecialProduct inherit from product so we dont have to write every methods or property again
    //SpecialProduct extends Product with polymorphic behavior
    //Virtual function enables runtime polymorphism

public:
    SpecialProduct(const std::string &name, double price);

    std::string getType() const override;
};

#endif
