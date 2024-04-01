#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int x = 0;
    int y = 0;
    int n;
    cin >> n;
    int dir = 0;
    int count = 0;
    bool answer = false;
    while(n--){
        char c;
        int num;
        cin >> c >> num;
        switch(c){
            case 'N':
            dir = 0;
            break;
            case 'E':
            dir = 1;
            break;
            case 'S':
            dir = 2;
            break;
            case 'W':
            dir = 3;
            break;
        }
        while(num--){
            x += dx[dir];
            y += dy[dir];
            count++;
            if(x == 0 && y == 0){
                answer = true;
                break;
            }
        }
        if(answer){
            break;
        }
    }
    if(!answer){
        count = -1;
    }
    cout << count;
    return 0;
}