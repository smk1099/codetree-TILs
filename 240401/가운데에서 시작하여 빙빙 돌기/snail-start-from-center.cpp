#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
bool in_range(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}
int matrix[101][101];
int main() {
    cin >> n;
    int x = n / 2;
    int y = n / 2;
    int dir = 2;
    int num = 1;
    while(num <= n * n){
        matrix[x][y] = num;
        int check_dir = (dir + 3) % 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int check_x = x + dx[check_dir];
        int check_y = y + dy[check_dir];
        if(!in_range(nx, ny) ){
            dir = (dir + 3) % 4;
        }
        else if(matrix[check_x][check_y] == 0){
            dir = (dir + 3) % 4;
        }
        x += dx[dir];
        y += dy[dir];
        num++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}