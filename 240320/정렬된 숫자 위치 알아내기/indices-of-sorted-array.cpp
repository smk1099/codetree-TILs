#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Custom_number{
    public:
    int value;
    int number;
    int position;
    Custom_number(int value = 0, int number = 0){
        this->value = value;
        this->number = number;
    }
    void set_position(int position){
        this->position = position;
    }
};

bool cmp(Custom_number &a, Custom_number &b){
    if(a.value == b.value){
        return a.number < b.number;
    }
    return a.value < b.value;
}
bool cmp2(Custom_number &a, Custom_number &b){
    return a.number < b.number;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Custom_number numbers[1001];
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        numbers[i]= Custom_number(val, i + 1);
    }
    sort(numbers, numbers + n, cmp);
    for(int i = 0; i < n; i++){
        numbers[i].set_position(i + 1);
    }
    sort(numbers, numbers + n, cmp2);
    for(int i = 0; i < n; i++){
        cout << numbers[i].position << " ";
    }
    return 0;
}