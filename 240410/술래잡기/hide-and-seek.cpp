#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

/*
**도망자
술래와의 거리가 3이하인 도망자만 움직임.
현재 보고 있는 방향으로 움직임.
격자 밖으로 움직일 경우 반대로 틀어서 움직임.
가고자 하는 방향에 술래가 있다면 움직이지 않음.
도망자끼리 겹칠 수 있음.

**술래
달팽이 모양으로 움직임.
현재 보고 있는 방향에서 자신의 칸을 포함해 3칸을 확인.
단 이때 만약 나무가 있는 칸이라면 도망자를 보지 못함.
도망자를 잡았다면 점수를 획득
점수는 현재 턴 x 현재턴에서 잡은 도망자 수


격자는 총 2개의 격자가 필요할 듯??
술래와 나무가 있는 격자
int matrix[100][100]
도망자들이 있는 격자 -> 여러개가 포함될 수 있으므로
set<int> runners[100][100];
도망자의 x좌표 배열
int x_position[10000];
도망자의 y좌표 배열
int y_position[10000];
도망자의 dx, dy
int dx1[4] = {1, 0, -1, 0};
int dy1[4] = {0, 1, 0, -1};
술래의 (1, 1) 도착 여부와 (n / 2, n / 2) 도착 여부를 저장하는 변수
-> true인 경우는 방향을 반대로 바꾸고, 만약 도착하는 경우는 방향을 무조건 아래로 설정한다.
-> 처음은?? 무조건 2로 설정
bool one_to_one = false;


*/
//술래가 지나온 길을 체크하는 격자.
bool is_check[100][100];

//나무가 있는 격자
bool is_tree[100][100];

// 도망자들이 있는 격자 -> 여러개가 포함될 수 있으므로
set<int> runners[100][100];
// 도망자의 x좌표 배열
int x_position[10000];
// 도망자의 y좌표 배열
int y_position[10000];
// 도망자의 현재 방향
int run_dir[10000];
// 도망자의 생존 여부
bool survive[10000];;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// 술래의 (1, 1) 도착 여부와 (n / 2, n / 2) 도착 여부를 저장하는 변수
// -> true인 경우는 방향을 반대로 바꾸고, 만약 도착하는 경우는 방향을 무조건 아래로 설정한다.
// -> 처음은?? 무조건 2로 설정
bool one_to_one = false;

int monster_x, monster_y, monster_dir;
//술래의 x, y좌표, 방향

int n, m, h, k;
int turn = 1;
int answer = 0;

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

int get_dist(int x, int y){
    return abs(x - monster_x) + abs(y - monster_y);
}

void check_init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            is_check[i][j] = false;
        }
    }
}

void move(int number){
    int x = x_position[number];
    int y = y_position[number];
    int curr_dir = run_dir[number];
    int nx = x + dx[curr_dir];
    int ny = y + dy[curr_dir];
    if(!in_range(nx, ny)){
        curr_dir = (curr_dir + 2) % 4;
        run_dir[number] = curr_dir;
        nx = x + dx[curr_dir];
        ny = y + dy[curr_dir];
    }
    if(nx == monster_x && ny == monster_y) return;
    auto it = runners[x][y].find(number);
    runners[x][y].erase(it);
    x = x_position[number] = nx;
    y = y_position[number] = ny;
    runners[x][y].insert(number);
}

void get_run(int x, int y){
    if(is_tree[x][y] || runners[x][y].empty()) return;
    int count = runners[x][y].size();
    for(int i = 0; i < count; i++){
        auto it = runners[x][y].begin();
        int number = *it;
        survive[number] = false;
        runners[x][y].erase(it);
    }
    answer += turn * count;
}

void monster_move(){
    monster_x += dx[monster_dir];
    monster_y += dy[monster_dir];
    if(!one_to_one && monster_x == 1 && monster_y == 1){
        one_to_one = true;
        monster_dir = 2;
        check_init();
    }
    else if(one_to_one && monster_x == n / 2 + 1 && monster_y == n / 2 + 1){
        one_to_one = false;
        monster_dir = 0;
        check_init();
    }
    else{
        if(!one_to_one){
            int next_dir = (monster_dir + 1) % 4;
            int nx = monster_x + dx[monster_dir];
            int ny = monster_y + dy[monster_dir];
            if(!in_range(nx, ny)){
                monster_dir = next_dir;
            }
            else{
                nx = monster_x + dx[next_dir];
                ny = monster_y + dy[next_dir];
                if(!is_check[nx][ny]){
                    monster_dir = next_dir;
                }
            }
        }
        else{
            int next_dir = (monster_dir + 3) % 4;
            int nx = monster_x + dx[monster_dir];
            int ny = monster_y + dy[monster_dir];
            if(!in_range(nx, ny)){
                monster_dir = next_dir;
            }
            else{
                nx = monster_x + dx[monster_dir];
                ny = monster_y + dy[monster_dir];
                if(is_check[nx][ny]){
                    monster_dir = next_dir;
                }
            }
        }
        
    }
    is_check[monster_x][monster_y] = true;
    for(int i = 0; i < 3; i++){
        int curr_x = monster_x + dx[monster_dir] * i;
        int curr_y = monster_y + dy[monster_dir] * i;
        if(in_range(curr_x, curr_y)){
            get_run(curr_x, curr_y);
        }
    }
}


int main() {
    cin >> n >> m >> h >> k;
    for(int i = 1; i <= m; i++){
        int x, y, d;
        cin >> x >> y >> d;
        runners[x][y].insert(i);
        x_position[i] = x;
        y_position[i] = y;
        run_dir[i] = d;
        survive[i] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            is_check[i][j] = is_tree[i][j] = false;
        }
    }
    monster_x = monster_y = n / 2 + 1;
    is_check[monster_x][monster_y] = true;
    monster_dir = 0;
    while(h--){
        int x, y;
        cin >> x >> y;
        is_tree[x][y] = true;
    }
    while(k--){
        for(int i = 1; i <= m; i++){
            if(!survive[i]) continue;
            int curr_x = x_position[i];
            int curr_y = y_position[i];
            if(get_dist(curr_x, curr_y) <= 3){
                move(i);
            }
        }
        monster_move();
        turn++;
    }
    cout << answer;
    return 0;
}