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

--->      git clone https://github.com/WilliamLebris/Customizable-Order-Manager
--->      cd Order-Manager
--->      mkdir build
--->      cd build
--->      cmake ..
--->      make

To Run the project 
--->      ./Order_Manager_2

To run the Tests
--->      ./RunTests

*************************************************************************


Short Video presentation : https://www.youtube.com/watch?v=B9a_C6RZtrk

End Notes
Feel free to reach out if you encounter any issues or have questions!









