#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int matrix[101][101];

int n;
int m;

bool in_range(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
    cin >> n >> m;
    while(m--){
        int r, c;
        cin >> r >> c;
        matrix[r][c] = 1;
        int count = 0;
        for(int i = 0; i < 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(in_range(nx, ny) && matrix[nx][ny] == 1){
                count++;
            }
        }
        if(count == 3){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}