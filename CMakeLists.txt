cmake_minimum_required(VERSION 3.31)
project(Order_Manager_2)

set(CMAKE_CXX_STANDARD 20)

# Include directory
include_directories(include)

# GoogleTest Integration - SIMPLIFIED VERSION
find_package(GTest REQUIRED)

enable_testing()

# Main library
add_library(OrderManagerLib
        src/setupProducts.cpp
        src/setupCustomerFields.cpp
        src/addOrder.cpp
        src/menu.cpp
        src/getValidInt.cpp
        src/getValidDouble.cpp
        src/order_system.cpp
        src/UserDatabase.cpp
        src/NameValidation.cpp
        src/order.cpp
        src/file_manager.cpp
        src/product.cpp
)

# Main executable
add_executable(Order_Manager_2 main.cpp)
target_link_libraries(Order_Manager_2 OrderManagerLib)

# Unit Tests
add_executable(RunTests test/test_orders.cpp)
target_link_libraries(RunTests
        OrderManagerLib
        GTest::gtest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(RunTests)