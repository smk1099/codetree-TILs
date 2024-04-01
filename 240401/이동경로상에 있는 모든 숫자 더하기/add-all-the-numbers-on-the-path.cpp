#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
bool in_range(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

int matrix[100][100];

int main() {
    int t;
    cin >> n >> t;
    string str;
    cin >> str;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int x = n / 2;
    int y = n / 2;
    int dir = 0;
    int answer = matrix[x][y];
    for(int i = 0; i < str.size(); i++){
        switch(str[i]){
            case 'L':
            dir = (dir + 3) % 4;
            break;
            case 'R':
            dir = (dir + 1) % 4;
            break;
            case 'F':
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(in_range(nx, ny)){
                x = nx;
                y = ny;
                answer += matrix[x][y];
            }
            break;
        }
    }
    cout << answer;
    return 0;
}