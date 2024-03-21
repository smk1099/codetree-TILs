#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

void print_vector(){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void choose_num(int index){
    if(index > n){
        print_vector();  
        return;
    }
    for(int i = 1; i <= k; i++){
        v.push_back(i);
        choose_num(index + 1);
        v.pop_back();
    }


}

int main() {
    cin >> k >> n;
    choose_num(1);
    return 0;
}