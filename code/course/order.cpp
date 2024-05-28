#include "order.h"

Order::Order() {};
Order::~Order() {};

void Order::addOrder() {
    int productId, customerId;
    string status;
    cout << "Enter product ID: ";
    cin >> productId;
    cout << "Enter customer ID: ";
    cin >> customerId;
    cout << "Enter order status: ";
    cin >> status;
    orders.push_back(Order(++orderCounter, productId, customerId, status));
    cout << "Order added successfully!\n";
}

void Order::listOrders() {
    cout << "Order List:\n";
    for (Order order : orders) {
        cout << "ID: " << order.id << ", Product ID: " << order.productId
            << ", Customer ID: " << order.customerId << ", Status: " << order.status << "\n";
    }
}