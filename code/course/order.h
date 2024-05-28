#ifndef order_h
#define order_h
#include <vector>
#include <iostream>
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
public:
    Order(int id, int productId, int customerId, string status)
        : id(id), productId(productId), customerId(customerId), status(status) {}

    Order();
    ~Order();

    void addOrder();
    void listOrders();

};

#endif // !order_h
