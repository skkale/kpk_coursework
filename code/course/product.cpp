#include "product.h"

Product::Product() {}

Product::~Product() {}
    
    // ��������� ������� (�� ���������������� ������ �� �� � ��� ���������� ������)
void Product::setID(int _id) { id = _id; }
void Product::setNAME(string _name) { name = _name; }
void Product::setPRICE(double _price) { price = _price; }

// ������� ����� � ����� �� ����� � ���������� ���'���
void Product::fileRead(){
    ifstream file("product.txt");
    if (!file.is_open()) { cerr << "File is not exist\n"; return; }
    while (file >> id >> name >> price) {
        products.push_back(Product(id, name, price));
    }
    productCounter = id;
    file.close();
}

    // ��������� ����� ���� ������� � ���������� ������
string Product::getNAME(int findID) {
    for (Product product : products) {
        if (product.id == findID) {
            return product.name;
        }
    }
}
double Product::getPRICE(int findID) {
    for (Product product : products) {
        if (product.id == findID) {
            return product.price;
        }
    }
}

// ���������� ���� ��� ������ �������
void Product::listProducts() {
    cout << "Product List:\n";
    for (Product product : products) {
        cout << "ID: " << product.id << ", Name: " << product.name << ", Price: " << product.price << "\n";
    }
}
// ���������� ���� ��� ������ �������� �� ��� � ������
void Product::getProduct() {
    int findID;
    cout << "Enter product ID:\n";
    cin >> findID;
    for (Product product : products) {
        if (product.id == findID) {
            cout << "ID: " << product.id << ", Name: " << product.name << ", Price: " << product.price << "\n";
        }
    }
}

void Product::addProduct() {
    string name;
    double price;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    products.push_back(Product(++productCounter, name, price));
    //ofstream file("product.txt");
    //if (!file.is_open()) { cerr << "File is not exist\n"; return; }
    //file << productCounter << " " << getNAME(productCounter) << " " << getPRICE(productCounter) << endl;
    //file.close();
    cout << "Product added successfully!\n";
}
void Product::deleteProduct(int deleteID) {
    if(deleteID-1 >= 0 && deleteID-1 < products.size()){
    products.erase(products.begin() + deleteID-1);
    }

}

// ����� ����� � ���������� ���'�� � ����
void Product::fileSave() {
    ofstream file("product.txt");
    if (!file.is_open()) { cerr << "File is not exist\n"; return; }
    for (Product product : products) {
    file << product.id << " " << product.name << " " << product.price << endl;
    }
    file.close();
}


