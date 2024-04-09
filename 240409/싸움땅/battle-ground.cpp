#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int init_power[31];
int matrix[21][21]; //사람들의 위치를 저장하고 있는 격자
priority_queue<int> gun[21][21]; //각 위치마다의 총들을 파워 순으로 저장
int point[31]; //사람들의 포인트를 저장
int dir[31]; //사람들의 방향을 저장
int use_gun[31]; //현재 사용중인 총의 파워를 저장
int x_position[31];
int y_position[31];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0 ,-1};

void move(int);

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

void get_gun(int x, int y, int number){
    //해당위치에서 총 줍기
    if(gun[x][y].empty()) return;
    // 총이 없다면 생략
    if(gun[x][y].top() > use_gun[number]){
        //만약 해당 위치에 총이 있고, 사용중인 총보다 좋다면
        if(use_gun[number] != 0){
            //원래 있는 총을 내려놓음.
            gun[x][y].push(use_gun[number]);
        }
        use_gun[number] = gun[x][y].top();
        gun[x][y].pop();
    }
}

void update_dir(int number){
    int x = x_position[number];
    int y = y_position[number];
    int curr_dir = dir[number];
    int nx = x + dx[curr_dir];
    int ny = y + dy[curr_dir];
    while(!in_range(nx, ny) || matrix[nx][ny] != 0){
        curr_dir = (curr_dir + 1) % 4;
        nx = x + dx[curr_dir];
        ny = y + dy[curr_dir];
    }
    //방향 업데이트
    dir[number] = curr_dir;
}

void versus(int number1, int number2){
    // 총 데미지와 초기 데미지로 승부
    // 이긴 사람의 포인트를 업데이트 한다.
    // 진 사람은 move를 한번더 진행한다.
    // move를 진행할 때 막혀있는 경우 방향 회전을 진행
    // number2가 현재 matrix에 적혀있고
    // number1은 현재 matrix에 적혀있지 않음.
    int total_power1 = init_power[number1] + use_gun[number1];
    int total_power2 = init_power[number2] + use_gun[number2];
    int curr_x = x_position[number1];
    int curr_y = y_position[number1];
    if(total_power1 > total_power2 || (total_power1 == total_power2 &&
                                       init_power[number1] > init_power[number2])){
        if(use_gun[number2] > 0){
            gun[curr_x][curr_y].push(use_gun[number2]);
            use_gun[number2] = 0;
        }
        get_gun(curr_x, curr_y, number1);
        update_dir(number2);
        //방향을 바꾸는 기준이 다르기 때문에 방향 업데이트를 진행
        move(number2);
        matrix[curr_x][curr_y] = number1;
        point[number1] += total_power1 - total_power2;
    }
    else{
        if(use_gun[number1] > 0){
            gun[curr_x][curr_y].push(use_gun[number1]);
            use_gun[number1] = 0;
        }
        get_gun(curr_x, curr_y, number2);
        update_dir(number1);
        //방향을 바꾸는 기준이 다르기 때문에 방향 업데이트를 진행
        move(number1);
        matrix[curr_x][curr_y] = number2;
        point[number2] += total_power2 - total_power1;
    }
}

void move(int number){
    //현재 사람의 방향으로 움직인다.
    //만약 사람이 있다면 대결을 진행한다.
    //사람이 없다면 총이 있는지 확인하고
    //총이 없다면 사용하고, 아니면 가지고 있는 총과 비교한다.
    int x = x_position[number];
    int y = y_position[number];
    int curr_dir = dir[number];
    int nx = x + dx[curr_dir];
    int ny = y + dy[curr_dir];
    if(!in_range(nx, ny)){
        //격자 밖이라면 방향을 바꾼다.
        curr_dir = (curr_dir + 2) % 4;
        dir[number] = curr_dir;
        nx = x + dx[curr_dir];
        ny = y + dy[curr_dir];
    }
    if(matrix[x][y] == number){
        //현재 내 위치에 내 번호가 적혀있다면
        //즉, 대결에서 패배해서 움직이는 경우가 아니라면 0으로 만든다.
        matrix[x][y] = 0;
    }
    x = x_position[number] = nx;
    y = y_position[number] = ny;
    //좌표 업데이트
    if(matrix[nx][ny] != 0){
        //사람이 있다면
        versus(number, matrix[nx][ny]);
        //대결 진행
    }
    else{
        //사람이 없다면
        get_gun(x, y, number);
        //총 줍기
        matrix[x][y] = number;
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int num;
            cin >> num;
            if(num != 0){
                gun[i][j].push(num);
            }
            matrix[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        matrix[x][y] = i;
        x_position[i] = x;
        y_position[i] = y;
        dir[i] = d;
        init_power[i] = s;
        use_gun[i] = 0;
    }
    while(k--){
        for(int i = 1; i <= m; i++){
            move(i);
        }
    }
    for(int i = 1; i <= m; i++){
        cout << point[i] << ' ';
    }
    return 0;
}