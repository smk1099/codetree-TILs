#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;



int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int arr1[100'000];
    int arr2[100'000];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    priority_queue<tuple<int, int, int>> pq;
    for(int i = 0; i < n; i++){
        pq.push({-(arr1[i] + arr2[0]), i, 0});
    }
    while(--k){
        int index1, index2;
        tie(ignore, index1, index2) = pq.top();
        pq.pop();
        pq.push({-(arr1[index1] + arr2[index2 + 1]), index1, index2 + 1});
    }
    int answer;
    tie(answer, ignore, ignore) = pq.top();
    cout << -answer;
    return 0;
}