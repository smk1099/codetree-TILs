#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int answer = 0;

void is_answer(){
    int prev_number = 0;
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(count == 0){
            prev_number = v[i];
            count = v[i] - 1;
        }
        else if(prev_number != v[i]){
            return;
        }
        else{
            count--;
        }
    }
    if(count == 0){
        answer++;
    }
}

void choose_num(int index){
    if(index > n){
        is_answer();
        return;
    }
    for(int i = 1; i <= 4; i++){
        v.push_back(i);
        choose_num(index + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    choose_num(1);
    cout << answer;
    return 0;
}