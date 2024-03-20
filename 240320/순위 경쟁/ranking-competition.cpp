#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
    int a, b, c;
    a = b = c = 0;
    int winner = 7;
    pair<int, int> game[3] = {{0, 1}, {0, 2}, {0, 4}};
    int n;
    cin >> n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin >> c >> s;
        if(c == 'C'){
            c = 'D';
        }
        for(int j = 0; j < 3; j++){
            if(get<1>(game[j]) == (int)(c - 'A') + 1){
                get<0>(game[j]) += s;
            }
        }
        sort(game, game + 3);
        int cur_win = 0;
        int max_val = get<0>(game[2]);
        for(int j = 0; j < 3; j++){
            if(max_val == get<0>(game[j])){
                cur_win += get<1>(game[j]);
            }
        }
        if(cur_win != winner){
            answer++;
            winner = cur_win;
        }
    }
    cout << answer;
    return 0;
}