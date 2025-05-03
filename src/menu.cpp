//
// Created by William Tissi on 5/1/25.
//

// since we need to propose the menu at least once before the user say he doesn't want to see it anymore, I thought that using do while loop is the best fit because it does an action at least once before checkinng any conditon. And we also need to propose this menu to our user constanly to propose to the user our available feature

// I also created a feedback feature using ternary operator to be creative.
//goal 1: stand out of the from the crowd to be special


// since our menu function use others function, it is important to have their library (import).
//
// Created by William Tissi on 5/1/25.
//

#include "../include/menu.h"
#include "../include/addOrder.h"
#include "../include/displayOrders.h"
#include "../include/searchOrder.h"
#include "../include/deleteOrder.h"
#include "../include/getValidInt.h"
#include "../include/UserDatabase.h"
#include "../include/printStoreOrders.h"
#include <iostream>
#include <thread>

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
    int choice;
    int feedbackResponse;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Delete Order\n";
        cout << "5. Print all the orders since the store opened\n";
        cout << "6. Add a new user\n";
        cout << "7. Log in as another user\n";
        cout << "8. Exit\n";
        cout << "====================\n";
        cout << "Enter your choice: ";
        choice = intValidation::getValidInt(1, 8);

        switch (choice) {
            case ADD_ORDER: addOrderDeclaration::addOrder(); break;
            case DISPLAY_ORDERS: displayOrderDeclaration::displayOrders(); break;
            case SEARCH_ORDER: searchOrderDeclaration::searchOrder(); break;
            case DELETE_ORDER: deleteOrderDeclaration::deleteOrder(); break;
            case PRINT_STORE_ORDERS: readAllOrdersFromBinary(); break;
            case ADD_USER: addNewUser(); break;
            case LOGIN_USER: login(); break;
            case EXIT_PROGRAM:
                cout << "Exiting program...\n" << endl;
                cout << "Your experience is valuable\n";
                cout << "Do you mind giving us some feedback about your experience with this program?\n";
                cout << "Enter 1 for yes or 2 for no\n";
                feedbackResponse = intValidation::getValidInt(1, 2);

                if (feedbackResponse == 1) {
                    std::thread feedbackThread([]() {
                        cout << "How would you rate the program on a scale of 0 to 10\n";
                        int rateExperience = intValidation::getValidInt(0, 10);
                        cout << "***    Thank you !!!    ***\n" << endl;
                    });
                    feedbackThread.join();
                } else {
                    cout << "Okay !!\n";
                }
                break;
        }
    } while (choice != EXIT_PROGRAM);
}
