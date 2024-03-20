#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
    int a, b, c;
    a = b = c = 0;
    int winner = 6;
    pair<int, int> game[3] = {{0, 1}, {0, 2}, {0, 3}};
    int n;
    cin >> n;
    int answer = 0;
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin >> c >> s;
        for(int i = 0; i < 3; i++){
            if(get<1>(game[i]) == (int)(c - 'A') + 1){
                get<0>(game[i]) += s;
            }
        }
        sort(game, game + 3);
        int cur_win = 0;
        int min_val = get<0>(game[2]);
        for(int i = 0; i < 3; i++){
            if(min_val == get<0>(game[i])){
                cur_win += get<1>(game[i]);
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