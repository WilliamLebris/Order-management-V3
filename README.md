🧾 Order Management System
This is a C++  application for managing customer orders, product information, user accounts, and special products. It simulates a basic system for stores or restaurants to keep track of orders, validate input, and manage users securely.


**************************************************************************************
📁 Features
✅ Account Management: Create and log in as users with secure password validation.

🧍 Customer Info Fields: Choose up to 5 fields (e.g., Name, Phone, ID).

🛒 Product Setup: Add regular and special products with prices.

🧾 Order System: Add, view, print, and delete customer orders.

✔️ Input Validation: Ensures data is clean.

🔎 Unit Testing: Uses Google Test (gtest) to ensure code reliability.
***************************************************************************



🛠️ Technologies

STL (unordered_map, map, vector, memory)

Google Test for unit testing
****************************************************************** 


📦 Folder Structure
Order-Manager-2/ <br>
│<br>
├── src/                      # All .cpp files here<br>
│<br>
├── include/                  # All .hpp header files here<br>
│<br>
├── test/                     # All test files here<br>
│   └── test_orders.cpp<br>
│<br>
├── data/                     # CSV and binary files here<br>
│<br>
├── extern/                   # External dependencies (e.g., Google Test)<br>
│<br>
├── CMakeLists.txt            # CMake build configuration<br>
├── .gitignore                # Git ignore file<br>
├── README.md                 # Project readme<br>
├── LICENSE                   # Project license<br>
└── main.cpp                  # Main application entry point<br>
*************************************************************************



## New implementation <br>
----------------------------------------------------------------------------------------------------------<br>
Classes & Objects ::---->	            Order, Product, FileManager, etc.  	          Clean separation of concerns.<br>
                                    encapsulate data + behavior<br>
                                 (e.g., Order::setCustomerField()).<br>
<br>

Abstraction	  ::--->                 FileManager hides file operations behind   	  Users don’t need to know CSV/binary logic. <br>
                                 simple interfaces like printAllOrders().<br>
<br>

Encapsulation	   ::---->           Private members (e.g., Order::customerInfo) 	  Controlled access to data.<br>
                                 with public getters/setters.<br>
<br>
Inheritance	           ::---->         SpecialProduct : public Product .	          Base class defines common interface,<br>
                              (in product.h/cpp) overrides getType()             derived classes specialize.<br>

<br>
Polymorphism	      ::---->     Product::getType() behaves differently  	          Enables flexible, extensible code.<br>
                           for RegularProduct vs. SpecialProduct<br>
                           (runtime polymorphism). FileManager interface<br>
                           allows future extensions (interface polymorphism).<br>
<br>

Composition	            ::---->   Order contains a map<string, int> for products	  More flexible than inheritance for <br>
                              (has-a relationship) instead of inheriting.           this use case.<br>
<br>

Exceptions	                ::---->Custom exceptions (OrderException) thrown for     	Graceful error handling with clear semantics.<br>
                                 invalid states (e.g., negative prices <br>
                                    in OrderSystem::addProduct()).   <br>

🧠 Sample Use Case
Admin creates a user account.

Logs in and sets up customer fields like Name and Phone.

Adds products and their prices (e.g., Burger - $8.50).

Takes an order from a customer and stores it in a .csv file.
******************************************************************************



Prerequisites
Before you begin, make sure you have the following installed:

g++ (for compiling C++ code)

Google Test (for running unit tests)

CLion or another C++ IDE (optional, but recommended for ease of use)

CMake (if you later want to configure with CMake)
*************************************************************************


Steps to Build and Run
1. Clone the Repository
   Clone the project repository to your local machine:

--->      git clone https://github.com/WilliamLebris/Customizable-Order-Manager <br>
--->      cd Order-Manager <br>
--->      mkdir build <br>
--->      cd build <br>
--->      cmake .. <br>
--->      make <br>

To Run the project 
--->      ./Order_Manager_2 <br>

To run the Tests
--->      ./RunTests <br>

*************************************************************************


Short Video presentation : https://youtu.be/m1ACjsfLj1w

End Notes
Feel free to reach out if you encounter any issues or have questions!









