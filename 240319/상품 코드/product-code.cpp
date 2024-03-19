#include <iostream>

using namespace std;

class Product{
    public:
    string name;
    int code;
    Product(){
        name = "codetree";
        code = 50;
    }
    Product(string name, int code){
        this->name = name;
        this->code = code;
    }
    void print(){
        cout << "product " << code << " is " << name << "\n";
    }
};
int main() {
    string name;
    int code;
    cin >> name >> code;
    Product product1;
    Product product2(name, code);
    product1.print();
    product2.print();
    return 0;
}