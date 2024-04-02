#include <iostream>
#include <tuple>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i <n ;i++){
        int num;
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                int output;
                tie(ignore, output) = pq.top();
                pq.pop();
                cout << -output << "\n";
            }
        }
        else{
            pq.push({-abs(num), -num});
        }
    }
    return 0;
}