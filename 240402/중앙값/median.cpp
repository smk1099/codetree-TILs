#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        priority_queue<int> bigger;
        priority_queue<int> smaller;
        int number = 0;
        cin >> number;
        cout << number << " ";
        for(int i = 1; i < m; i++){
            int input_number;
            cin >> input_number;
            if(input_number > number){
                bigger.push(-input_number);
            }
            else{
                smaller.push(input_number);
            }

            if(i % 2 == 0){
                if(bigger.size() > smaller.size()){
                    smaller.push(number);
                    number = -bigger.top();
                    bigger.pop();
                }
                else if(smaller.size() > bigger.size()){
                    bigger.push(-number);
                    number = smaller.top();
                    smaller.pop();
                }
                cout << number << " ";
            }
        }
        cout << "\n";

    }
    return 0;
}