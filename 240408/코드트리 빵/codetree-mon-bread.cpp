#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

/*
격자 내에서 움직일 수 없는 위치는 2로
베이스 캠프 후보는 1로
움직일 수 있는 곳은 0으로

각자 편의점의 거리에서부터 베이스 캠프 고르기
-> 격자를 돌며 1인 경우 벡터에 넣고 정렬 기준으로 정렬해서 가장 가까운 베이스 캠프 고르기

편의점으로 이동
-> 편의점부터 bfs를 돌면서 각자마다 격자에 최단 거리를 입력하는데, 이때 탐색하는 위치가
사용자의 위치와 동일해진 경우 마지막으로 최단거리를 사용자와 인접한 곳에 적고, 종료한다.
사용자의 위치로부터 적힌 최단거리 중에 상/좌/우/하 순으로 탐색하며 사용자의 최단거리보다 -1인
곳을 찾는다.
*/

int n, m;
int move_matrix[16][16]; //사람들이 움직이는 격자
vector<pair<int, int>> exits(16, {0, 0}); //편의점 좌표 정보를 순서대로 기억
bool is_end[31]; //m번 사람이 도착했는지 체크하는 배열
bool tmp_end[31]; // 이번턴에 도착했는지 확인하는 배열
int x_position[31]; //m번 사람의 x좌표
int y_position[31]; //m번 사람의 y좌표

//m번 편의점에 대한 bfs를 할 때 m번 사람의 위치가 2일수도 있음.
//왜냐하면 다 이동을 한 뒤에 이동 불가 표시를 하기 때문에 2인 경우에 m번 사람의 위치와
//동일한지 확인해야 함.

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}


pair<int, int> choice(int number){
    queue<pair<int, int>> q;
    priority_queue<tuple<int, int, int>> pq;
    int x, y;
    tie(x, y) = exits[number];
    int dist[16][16];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 0;
        }
    }
    q.push({x, y});
    dist[x][y] = 1;
    int min_dist = 0;
    while(!q.empty()){
        int curr_x, curr_y;
        tie(curr_x, curr_y) = q.front();
        q.pop();
        if(min_dist != 0){
            if(dist[curr_x][curr_y] > min_dist) continue;
        }
        for(int i = 0; i < 4; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if(in_range(nx, ny) && dist[nx][ny] == 0 && move_matrix[nx][ny] != 2){
                if(move_matrix[nx][ny] == 1 && min_dist == 0){
                    min_dist = dist[curr_x][curr_y] + 1;
                }
                q.push({nx, ny});
                dist[nx][ny] = dist[curr_x][curr_y] + 1;
            }
        }
        if(move_matrix[curr_x][curr_y] == 1 && min_dist == dist[curr_x][curr_y]){
            pq.push({-dist[curr_x][curr_y], -curr_x, -curr_y});
        }
    }
    tie(ignore, x, y) = pq.top();
    return {-x, -y};
}

void move(int number){
    int person_x = x_position[number];
    int person_y = y_position[number];
    int x, y;
    tie(x, y) = exits[number];
    queue<pair<int, int>> q;
    int dist[16][16];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 0;
        }
    }
    q.push({x, y});
    dist[x][y] = 1;
    while(!q.empty()){
        int curr_x, curr_y;
        tie(curr_x, curr_y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            if(in_range(nx, ny) && dist[nx][ny] == 0){
                if(move_matrix[nx][ny] != 2){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[curr_x][curr_y] + 1;
                }
                else if(nx == person_x && ny == person_y){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[curr_x][curr_y] + 1;
                }
            }
        }
        if(curr_x == person_x && curr_y == person_y){
            //사람의 위치에 다다른 경우
            for(int i = 0; i < 4; i++){
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];
                if(dist[curr_x][curr_y] - 1 == dist[nx][ny]){
                    //이미 거리가 측정되어 있고 1 적은 경우가 다음 위치
                    x_position[number] = nx;
                    y_position[number] = ny;
                    if(nx == x && ny == y){
                        is_end[number] = tmp_end[number] = true;
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> move_matrix[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        exits[i] = {x, y};
        is_end[i] = false;
    }
    int time = 1;
    int count = m;
    while(count > 0){
        //사람이 편의점에 도착할때마다 count를 줄이고, count가 0이 되면 종료
        for(int i = 1; i < min(time, m + 1); i++){
            tmp_end[i] = false;
            if(!is_end[i]){
                move(i);
                //아직 도착하지 않은 사람은 움직인다.
            }
        }
        for(int i = 1; i < min(time, m + 1); i++){
            if(tmp_end[i]){
                //이번턴에 도착한 사람이 있다면 해당 위치를 이동불가로 표시
                count--;
                int x, y;
                tie(x, y) = exits[i];
                move_matrix[x][y] = 2;
            }
            if(count == 0){
                time--;
            }
        }
        if(time <= m){
            //베이스캠프 선정
            int x, y;
            tie(x, y) = choice(time);
            move_matrix[x][y] = 2;
            x_position[time] = x;
            y_position[time] = y;
        }
        time++;
    }
    cout << time;
    return 0;
}