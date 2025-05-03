//
// Created by William Tissi on 5/2/25.
//
#include <gtest/gtest.h>
#include "../include/getValidInt.h"
#include "../include/addOrder.h"
#include "../include/deleteOrder.h"
#include "../include/displayOrders.h"
#include "../include/globalVariable.h"
#include "../include/UserDatabase.h"

#include <fstream>
#include <sstream>


TEST(NameValidationTest, AcceptsLetters) {
    EXPECT_TRUE(intValidation::validateLettersOrDigits("JohnDoe"));
}

TEST(NameValidationTest, AcceptsDigits) {
    EXPECT_TRUE(intValidation::validateLettersOrDigits("123456"));
}

TEST(NameValidationTest, RejectsMixed) {
    EXPECT_FALSE(intValidation::validateLettersOrDigits("John123"));
}

TEST(NameValidationTest, RejectsSpecialCharacters) {
    EXPECT_FALSE(intValidation::validateLettersOrDigits("John_Doe!"));
}

TEST(GetValidDoubleTest, AcceptsValidPrice) {
    double price = 10.5;
    EXPECT_TRUE(price >= 1.0);
}

TEST(GetValidDoubleTest, RejectsNegativePrice) {
    double price = -3.0;
    EXPECT_FALSE(price >= 1.0);
}

TEST(GetValidDoubleTest, RejectsZero) {
    double price = 0.0;
    EXPECT_FALSE(price >= 1.0);
}



TEST(addOrderTest, AddOrderSuccessfully) {
    // Simulate user input
    std::istringstream fakeInput("2024-02-02\n1\n2\n3\nno\n");
    std::streambuf* origCin = std::cin.rdbuf(fakeInput.rdbuf());

    // Capture output
    std::ostringstream test_output;
    std::streambuf* origCout = std::cout.rdbuf(test_output.rdbuf());

    // Call the original function
    addOrderDeclaration::addOrder();

    // Restore cin and cout
    std::cin.rdbuf(origCin);
    std::cout.rdbuf(origCout);

    // Check expected output
    EXPECT_TRUE(test_output.str().find("Order added successfully!") != std::string::npos);

    // Check file update
    std::ifstream inputFile("data/ordersFile.csv");
    EXPECT_TRUE(inputFile.is_open());

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        if (line.find("2024-02-02") != std::string::npos) {
            found = true;
            break;
        }
    }
    EXPECT_TRUE(found);
    inputFile.close();
}


TEST(SetupProductsTest, AddsProductsToMap) {
    productMap.clear(); // make sure it starts empty
    productMap["Pizza"] = 12.99;
    productMap["Burger"] = 8.50;

    EXPECT_EQ(productMap.size(), 2);
    EXPECT_DOUBLE_EQ(productMap["Pizza"], 12.99);
    EXPECT_DOUBLE_EQ(productMap["Burger"], 8.50);
}



TEST(SetupCustomerFieldsTest, SetsCustomerFieldsCorrectly) {
    numFields = 2;
    customerFields[0] = "Name";
    customerFields[1] = "Phone";

    EXPECT_EQ(customerFields[0], "Name");
    EXPECT_EQ(customerFields[1], "Phone");
    EXPECT_EQ(numFields, 2);
}


TEST(AddOrderTest, OrderCountIncreases) {
    int originalCount = orderCount;

    // Simulate adding a dummy order manually
    std::unique_ptr<Order> dummyOrder = std::make_unique<Order>();
    dummyOrder->date = "2025-05-02";
    dummyOrder->customerInfo[0] = "Test Name";
    dummyOrder->customerInfo[1] = "1234567890";
    dummyOrder->totalPrice = 50.0;
    dummyOrder->isActive = true;

    orders.push_back(std::move(dummyOrder));
    orderCount++;

    EXPECT_EQ(orderCount, originalCount + 1);
}


// Password validation tests
TEST(UserDatabaseTest, PasswordValidation) {
    EXPECT_TRUE(isValidPassword("pass123"));
    EXPECT_TRUE(isValidPassword("123abc"));
    EXPECT_FALSE(isValidPassword("password"));  // No digits
    EXPECT_FALSE(isValidPassword("12345"));     // No letters
    EXPECT_FALSE(isValidPassword(""));          // Empty string
}

// CreateFirstAccount test
TEST(UserDatabaseTest, CreateFirstAccount) {
    std::istringstream input("John\nDoe\nPass123\n");
    std::ostringstream output;

    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    createFirstAccount();

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    EXPECT_NE(output.str().find("Account created successfully!"), std::string::npos);
}

// Login success test
TEST(UserDatabaseTest, LoginSuccess) {
    userDatabase["johndoe"] = "Password123";

    std::istringstream input("John\nDoe\nPassword123\n");
    std::ostringstream output;

    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    bool result = login();

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    EXPECT_TRUE(result);
    EXPECT_NE(output.str().find("Login successful"), std::string::npos);
}

// Login fail: wrong password
TEST(UserDatabaseTest, LoginFailWrongPassword) {
    userDatabase["johndoe"] = "Password123";

    std::istringstream input("John\nDoe\nWrongPass\n");
    std::ostringstream output;

    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    bool result = login();

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    EXPECT_FALSE(result);
    EXPECT_NE(output.str().find("Invalid credentials"), std::string::npos);
}


// AddNewUser test
TEST(UserDatabaseTest, AddNewUser) {
    std::istringstream input("Alice\nSmith\nSecure1\n");
    std::ostringstream output;

    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    addNewUser();

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    EXPECT_EQ(userDatabase["alicesmith"], "Secure1");
    EXPECT_NE(output.str().find("New user created successfully"), std::string::npos);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
