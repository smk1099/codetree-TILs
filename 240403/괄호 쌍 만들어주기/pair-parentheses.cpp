#include <iostream>

using namespace std;
/*
여는 괄호 두개가 나오면 그 뒤로 닫는 괄호 연속 두개가 몇개 나오는지 구해놓은게 있다면
그만큼 답으로 더하면 됨.
뒤에서부터 닫는 괄호 연속 두개가 나오면 해당 위치에 1을 더하면 됨.
*/



int main() {
    int back_count[100'001];
    string str;
    cin >> str;
    int n = str.size();
    long long answer = 0;
    for(int i = 0; i < n; i++){
        back_count[i] = 0;
    }
    for(int i = n - 2; i >= 0; i--){
        if(str[i] == ')' && str[i + 1] == ')'){
            back_count[i] = back_count[i + 1] + 1;
        }
        else{
            back_count[i] = back_count[i + 1];
        }
    }
    for(int i = 1; i < n; i++){
        if(str[i] == '(' && str[i - 1] == '('){
            answer += back_count[i];
        }
    }
    cout << answer;
    return 0;
}