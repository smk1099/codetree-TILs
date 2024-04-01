#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*
/ -> 위 혹은 아래이면 반시계
양 옆이면 시계
\ -> 위 혹은 아래이면 시계
양 옆이면 반시계

시계방향 -> dir = (dir + 1) % 4
반시계방향 -> dir = (dir + 3) % 4

처음 방향 -> 번호 / 4 에 따라 결정하면 됨.
dir = ((번호 / 4) + 2) % 4
*/

int n;
char matrix[1001][1001];

bool in_range(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cin >> num;
    int dir = ((num / 4) + 2) % 4;

    // 초기 위치 세팅
    int tmp_dir = 1;
    int x = 0;
    int y = 0;
    num--;
    while(num--){
        int nx = x + dx[tmp_dir];
        int ny = y + dy[tmp_dir];
        if(in_range(nx, ny)){
            x = nx;
            y = ny;
        }
        else{
            tmp_dir = (tmp_dir + 1) % 4;
        }
    }
    // 초기 위치 세팅 끝

    int count = 0;
    while(in_range(x, y)){
        // cout << "x : " << x << "\n";
        // cout << "y : " << y << "\n";
        // cout << "dir : " << dir << "\n";
        // cout << "-------\n";
        if(matrix[x][y] == '\\'){
            if(dir % 2 == 0){
                //위 혹은 아래일때
                dir = (dir + 3) % 4;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }
        else{
            if(dir % 2 == 0){
                //위 혹은 아래일때
                dir = (dir + 1) % 4;
            }
            else{
                dir = (dir + 3) % 4;
            }
        }
        x += dx[dir];
        y += dy[dir];
        count++;
    }
    cout << count;

    return 0;
}