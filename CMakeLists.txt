cmake_minimum_required(VERSION 3.31)
project(Order_Manager_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Order_Manager_2
        include/setupProducts.h
        include/setupCustomerFields.h
        include/addOrder.h
        include/displayOrders.h
        include/searchOrder.h
        include/deleteOrder.h
        include/menu.h
        include/getValidInt.h
        include/getValidDouble.h
        include/globalVariable.h
        include/UserDatabase.h
        include/NameValidation.h
        include/printStoreOrders.h
        src/setupProducts.cpp
        src/setupCustomerFields.cpp
        src/addOrder.cpp
        src/displayOrders.cpp
        src/searchOrder.cpp
        src/deleteOrder.cpp
        src/menu.cpp
        src/getValidInt.cpp
        src/getValidDouble.cpp
        src/globalVariable.cpp
        src/UserDatabase.cpp
        src/NameValidation.cpp
        main.cpp
        src/printStoreOrders.cpp
)

# ======================
# GoogleTest Integration

include(FetchContent)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RunTests
        test/test_orders.cpp
        src/getValidInt.cpp
)

target_link_libraries(RunTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(RunTests)
