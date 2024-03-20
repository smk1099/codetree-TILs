#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    int n;
    cin >> n;
    int answer = 0;
    vector<int> v(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int sum = v[i] + v[2 * n - 1 - i];
        answer = max(answer, sum);
    }
    cout << answer;
    return 0;
}