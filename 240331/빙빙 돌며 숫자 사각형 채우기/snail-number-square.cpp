#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;

bool in_range(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int matrix[101][101];
int number = 1;

int main() {
    cin >> n >> m;
    int dir = 0;
    int x = 0;
    int y = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = 0;
        }
    }

    while(number <= n * m){
        matrix[x][y] = number;
        number++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!in_range(nx, ny) || matrix[nx][ny] != 0){
            dir = (dir + 5) % 4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << "\n";
    }

    
    return 0;
}