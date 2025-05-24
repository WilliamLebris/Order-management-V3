//
// Created by William Tissi on 5/1/25.
//

#ifndef ORDER_SYSTEM_H
#define ORDER_SYSTEM_H

#include "order.h"
#include "product.h"
#include <map>
#include <vector>
#include <memory>

class OrderSystem {
private:
    static inline double totalRevenue = 0.0;
    static inline std::map<std::string, double> productMap;
    static inline std::vector<std::string> customerFields;
    static inline std::vector<std::unique_ptr<Order>> orders;
    static inline std::vector<std::shared_ptr<Product>> specialProducts;
    static inline int orderCount = 0;




public:
    static constexpr int MAX_ORDERS = 100;
    static constexpr int MAX_PRODUCTS = 10;
    static constexpr int MAX_CUSTOMER_FIELDS = 5;
    // Initialization
    static void initialize();
    static void run();

    // Revenue methods
    static double getTotalRevenue();
    static void addToRevenue(double amount);

    // Product methods
    static const std::map<std::string, double>& getProductMap();
    static void addProduct(const std::string& name, double price);

    // Customer fields
    static const std::vector<std::string>& getCustomerFields();
    static void setCustomerFields(const std::vector<std::string>& fields);

    // Order methods
    static const std::vector<std::unique_ptr<Order>>& getOrders();
    static void addOrder(std::unique_ptr<Order> order);
    static bool removeOrder(const std::string& customerName);  // Added declaration

    // Special products
    static const std::vector<std::shared_ptr<Product>>& getSpecialProducts();
    static void addSpecialProduct(std::shared_ptr<Product> product);

    // Helper methods
    static int getOrderCount();
    static bool canAddMoreOrders();
    static bool hasProducts();          // Added declaration
    static bool hasCustomerFields();    // Added declaration
};

#endif // ORDER_SYSTEM_H