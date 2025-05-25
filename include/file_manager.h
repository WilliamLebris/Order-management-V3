//
// Created by William Tissi on 5/23/25.
//

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


#include "order.h"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

class Order;
//implementing abstraction
//Users call printAllOrders() without knowing CSV/binary implementation

//Pure virtual function forces child classes to implement it
class FileManager {
public:
    virtual ~FileManager() = default;
    // virtual void saveOrder(const Order& order) = 0;
    virtual bool deleteOrder(const std::string& customerName) = 0;
    virtual void displayOrders() = 0;
    virtual void searchOrder() = 0;
    virtual void printAllOrders() = 0; // Abstracting interface, Pure virtual (interface)
};

class CSVFileManager : public FileManager {
public:
    //void saveOrder(const Order& order) override;
    bool deleteOrder(const std::string& customerName) override;
    void displayOrders() override;
    void searchOrder() override;
    void printAllOrders() override;

private:
    std::string toLowerCase(const std::string &str);
    std::string trim(const std::string &str);
    bool OrderHasPhoneNumber() const;
};


#endif //FILE_MANAGER_H