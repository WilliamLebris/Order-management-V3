#include "../include/menu.h"
#include "../include/order_system.h"
#include "../include/file_manager.h"
#include "../include/UserDatabase.h"
#include "../include/getValidInt.h"
#include "../include/addOrder.h"  // Include addOrder functionality
#include <iostream>
#include <thread>
#include <memory>


using namespace std;

enum MenuOption {
    ADD_ORDER = 1,
    DISPLAY_ORDERS,
    SEARCH_ORDER,
    DELETE_ORDER,
    PRINT_STORE_ORDERS,
    ADD_USER,
    LOGIN_USER,
    EXIT_PROGRAM
};

void menuDeclaration::menu() {
    auto fileManager = make_unique<CSVFileManager>();
    int choice;
    int feedbackResponse;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Delete Order\n";
        cout << "5. Print all store orders\n";
        cout << "6. Add a new user\n";
        cout << "7. Log in\n";
        cout << "8. Exit\n";
        cout << "====================\n";
        cout << "Enter your choice: ";
        choice = intValidation::getValidInt(1, 8);

        switch (choice) {
            case ADD_ORDER:
                addOrderDeclaration::addOrder();
                break;

            case DISPLAY_ORDERS:
                fileManager->displayOrders();
                break;

            case SEARCH_ORDER:
                fileManager->searchOrder();
                break;

            case DELETE_ORDER: {
                string name;
                cout << "Enter customer name to delete: ";
                getline(cin, name);
                if (fileManager->deleteOrder(name)) {
                    cout << "Order deleted successfully.\n";
                } else {
                    cout << "Order not found.\n";
                }
                break;
            }

            case PRINT_STORE_ORDERS:
                fileManager->printAllOrders();
                break;

            case ADD_USER:
                UserDatabase::addNewUser();
                break;

            case LOGIN_USER:
                UserDatabase::login();
                break;

            case EXIT_PROGRAM:
                cout << "Exiting program...\n";
                cout << "Your experience is valuable\n";
                cout << "Do you mind giving feedback? (1=yes, 2=no): ";
                feedbackResponse = intValidation::getValidInt(1, 2);

                if (feedbackResponse == 1) {
                    thread feedbackThread([]() {
                        cout << "Rate the program (0-10): ";
                        int rating = intValidation::getValidInt(0, 10);
                        cout << "*** Thank you! ***\n";
                    });
                    feedbackThread.join();
                }
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != EXIT_PROGRAM);
}