//
// Created by William Tissi on 5/1/25.
//

// since we need to propose the menu at least once before the user say he doesn't want to see it anymore, I thought that using do while loop is the best fit because it does an action at least once before checkinng any conditon. And we also need to propose this menu to our user constanly to propose to the user our available feature

// I also created a feedback feature using ternary operator to be creative.
//goal 1: stand out of the from the crowd to be special


// since our menu function use others function, it is important to have their library (import).
#include "../include/menu.h"
#include "../include/addOrder.h"
#include "../include/displayOrders.h"
#include "../include/searchOrder.h"
#include "../include/deleteOrder.h"

#include "../include/getValidInt.h"
#include "../include/UserDatabase.h"
#include "../include/printStoreOrders.h"
#include <iostream>
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
    int rateExperience;
    do {

        // proposing different options that my program have
        cout << "\n===== MENU =====\n";
        cout << "1. Add Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Delete Order\n";
        cout << "5. Print all the orders since the store opened"<<endl;
        cout << "6. Add a new user"<<endl;
        cout << "7. Log in as another users"<<endl;
        cout << "8. Exit\n";
        cout<< "====================\n";
        cout << "Enter your choice: ";
        choice = intValidation::getValidInt(1, 8);  // make sure the user doesn't try to crash the program

        // depending on the answer, execute a case
        switch (choice) {
            case ADD_ORDER: addOrderDeclaration::addOrder(); break;
            case DISPLAY_ORDERS: displayOrderDeclaration::displayOrders(); break;
            case SEARCH_ORDER: searchOrderDeclaration::searchOrder(); break;
            case DELETE_ORDER: deleteOrderDeclaration::deleteOrder(); break;
            case PRINT_STORE_ORDERS: readAllOrdersFromBinary(); break;
            case ADD_USER: addNewUser(); break;
            case LOGIN_USER: login(); break;
            case EXIT_PROGRAM:
                // feedback feature
                cout << "Exiting program...\n"<<endl;
                cout << "Your experience is valuable"<<endl;
                cout << "Do you mind giving us some feedback about your experience with this program?"<<endl;
                cout << "Enter 1 for yes or 2 for no"<<endl;
                feedbackResponse = intValidation::getValidInt(1, 2);
                //now using ternary operator to have some feedback in case the user want to leave feedback

                (feedbackResponse == 1)
                    ? (cout << "How would you rate the program on a scale of 0 to 10\n",
                       rateExperience = intValidation::getValidInt(0, 10),
                       cout << "***    Thank you !!!    ***\n"<<endl)
                    : cout << "Okay !!\n";

                break;
        }
    } while (choice != EXIT_PROGRAM);
}
