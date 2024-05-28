#include "customer.h"

Customer::Customer() {};

Customer::~Customer() {};

void Customer::setID(int _id) { id = _id; }
void Customer::setNAME(string _name) { name = _name; }
void Customer::setEMAIL(string _email) { email = _email; }

void Customer::fileRead() {
    ifstream file("customer.txt");
    if (!file.is_open()) {
        cerr << "File does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int firstSpace = line.find(' ');
        int lastSpace = line.find_last_of(' ');

        int id = stoi(line.substr(0, firstSpace));  
        string name = line.substr(firstSpace + 1, lastSpace - firstSpace - 1);
        string email = line.substr(lastSpace + 1);

        customers.push_back(Customer(id, name, email));
    }

    customerCounter = 0;
    file.close();
}

string Customer::getNAME(int findID) {
    for (Customer customer : customers) {
        if (customer.id == findID) {
            return customer.name;
        }
        else if (findID > customers.size()) return "WRONG ELEMENT";
    }
}
string Customer::getEMAIL(int findID) {
    for (Customer customer : customers) {
        if (customer.id == findID) {
            return customer.email;
        }
        else if (findID > customers.size()) return "WRONG ELEMENT";
    }
}

void Customer::addCustomer() {
    string name, email;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter customer email: ";
    getline(cin, email);
    customers.push_back(Customer(++customerCounter, name, email));
    cout << "Customer added successfully!\n";
}

void Customer::deleteCustomer(int deleteID) {
    if (deleteID - 1 >= 0 && deleteID - 1 < customers.size()) {
        customers.erase(customers.begin() + deleteID - 1);
    }

}

void Customer::listCustomers() {
    cout << "Customer List:\n";
    for (Customer customer : customers) {
        cout << "ID: " << customer.id << ", Name: " << customer.name << ", Email: " << customer.email << "\n";
    }
}

void Customer::getCustomer() {
        int findID;
        cout << "Enter customer ID:\n";
        cin >> findID;
        for (Customer customer : customers) {
            if (customer.id == findID) {
                cout << "ID: " << customer.id << ", Name: " << customer.name << ", Price: " << customer.email << "\n";
            }
        }
    }

void Customer::fileSave() {
    ofstream file("customer.txt");
    if (!file.is_open()) { cerr << "File is not exist\n"; return; }
    for (Customer customer : customers) {
        file << customer.id << " " << customer.name << " " << customer.email << endl;
    }
    file.close();
}


