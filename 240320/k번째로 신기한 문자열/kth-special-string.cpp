#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    int n, k;
    string start;
    cin >> n >> k >> start;
    int sub_str_size = start.size();
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str.substr(0, sub_str_size) == start){
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end());
    cout << v[k - 1];
    return 0;
}