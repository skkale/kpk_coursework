#include "order.h"

Order::Order() {};
Order::~Order() {};

void Order::setID(int _id) { id = _id; }
void Order::setPRODUCTID(int _productId) { productId = _productId; }
void Order::setCUSTOMERID(int _customerId) { customerId = _customerId; }
void Order::setSTATUS(string _status) { status = _status; }

void Order::fileRead() {
    ifstream file("order.txt");
    if (!file.is_open()) {
        cerr << "File does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int firstSpace = line.find(' ');
        int secondSpace = line.find(' ', firstSpace + 1); // пошук другого пробілу
        size_t thirdSpace = line.find(' ', secondSpace + 1); // пошук третього пробілу
        int lastSpace = line.find_last_of(' ');

        int id = stoi(line.substr(0, firstSpace));
        int productId = stoi(line.substr(firstSpace + 1, secondSpace - firstSpace - 1));
        int customerId = stoi(line.substr(secondSpace + 1, thirdSpace - secondSpace - 1));
        string status = line.substr(thirdSpace + 1);

        orders.push_back(Order(id, productId, customerId, status));
    }

    orderCounter = 0;
    file.close();
}

int Order::getPRODUCTID(int findID) {
    for (Order order : orders) {
        if (order.id == findID) {
            return order.productId;
        }
        else if (findID > orders.size()) return 9999;
    }
}
int Order::getCUSTOMERID(int findID){
    for (Order order : orders) {
        if (order.id == findID) {
            return order.customerId;
        }
        else if (findID > orders.size()) return 9999;
    }
}
string Order::getSTATUS(int findID){
    for (Order order : orders) {
        if (order.id == findID) {
            return order.status;
        }
        else if (findID > orders.size()) return "WRONG ELEMENT";
    }
}
void Order::getOrder() {
    int findID;
    cout << "Enter order ID:\n";
    cin >> findID;
    for (Order order : orders) {
        if (order.id == findID) {
            cout << "ID: " << order.id << ", Product ID: " << order.productId 
                << ", Customer ID: " << order.customerId << "Status:" << order.status<< "\n";
        }
    }
}

void Order::addOrder() {
    int productId, customerId;
    string status;
    cout << "Enter product ID: ";
    cin >> productId;
    cout << "Enter customer ID: ";
    cin >> customerId;
    cout << "Enter order status: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, status);
    orders.push_back(Order(++orderCounter, productId, customerId, status));
    cout <<"Order added successfully!\n";
}

void Order::deleteOrder(int deleteID) {
    if (deleteID - 1 >= 0 && deleteID - 1 < orders.size()) {
        orders.erase(orders.begin() + deleteID - 1);
    }

}

void Order::listOrders() {
    cout << "Order List:\n";
    for (Order order : orders) {
        cout << "ID: " << order.id << ", Product ID: " << order.productId
            << ", Customer ID: " << order.customerId << ", Status: " << order.status << "\n";
    }
}

void Order::fileSave() {
    ofstream file("order.txt");
    if (!file.is_open()) { cerr << "File is not exist\n"; return; }
    for (Order order : orders) {
        file << order.id << " " << order.productId << " " << order.customerId << " " << order.status << endl;
    }
    file.close();
}