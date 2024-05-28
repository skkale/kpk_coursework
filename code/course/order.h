#ifndef order_h
#define order_h
#include "customer.h"
#include "product.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Order {
private:
    int id;
    int productId;
    int customerId;
    string status;
    vector<Order> orders;
    int orderCounter = 0;
    Customer customer;
    Product product;
public:
    Order(int id, int productId, int customerId, string status)
        : id(id), productId(productId), customerId(customerId), status(status) {}

    Order();
    ~Order();
    void setID(int _id);
    void setPRODUCTID(int _productId);
    void setCUSTOMERID(int _customerId);
    void setSTATUS(string _status);
   
    void fileRead();

    int getPRODUCTID(int findID);
    int getCUSTOMERID(int findID);
    string getSTATUS(int findID);
    void getOrder();

    void addOrder();
    void deleteOrder(int deleteID);
    void listOrders();

    void fileSave();
};

#endif // !order_h
