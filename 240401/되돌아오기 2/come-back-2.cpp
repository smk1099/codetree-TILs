#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int dir = 0;
    int x = 0;
    int y = 0;
    int count = 0;
    bool answer = false;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        count++;
        switch(str[i]){
            case 'F':
            x += dx[dir];
            y += dy[dir];
            break;
            case 'L':
            dir = (dir + 3) % 4;
            break;
            case 'R':
            dir = (dir + 1) % 4;
            break;
        }
        if(x == 0 && y == 0){
            answer = true;
            break;
        }
    }
    if(!answer){
        count = -1;
    }
    cout << count;
    return 0;
}