#include "customer.h"

Customer::Customer() {};

Customer::~Customer() {};

void Customer::addCustomer() {
    string name, email;
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter customer email: ";
    cin >> email;
    customers.push_back(Customer(++customerCounter, name, email));
    cout << "Customer added successfully!\n";
}

void Customer::listCustomers() {
    cout << "Customer List:\n";
    for (Customer customer : customers) {
        cout << "ID: " << customer.id << ", Name: " << customer.name << ", Email: " << customer.email << "\n";
    }
}