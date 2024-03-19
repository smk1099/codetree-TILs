#include <iostream>

using namespace std;

class Person{
    public:
    char codeName;
    int score;
    Person(){
        codeName = '-';
        score = 0;
    }
    Person(char codeName, int score){
        this->codeName = codeName;
        this->score = score;
    }
    void print(){
        cout << this->codeName << " " << this->score;
    }
};
int main() {
    Person people[5];
    int min_score = 101;
    Person person;
    for(int i = 0; i < 5; i++){
        char codeName;
        int score;
        cin >> codeName >> score;
        people[i] = {codeName, score};
        if(min_score > score){
            person = people[i];
            min_score = score;
        }
    }
    person.print();
    return 0;
}