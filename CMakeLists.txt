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
        src/main.cpp)
