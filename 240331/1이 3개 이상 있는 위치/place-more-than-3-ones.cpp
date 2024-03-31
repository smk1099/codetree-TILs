#include <iostream>

using namespace std;

int count = 0;
int matrix[101][101];
int visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

bool in_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, int number){
    visited[x][y] = number;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in_range(nx, ny) && matrix[nx][ny] == 1 && visited[nx][ny] == 0){
            dfs(nx, ny, number);
        }
    }
}
int main() {
    cin >> n;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            visited[i][j] = 0;
        }
    }

    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1 && visited[i][j] == 0){
                dfs(i, j, ++count);
            }
        }
    }

    cout << count;



    return 0;
}