#include <gtest/gtest.h>
#include "../include/order_system.h"
#include "../include/order.h"
#include "../include/product.h"

TEST(OrderSystemTest, AddRegularProduct) {
    OrderSystem::initialize();
    OrderSystem::addProduct("Burger", 9.99);

    auto products = OrderSystem::getProductMap();
    ASSERT_EQ(products.size(), 1);
    EXPECT_EQ(products.at("Burger"), 9.99);
}

TEST(OrderSystemTest, AddSpecialProduct) {
    OrderSystem::initialize();
    auto special = std::make_shared<SpecialProduct>("Champagne", 49.99);
    OrderSystem::addSpecialProduct(special);

    auto specials = OrderSystem::getSpecialProducts();
    ASSERT_EQ(specials.size(), 1);
    EXPECT_EQ(specials[0]->getName(), "Champagne");
    EXPECT_EQ(specials[0]->getPrice(), 49.99);
    EXPECT_EQ(specials[0]->getType(), "Special");
}

TEST(OrderSystemTest, SetCustomerFields) {
    std::vector<std::string> fields = {"Name", "Phone", "Email"};
    OrderSystem::setCustomerFields(fields);

    auto resultFields = OrderSystem::getCustomerFields();
    ASSERT_EQ(resultFields.size(), 3);
    EXPECT_EQ(resultFields[0], "Name");
    EXPECT_EQ(resultFields[1], "Phone");
    EXPECT_EQ(resultFields[2], "Email");
}

TEST(OrderTest, SetCustomerInfo) {
    Order order;
    std::vector<std::string> info = {"Alice", "123456789", "alice@example.com", "123 Main St", "ID123"};

    order.setCustomerInfo(info);
    auto storedInfo = order.getCustomerInfo();

    EXPECT_EQ(storedInfo[0], "Alice");
    EXPECT_EQ(storedInfo[4], "ID123");
}

TEST(OrderTest, AddProductToOrder) {
    Order order;
    order.addProduct("Burger", 2);

    auto products = order.getProductQuantities();
    ASSERT_EQ(products.size(), 1);
    EXPECT_EQ(products["Burger"], 2);
}
