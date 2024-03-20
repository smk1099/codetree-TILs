#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    int average = sum / n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > average){
            answer += v[i] - average;
        }
    }
    cout << answer;
    return 0;
}