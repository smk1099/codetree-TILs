#include <iostream>

using namespace std;

int n, m, k;
int matrix[301][301];
int tmp[301][301];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotate(int x, int y, int x_len, int y_len){
    //시작점과 둘레가 주어지면 이를 기반으로 반시계 방향 회전
    int length = x_len * 2 + y_len * 2 - 4;
    if(length == 0) return;
    int real_k = k % length;
    int count[4] = {x_len - 1, y_len - 1, x_len - 1, y_len - 1};
    int curr_x = x;
    int curr_y = y;
    while(real_k--){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < count[i]; j++){
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];
                tmp[nx][ny] = matrix[curr_x][curr_y];
                curr_x = nx;
                curr_y = ny;
            }
        }
        curr_x = x;
        curr_y = y;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < count[i]; j++){
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];
                matrix[nx][ny] = tmp[nx][ny];
                curr_x = nx;
                curr_y = ny;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    int curr_x = 1;
    int curr_y = 1;
    int curr_x_len = n;
    int curr_y_len = m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            tmp[i][j] = matrix[i][j];
        }
    }
    while(curr_x_len >= 2 && curr_y_len >= 2){
        rotate(curr_x, curr_y, curr_x_len, curr_y_len);
        curr_x++;
        curr_y++;
        curr_x_len -= 2;
        curr_y_len -= 2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}