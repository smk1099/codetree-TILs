#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    priority_queue<int> pq;
    // 최솟값 3개를 저장할 큐
    long long calc = 1;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(i < 3){
            pq.push(num);
            calc *= num;
            if(i == 2){
                cout << calc;
            }
            else{
                cout << -1;
            }
        }
        else{
            if(num < pq.top()){
                calc /= pq.top();
                pq.pop();
                calc *= num;
            }
            cout << calc;
        }
        cout << "\n";

    }
    return 0;
}