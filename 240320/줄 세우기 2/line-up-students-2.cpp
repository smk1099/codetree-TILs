#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
    int h;
    int w;
    int number;
    Student(int h = 0, int w = 0, int number = 0){
        this->h = h;
        this->w = w;
        this->number = number;
    }
    void print(){
        cout << h << " " << w << " " << number << "\n";
    }

};

bool cmp(Student &a, Student &b){
    if(a.h == b.h){
        return a.w > b.w;
    }
    return a.h < b.h;
}

int main() {
    int n;
    cin >> n;
    Student people[1000];
    for(int i = 0; i < n; i++){
        int h, w;
        cin >> h >> w;
        people[i] = Student(h, w, i + 1);
    }
    sort(people, people + n, cmp);
    for(int i = 0; i < n; i++){
        people[i].print();
    }
    return 0;
}