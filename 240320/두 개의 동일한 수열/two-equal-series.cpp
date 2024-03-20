#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> m;
    int n;
    cin >> n;
    string answer = "Yes";
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        m[num]++;
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(m[num] != 1){
            answer = "No";
            break;
        }
    }
    cout << answer;
    return 0;
}