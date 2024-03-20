#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
    int height;
    int weight;
    int number;
    Student(int height = 0, int weight = 0, int number = 0){
        this->height = height;
        this->weight = weight;
        this->number = number;
    }
    void print(){
        cout << height << " " << weight << " " << number << "\n";
    }
};

bool cmp(Student& a, Student& b){
    if(a.height == b.height){
        if(a.weight == b.weight){
            return a.number < b.number;
        }
        return a.weight > b.weight;
    }
    return a.height > b.height;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Student people[1001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int height, weight;
        cin >> height >> weight;
        people[i] = Student(height, weight, i + 1);
    }
    sort(people, people + n, cmp);
    for(int i = 0; i < n; i++){
        people[i].print();
    }
    return 0;
}