#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/*
루돌프가 움직일 때 방향 정하기
-> 탈락하지 않은 산타들을 벡터에 넣고 특정 기준으로 정렬
가장 첫번째 산타의 좌표에 따라 루돌프의 방향 결정
루돌프가 움직인 후 충돌 발생

충돌이 발생하면 산타에게 점수를 부여하고 움직일때까지 남은 턴을 + 2로 한다.
산타가 부딪힌 경우에는 남은 턴을 + 1로 한다.

밀려난 뒤에 해당 위치에 산타가 있는 경우 해당 산타를 위치로 이동시킨다.

상우하좌로 이동하면서 가장 거리가 많이 줄어드는 방향을 4번 탐색해 알라내고, 알아낸 위치로
1칸 이동하고 나서, 충돌을 발생시킨다.

산타의 모두 탈락은 어떻게??
-> 루돌프가 우선순위를 결정할때 벡터의 크기가 0이면 턴 종료 시키면 됨.
*/

int r_position[31];
int c_position[31];
int matrix[51][51]; //산타들만 저장하는 격자
bool survive[31]; //산타들의 생존 여부
int impossible[31]; //기절한 산타의 기절해 움직이지 못하는 최대 턴
int score[31]; //산타들의 점수
int santa_power, lu_power;
int lu_r, lu_c; //루돌프의 좌표
int n, m, p;
int curr_turn = 0;

int get_dist(int x, int y){
    return (x - lu_r) * (x - lu_r) + (y - lu_c) * (y - lu_c);
}


bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b){
    int r1, c1;
    int r2, c2;
    tie(ignore, r1, c1) = a;
    tie(ignore, r2, c2) = b;
    if(get_dist(r1, c1) == get_dist(r2, c2)){
        if(r1 == r2){
            return c1 > c2;
        }
        return r1 > r2;
    }
    return get_dist(r1, c1) < get_dist(r2, c2);
}

void collapse(int curr_number, int r, int c, int r_dir, int c_dir){
    int next_number = matrix[r][c];
    matrix[r][c] = curr_number;
    int nr = r + r_dir;
    int nc = c + c_dir;
    r_position[next_number] = nr;
    c_position[next_number] = nc;
    if(!in_range(nr, nc)){
        survive[next_number] = false;
    }
    else{
        if(matrix[nr][nc] == 0){
            matrix[nr][nc] = next_number;
        }
        else{
            collapse(next_number, nr, nc, r_dir, c_dir);
        }
    }
}

void lu_move(){
    vector<tuple<int, int, int>> v;
    for(int i = 1; i <= p; i++){
        if(!survive[i]) continue;
        v.push_back({i, r_position[i], c_position[i]});
    }
    if(v.empty()) return;
    sort(v.begin(), v.end(), cmp);
    int number, curr_r, curr_c;
    tie(number, curr_r, curr_c) =  v[0];
    int r_dir = 0;
    int c_dir = 0;
    if(lu_r < curr_r){
        r_dir = 1;
    }
    else if(lu_r > curr_r){
        r_dir = -1;
    }
    if(lu_c < curr_c){
        c_dir = 1;
    }
    else if(lu_c > curr_c){
        c_dir = -1;
    }
    lu_r += r_dir;
    lu_c += c_dir;
    if(lu_r == curr_r && lu_c == curr_c){
        //충돌판정
        score[number] += lu_power;
        impossible[number] = curr_turn + 1;
        r_position[number] += r_dir * lu_power;
        c_position[number] += c_dir * lu_power;
        int nr = r_position[number];
        int nc = c_position[number];
        matrix[curr_r][curr_c] = 0;
        if(!in_range(nr, nc)){
            survive[number] = false;
        }
        else{
            if(matrix[nr][nc] == 0){
                matrix[nr][nc] = number;
            }
            else{
                collapse(number, nr, nc, r_dir, c_dir);
            }
        }
    }
}

void santa_move(int number){
    int curr_r = r_position[number];
    int curr_c = c_position[number];
    int curr_dir = -1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int min_dist = get_dist(curr_r, curr_c);
    for(int i = 0; i < 4; i++){
        int nr = curr_r + dx[i];
        int nc = curr_c + dy[i];
        if(in_range(nr, nc) && matrix[nr][nc] == 0){
            if(min_dist > get_dist(nr, nc)){
                min_dist = get_dist(nr, nc);
                curr_dir = i;
            }
        }
    }
    if(curr_dir == -1) return;
    int next_r = curr_r + dx[curr_dir];
    int next_c = curr_c + dy[curr_dir];
    matrix[curr_r][curr_c] = 0;
    r_position[number] = next_r;
    c_position[number] = next_c;
    if(lu_r == next_r && lu_c == next_c){
        //충돌 판정
        score[number] += santa_power;
        impossible[number] = curr_turn + 1;
        int r_dir = -dx[curr_dir];
        int c_dir = -dy[curr_dir];
        r_position[number] += r_dir * santa_power;
        c_position[number] += c_dir * santa_power;
        int nr = r_position[number];
        int nc = c_position[number];
        if(!in_range(nr, nc)){
            survive[number] = false;
        }
        else{
            if(matrix[nr][nc] == 0){
                matrix[nr][nc] = number;
            }
            else{
                collapse(number, nr, nc, r_dir, c_dir);
            }
        }
    }
    else{
        matrix[next_r][next_c] = number;
    }
}


int main(){
    cin >> n >> m >> p >> lu_power >> santa_power;
    cin >> lu_r >> lu_c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < p; i++){
        int num, r, c;
        cin >> num >> r >> c;
        r_position[num] = r;
        c_position[num] = c;
        matrix[r][c] = num;
        survive[num] = true;
        impossible[num] = 0;
        score[num] = 0;
    }

    while(++curr_turn <= m){
        lu_move();
        for(int i = 1; i <= p; i++){
            if(survive[i] && impossible[i] < curr_turn){
                santa_move(i);
            }
        }
        for(int i = 1; i <= p; i++) {
            if (survive[i]) {
                score[i]++;
            }
        }
    }
    for(int i = 1; i <= p; i++){
        cout << score[i] << " ";
    }
    return 0;
}