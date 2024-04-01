#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
bool in_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int matrix[101][101];
int main() {
    cin >> n >> m;
    int dir = 2;
    int x = 0;
    int y = 0;
    int num = 1;
    while(num <= n * m){
        matrix[x][y] = num;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!in_range(nx, ny) || matrix[nx][ny] != 0){
            dir = (dir + 3) % 4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
        num++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}