#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
        if(i % 2 == 0){
            sort(v.begin(), v.end());
            cout << v[i / 2] << " ";
        }
    }
    return 0;
}