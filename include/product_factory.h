//
// Created by William Tissi on 5/23/25.
//

#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H




#include "product.hpp"
#include <memory>

class ProductFactory {
public:
    static std::shared_ptr<Product> createProduct(const std::string& type,
                                                const std::string& name,
                                                double price);
};

#endif