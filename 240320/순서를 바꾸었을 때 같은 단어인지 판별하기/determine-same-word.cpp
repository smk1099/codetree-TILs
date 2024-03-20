#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<char, int> m;
    vector<char> v;
    int n;
    string answer = "Yes";
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0; i < str1.size(); i++){
        if(m[str1[i]]++ == 0){
            v.push_back(str1[i]);
        };
    }
    for(int i = 0; i < str2.size(); i++){
        m[str2[i]]--;
        if(m[str2[i]] < 0){
            answer = "No";
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(m[v[i]] != 0){
            answer = "No";
        }
    }
    cout << answer;
    return 0;
}