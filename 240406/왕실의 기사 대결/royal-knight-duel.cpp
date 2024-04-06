#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

/*
기사들의 초기 체력 - int init_health[31];
기사들의 현재 체력 - int curr_health[31];
기사들의 생존 여부 - bool survive[31];
기사들의 좌측 상단의 위치 중 r 좌표 int r_position[31];
기사들의 좌측 상단의 위치 중 c 좌표 int c_position[31];
기사들의 길이 - vector<pair<int, int>> length;
체스판 함정 및 벽 정보 - int board[41][41];
기사들의 좌측 상단 정보 - int obj_board[41][41]; -> 기사들의 번호가 적혀있고, 나머지는 0으로

기사가 체스판을 벗어나는지, 벽에 부딪히는지, 몇개의 함정에 빠졌는지 판정하는게 가장 중요한 포인트가 될 듯.

기사가 움직일때는 재귀적으로 호출해서 return 값은 움직이는데에 성공하는지로 구현하고
움직이는 위치에 다른 기사가 있는 경우 그 기사의 움직이는 함수를 호출하는 것으로 재귀를 구현.
만약 다음 움직이는 위치에 벽 혹은 체스판 밖인 경우 움직이지 못하기 때문에 false를 리턴한다.
false를 리턴받으면 모두 움직이지 못함.

만약 움직일 수 있다면 움직인 후에 함정 판정을 하고 함정 수 만큼 체력을 잃고 만약 0이 되면 기사를 제거한다.
제거할 때는 obj_board의 값을 0으로 바꾸고, survive를 false로 바꾼다.
제거되지 않으면 기사들의 번호를 토대로 r 좌표 c 좌표를 바꾸고, obj_board의 값을 해당 기사의 번호로 바꾼다.
이후에 curr_health를 업데이트 한다.
*/

int l;
int n;
int q;
int board[41][41];
int obj_board[41][41];
vector<pair<int, int>> length(31, {0, 0});
int r_position[31];
int c_position[31];
int init_health[31];
int curr_health[31];
int tmp_health[31];
bool survive[31];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool can_move(int number, int up, int left){
    int down = up + length[number].first - 1;
    int right = left + length[number].second - 1;
    if(up >= 1 && down <= l && left >= 1 && right <= l){
        for(int i = up; i <= down; i++){
            for(int j = left; j <= right; j++){
                if(board[i][j] == 2){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

int exist(int number, int up, int left){
    int down = up + length[number].first - 1;
    int right = left + length[number].second - 1;
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            if(obj_board[i][j] != 0 && obj_board[i][j] != number && survive[obj_board[i][j]]){
                return obj_board[i][j];
            }
        }
    }
    return 0;
}

void calc(int number, int count){
    //처음 움직인 기사는 데미지를 받지 않음.
    if(count == 0) return;
    int damage_sum = 0;
    int up = r_position[number];
    int left = c_position[number];
    int down = up + length[number].first - 1;
    int right = left + length[number].second - 1;
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            if(board[i][j] == 1){
                damage_sum++;
            }
        }
    }
    tmp_health[number] = curr_health[number] - damage_sum;

}

void erase_number(int number, int up, int left){
    int down = up + length[number].first - 1;
    int right = left + length[number].second - 1;
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            obj_board[i][j] = 0;
        }
    }
}

void insert_number(int number, int up, int left){
    int down = up + length[number].first - 1;
    int right = left + length[number].second - 1;
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            obj_board[i][j] = number;
        }
    }
}


bool move(int number, int dir, int count){
    // 움직여 데미지를 받으면 true, 움직일 수 없으면 false;
    int x = r_position[number];
    int y = c_position[number];
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(!can_move(number, nx, ny)){
        return false;
    }
    else{
        int next_number = exist(number, nx, ny);
        while(next_number != 0){
            if(!move(next_number, dir, count + 1)){
                return false;
            }
            next_number = exist(number, nx, ny);
        }
        erase_number(number, x, y);
        insert_number(number, nx, ny);
        r_position[number] = nx;
        c_position[number] = ny;
        calc(number, count);

    }
    return true;
}


int main() {
    cin >> l >> n >> q;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= l; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        r_position[i] = r;
        c_position[i] = c;
        length[i] = {h, w};
        insert_number(i, r, c);
        curr_health[i] = init_health[i] = k;
        survive[i] = true;
    }

    while(q--){
        int number, dir;
        cin >> number >> dir;
        //이동
        if(survive[number]){
            for(int i = 1; i <= n; i++){
                tmp_health[i] = curr_health[i];
            }
            if(move(number, dir, 0)){
                for(int i = 1; i <= n; i++){
                    curr_health[i] = tmp_health[i];
                    if(curr_health[i] <= 0){
                        survive[i] = false;
                    }
                }
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(survive[i]){
            answer += init_health[i] - curr_health[i];
        }
    }
    cout << answer;

    return 0;
}