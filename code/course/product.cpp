#include "product.h"

Product::Product() {}

Product::~Product() {}
    
    // ��������� ������� (�� ���������������� ������ �� �� � ��� ���������� ������)
void Product::setID(int _id) { id = _id; }
void Product::setNAME(string _name) { name = _name; }
void Product::setPRICE(double _price) { price = _price; }

// ������������ ������� ����� � ����� �� ����� � ���������� ���'���
void Product::fileRead(){
    ifstream file("product.txt");
    if (!file.is_open()) {
        cerr << "File does not exist\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int firstSpace = line.find(' '); // ����� ������� ������ ��� ���������� ���
        int lastSpace = line.find_last_of(' '); // ����� ���������� ������ ��� ���������� ��'�
        
        int id = stoi(line.substr(0, firstSpace)); // �������� ������ �� ������� ������� �� ������� ������ �� ������������ �� �� int
        double price = stod(line.substr(lastSpace + 1)); // �������� ������ �� ���������� ������ �� ���� � ������������ �� �� double
        string name = line.substr(firstSpace + 1, lastSpace - firstSpace - 1); // ��������� ��'� �� ������� �� ���������� ������

        products.push_back(Product(id, name, price));
    }

        productCounter = 0;
    file.close();
}

    // ��������� ����� ���� ������� � ���������� ������
string Product::getNAME(int findID) {
    for (Product product : products) {
        if (product.id == findID) {
            return product.name;
        }
        else if (findID > products.size()) return "WRONG ELEMENT";
    }
}
double Product::getPRICE(int findID) {
    for (Product product : products) {
        if (product.id == findID) {
            return product.price;
        }
        else if (findID > products.size()) return 9999.9999;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��� ����� ������� ��� ���� ��� �������� ����� ����� ��� getline() ��������� ��������
    cout << "Enter product name: ";
    getline(cin, name);
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


