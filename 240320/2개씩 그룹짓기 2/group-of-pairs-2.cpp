#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    int arr[200000];
    int answer = INT_MAX;
    cin >> n;
    for(int i = 0; i < n * 2; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n * 2);
    for(int i = 0; i < n; i++){
        answer = min(answer, arr[n + i] - arr[i]);
    }
    cout << answer;
    return 0;
}