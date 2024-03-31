#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}


int main() {
    int t, x, y;
    int dir = 0;
    cin >> n >> t >> x >> y;
    char d;
    cin >> d;
    switch(d){
        case 'U':
        dir = 0;
        break;
        case 'D':
        dir = 2;
        break;
        case 'R':
        dir = 1;
        break;
        case 'L':
        dir = 3;
        break;
    }
    while(t--){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(in_range(nx, ny)){
            x = nx;
            y = ny;
        }
        else{
            dir = (dir + 2) % 4;
        }
    }
    cout << x << " " << y;
    return 0;
}