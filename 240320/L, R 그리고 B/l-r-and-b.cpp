#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l_x, l_y;
    int r_x, r_y;
    int b_x, b_y;
    char input;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> input;
            if(input == 'B'){
                b_x = i;
                b_y = j;
            }
            if(input == 'R'){
                r_x = i;
                r_y = j;
            }
            if(input == 'L'){
                l_x = i;
                l_y = j;
            }
        }
    }
    int answer =  abs(b_x - l_x) + abs(b_y - l_y);
    if(l_x == r_x && r_x == b_x){
        if(l_y < r_y && r_y < b_y){
             answer += 2;
        }
        else if(l_y > r_y && r_y > b_y){
             answer += 2;
        }
    } 
    else if(l_y == r_y && r_y == b_y){
        if(l_x < r_x && r_x < b_x){
             answer += 2;
        }
        else if(l_x > r_x && r_x > b_x){
             answer += 2;
        }
    }

    cout << answer - 1;
    return 0;
}