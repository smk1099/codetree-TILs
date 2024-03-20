#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int A = 0;
    int B = 0;
    int answer = 0;
    int winner = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin >> c >> s;
        if(c == 'A'){
            A += s;
        }
        else{
            B += s;
        }
        if(A < B && winner != 2){
            winner = 2;
            answer++;
        }
        else if(A > B && winner != 1){
            winner = 1;
            answer++;
        }
        else if(A == B && winner != 3){
            winner = 3;
            answer++;
        }
    }
    cout << answer;
    return 0;
}