#include <bits/stdc++.h>
using namespace std;


int main() {
    string words[101];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    sort(words, words + n);
    for(auto & item : words){
        cout << item << "\n";
    }
    return 0;
}