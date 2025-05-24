#include "../include/deleteOrder.h"
#include "../include/file_manager.h"
#include "../include/order_system.h"
#include <iostream>

using namespace std;

void deleteOrderDeclaration::deleteOrder() {
    try {
        auto fileManager = make_unique<CSVFileManager>();
        cout << "Enter customer name to delete: ";
        string name;
        getline(cin, name);
        
        if (fileManager->deleteOrder(name)) {
            OrderSystem::removeOrder(name);
            cout << "Order deleted successfully.\n";
        } else {
            cout << "Order not found.\n";
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}