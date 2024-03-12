#include <iostream>

using namespace std;

string str;
int main() {
    cin >> str;
    int n = str.size();
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            for(int j = i + 1; j < n; j++){
                if(str[j] == ')'){
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}