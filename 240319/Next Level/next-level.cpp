#include <iostream>

using namespace std;

class Unit{
    public:
    string id;
    int level;
    Unit(){
        id = "codetree";
        level = 10;
    }
    Unit(string id, int level){
        this->id = id;
        this->level = level;
    }
    void print(){
        cout << "user " << this->id << " lv " << this->level << "\n";
    }
};

int main() {
    string id;
    int level;
    cin >> id >> level;
    Unit unit1;
    Unit unit2(id, level);
    unit1.print();
    unit2.print();

    return 0;
}