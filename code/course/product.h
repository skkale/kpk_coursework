#ifndef product_h
#define product_h
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    vector<Product> products;
    int productCounter = 0;

public:
    Product(int id, string name, double price) : id(id), name(name), price(price) {}
    
    Product();  // конструктор за замовчуванням
    ~Product(); // деструктор за замовчуванням
    
        // ініціалізація/оголошення
    void setID(int _id);
    void setNAME(string _name);
    void setPRICE(double _price);
    void fileRead();

    string getNAME(int findID);
    double getPRICE(int findID);
    void getProduct();
    
    void addProduct();
    void deleteProduct(int deleteID);
    void listProducts();

    void fileSave();
    
};

#endif // !product_h

