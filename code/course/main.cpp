#include <iostream>
#include <vector>
#include <Windows.h>
#include "product.h"
#include "order.h"
#include "customer.h"
#include "user.h"

using namespace std;

Product product;
Customer customer;
Order order;
User user;

class SalesManagerSystem {
private:

public:
    void showMenu() {
        int choice;
        do {
            cout << "\n1. Add Product\n";
            cout << "\n2. List Products\n";
            cout << "\n3. Add Customer\n";
            cout << "\n4. List Customers\n";
            cout << "\n5. Add Order\n";
            cout << "\n6. List Orders\n";
            cout << "\n7. Exit and Save\n";
            cout << "\n8. Delete Product\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                system("cls");
                product.addProduct();
                break;
            case 2:
                system("cls");
                product.listProducts();
                break;
            case 3:
                system("cls");
                customer.addCustomer();
                break;
            case 4:
                system("cls");
                customer.listCustomers();
                break;
            case 5:
                system("cls");
                order.addOrder();
                break;
            case 6:
                system("cls");
                order.listOrders();
                break;
            case 7:
                product.fileSave();
                customer.fileSave();
                order.fileSave();
                cout << "Exiting and Saving...\n";
                break;
            case 8:
                system("cls");
                int deleteID;
                cin >> deleteID;
                cout << product.getNAME(deleteID);
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        } while (choice != 7);
    }
};

SalesManagerSystem sms;

BOOL WINAPI ConsoleHandler(DWORD event){
    product.fileSave();
    customer.fileSave();
    order.fileSave();
    cout << "\n\nEMERGENCY SAVING\n\n";
    return true;
}

int main() {
    SetConsoleCtrlHandler(ConsoleHandler, TRUE); // обробка події на випадок екстренного закриття програм через графічний інтерфейс

    product.fileRead();
    customer.fileRead();
    order.fileRead();
    
    user.loggingIn();
    
    sms.showMenu();
    //cout << "END!";
    return 0;
}