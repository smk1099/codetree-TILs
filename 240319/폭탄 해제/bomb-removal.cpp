#include <iostream>

using namespace std;

class Bomb{
    public:
    string code;
    char color;
    int second;
    Bomb(){
        code = "";
        color = 'A';
        second = 0;
    }
    Bomb(string code, char color, int second){
        this->code = code;
        this->color = color;
        this->second = second;
    }
    void print(){
        cout << "code : " << code;
        cout <<"\ncolor : " << color;
        cout <<"\nsecond : " << second;
    }
};
int main() {
    string code;
    char color;
    int second;
    cin >> code >> color >> second;
    Bomb bomb(code, color, second);
    bomb.print();
    return 0;
}