#include <iostream>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n;
    cin >> n;
    int x = 0;
    int y = 0;
    while(n--){
        char dir;
        int num;
        cin >> dir >> num;
        switch(dir){
            case 'N':
            x = x + dx[0] * num;
            y = y + dy[0] * num;
            break;
            case 'E':
            x = x + dx[3] * num;
            y = y + dy[3] * num;
            break;
            case 'S':
            x = x + dx[1] * num;
            y = y + dy[1] * num;
            break;
            case 'W':
            x = x + dx[2] * num;
            y = y + dy[2] * num;
            break;
        }
    }
    cout << y << " " << x;
    return 0;
}