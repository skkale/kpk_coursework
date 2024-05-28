#ifndef customer_h
#define customer_h
#include <vector>
#include <fstream>
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
    
    void setID(int _id);
    void setNAME(string _name);
    void setEMAIL(string _email);
    void fileRead();

    string getNAME(int findID);
    string getEMAIL(int findID);
    void getCustomer();

    void addCustomer();
    void deleteCustomer(int deleteID);

    void listCustomers();
    
    void fileSave();
};
#endif // !customer_h
