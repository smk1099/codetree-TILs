#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int dir = 0;
    string str;
    cin >> str;
    int x = 0;
    int y = 0;
    for(int i = 0; i < str.size(); i++){
        switch(str[i]){
            case 'L':
            dir = (dir + 3) % 4;
            break;
            case 'R':
            dir = (dir + 5) % 4;
            break;
            case 'F':
            x += dx[dir];
            y += dy[dir];
            break;
        }
    }
    cout << y << " " << x;
    return 0;
}