#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

/*
r, c에서 q x q 회전 할 때
for(int i = r; i < r + q; i++){
    for(int j = c; j < c + q; j++){
        tmp[j][c + q - i] = matrix[i][j];
    }
}

1, 1에서 3 x 3 회전 할 때
1 1 -> 1 3
1 2 -> 2 3
1 3 -> 3 3
2 1 -> 1 2
2 2 -> 2 2
2 3 -> 3 2
3 1 -> 1 1
3 2 -> 2 1
3 3 -> 3 1


for(int i = r; i < r + q; i++){
    for(int j = c; j < c + q; j++){
        if(tmp[i][j] > 0 && tmp[i][j] <= 9){
            tmp[i][j]--;
        }
        matrix[i][j] = tmp[i][j];
    }
}

정사각형 판정 **
최대한 위쪽이면서 왼쪽인 것.
max(참가자의 r좌표 - 출구의 r좌표, 참가자의 c좌표 - 출구의 c좌표)중 가장 작은 것.
만약 같다면 참가자의 r좌표, c좌표 순으로 정렬
사각형 좌표 **
길이를 구했다면 출구와 참가자의 큰 r, c 좌표가 오른쪽 하단 후보
이를 통해 왼쪽 상단의 좌표를 구하는데, 만약 왼쪽 상단 좌표가 격자 밖이라면 안으로 만들어 구하고
오른쪽 하단 좌표를 업데이트 한다.

회전만 좀 고치면 될듯??
*/
int n, m, k;
int exit_r;
int exit_c;
int answer = 0;
int matrix[11][11];
int tmp[11][11]; //회전 전용 임시 격자
int r_position[11]; //참가자 r좌표
int c_position[11]; //참가자 c좌표
bool is_exit[11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int get_dist(int x, int y){
    return abs(x - exit_r) + abs(y - exit_c);
}

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

int can_move(int number){
    int x = r_position[number];
    int y = c_position[number];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in_range(nx, ny) && get_dist(x, y) > get_dist(nx, ny)){
            if(matrix[nx][ny] == 0){
                return 0;
            }
            else if(matrix[nx][ny] > 10){
                return matrix[nx][ny] - 10;
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}

void move(int number){
    int next_number = can_move(number);
    if(next_number == -1){
        return;
    }
    else if(next_number != 0){
        move(next_number);
        if(can_move(number) != 0){
            return;
        }
    }
    int x = r_position[number];
    int y = c_position[number];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in_range(nx, ny) && matrix[nx][ny] == 0 && get_dist(x, y) > get_dist(nx, ny)){
            answer++;
            matrix[x][y] = 0;
            if(nx == exit_r && ny == exit_c){
                is_exit[number] = true;
                return;
            }
            matrix[nx][ny] = number + 10;
            r_position[number] = nx;
            c_position[number] = ny;

            return;
        }
    }
}

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b){
    int x1, y1;
    int x2, y2;
    tie(ignore, x1, y1) = a;
    tie(ignore, x2, y2) = b;
    int gap1 = max(abs(x1 - exit_r), abs(y1 - exit_c));
    int gap2 = max(abs(x2 - exit_r), abs(y2 - exit_c));
    if(gap1 == gap2){
        if(x1 == x2){
            return y1 < y2;
        }
        return x1 < x2;
    }
    return gap1 < gap2;
}

void turn(){
    vector<tuple<int, int, int>> v;
    for(int i = 1; i <= m ; i++){
        if(is_exit[i]) continue;
        v.push_back({i, r_position[i], c_position[i]});
    }
    if(v.empty()) return;
    sort(v.begin(), v.end(), cmp);
    int number, curr_x, curr_y;
    tie(number, curr_x, curr_y) = v[0];
    int gap = max(abs(curr_x - exit_r), abs(curr_y - exit_c));
    int bottom = max(curr_x, exit_r);
    int right = max(curr_y, exit_c);
    //오른쪽 하단 위치를 기반으로 왼쪽 상단 위치 계산
    int top = max(1, bottom - gap);
    int left = max(1, right - gap);

    for(int i = top; i <= top + gap; i++){
        for(int j = left; j <= left + gap; j++){
            if(i == exit_r && j == exit_c){
                exit_r = j;
                exit_c = left + gap + 1 - i;
            }
            tmp[j][left + gap + 1 - i] = matrix[i][j];
        }
    }

    for(int i = top; i <= top + gap; i++){
        for(int j = left; j <= left + gap; j++){
            matrix[i][j] = tmp[i][j];
            if(matrix[i][j] > 0 && matrix[i][j] <= 9){
                matrix[i][j]--;
            }
            else if(matrix[i][j] > 10){
                r_position[matrix[i][j] - 10] = i;
                c_position[matrix[i][j] - 10] = j;
            }
        }
    }

}






int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 10 + i;
        r_position[i] = x;
        c_position[i] = y;
        is_exit[i] = false;
    }
    cin >> exit_r >> exit_c;
    while(k--){
        for(int i = 1; i <= m; i++){
            if(!is_exit[i]){
                move(i);
            }
        }
        turn();
    }
    cout << answer << "\n";
    cout << exit_r << " " << exit_c;
    return 0;
}