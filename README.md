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
Order-Manager-2/
│
├── src/                      # All .cpp files here
│
├── include/                  # All .hpp header files here
│
├── test/                     # All test files here
│   └── test_orders.cpp
│
├── data/                     # CSV and binary files here
│
├── extern/                   # External dependencies (e.g., Google Test)
│
├── CMakeLists.txt            # CMake build configuration
├── .gitignore                # Git ignore file
├── README.md                 # Project readme
├── LICENSE                   # Project license
└── main.cpp                  # Main application entry point
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

"->" git clone https://github.com/yourusername/Order-Manager-2.git
cd Order-Manager-2

2. Compile the Project Using g++
   Run the following command to compile the project using g++:

"->" g++ -std=c++17 -Iinclude -Iextern/googletest/googletest/include -Iextern/googletest/googletest \
test/test_orders.cpp src/*.cpp \
extern/googletest/build/lib/libgtest.a extern/googletest/build/lib/libgtest_main.a \
-pthread -o test_runner


This command compiles the test files (test/test_orders.cpp), source files (src/*.cpp), and links them with Google Test libraries.

3. Run the Test Runner
   After compilation, you can run the tests with the following command:

"->" ./test_runner


This will execute the tests and output the results to your terminal.
*************************************************************************



CMake Setup (Optional for Future Setup)
If you'd like to use CMake for easier build management, follow these steps:

Create a build directory:


"->" mkdir build
"->" cd build
Configure the project:

"->" cmake ..
Build the project:

"->" make
Run the tests:

"->" ./test_runner
*************************************************************************

End Notes
Feel free to reach out if you encounter any issues or have questions!









