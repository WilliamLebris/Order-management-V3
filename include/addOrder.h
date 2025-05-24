//
// Created by William Tissi on 5/1/25.
//

#include"order.h"
#ifndef ADDORDER_H
#define ADDORDER_H

namespace addOrderDeclaration {
    /**
     * @brief Adds a new order to the system
     *
     * Guides the user through the order creation process including:
     * - Customer information collection
     * - Product selection and quantities
     * - Special products
     * - Order validation and saving
     */
    void addOrder();

    /**
     * @brief Saves order data to both CSV and binary files
     *
     * @param order The order to be saved
     *
     * Creates/updates two files:
     * 1. ordersFile.csv - Human-readable order log
     * 2. ordersFile.bin - Binary order data for persistence
     */
    void saveOrderToFiles(const Order& order);
}
#endif