#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;

int n;
int arr[101];
int answer = INT_MAX;
void calc(int index){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i] * abs(i - index);
    }
    if(answer > sum){
        answer = sum;
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        calc(i);
    }
    cout << answer;
    return 0;
}