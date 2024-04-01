#include <iostream>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool in_range(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int matrix[101][101];
int main() {
    int num = 1;
    cin >> n >> m;
    int dir = 1;
    int x = 0;
    int y = 0;
    while(num <= n * m){
        matrix[x][y] = num;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!in_range(nx, ny) || matrix[nx][ny] != 0){
            dir = (dir + 1) % 4;
        }
        x += dx[dir];
        y += dy[dir];
        num++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (char)((matrix[i][j] - 1) % 26 + 'A') << " ";
        }
        cout << "\n";
    }
    return 0;
}