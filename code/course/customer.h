#ifndef customer_h
#define customer_h
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    int id;
    string name;
    string email;
    vector<Customer> customers;
    int customerCounter = 0;
public:
    Customer(int id, string name, string email) : id(id), name(name), email(email) {}
    
    Customer();
    ~Customer();

    void addCustomer();

    void listCustomers();
};
#endif // !customer_h
