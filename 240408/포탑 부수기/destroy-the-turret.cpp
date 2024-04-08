#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/**/
int n, m, k;
int towers[11][11];
int last_attack[11][11];
bool nice[11][11];
pair<int, int> last_position[11][11]; //직전 위치 저장용
bool visited[11][11];

bool cmp(pair<int, int> &a, pair<int, int> &b){
    int power1, last_time1, x1, y1;
    int power2, last_time2, x2, y2;
    tie(x1, y1) = a;
    tie(x2, y2) = b;
    power1 = towers[x1][y1];
    power2 = towers[x2][y2];
    last_time1 = last_attack[x1][y1];
    last_time2 = last_attack[x2][y2];
    if(power1 == power2){
        if(last_time1 == last_time2){
            if(x1 + y1 == x2 + y2){
                return y1 > y2;
            }
            return x1 + y1 > x2 + y2;
        }
        return last_time1 > last_time2;
    }
    return power1 < power2;
}

bool attack1(int x1, int y1, int x2, int y2){
    //레이저 공격
    //bfs를 돌리면서 다음 경로로 갈 수 있다면 다음 경로의 직전 위치를 저장한다.
    //현재 위치로 변경하고 데미지를 입는다.
    //만약 도착할 수 없다면 false를 리턴한다.
    queue<pair<int, int>> q; //bfs용 큐
    q.push({x1, y1});
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool is_succ = false;
    visited[x1][y1] = true;
    while(!q.empty()){
        int curr_x, curr_y;
        tie(curr_x, curr_y) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = (curr_x + dx[i] + n - 1) % n + 1;
            int ny = (curr_y + dy[i] + m - 1) % m + 1;
            if(!visited[nx][ny] && towers[nx][ny] != 0){
                last_position[nx][ny] = {curr_x, curr_y};
                if(nx == x2 && ny == y2){
                    towers[x2][y2] = max(0, towers[x2][y2] - towers[x1][y1]);
                    is_succ = true;
                    break;
                }
                else{
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if(is_succ) break;
    }
    if(is_succ){
        //목적지를 찾는데 성공했다면 경로에 데미지 입기
        int curr_x, curr_y;
        tie(curr_x, curr_y) = last_position[x2][y2];
        while(!(curr_x == x1 && curr_y == y1)){
            nice[curr_x][curr_y] = false;
            towers[curr_x][curr_y] =  max(0, towers[curr_x][curr_y] - towers[x1][y1] / 2);
            tie(curr_x, curr_y) = last_position[curr_x][curr_y];
        }

    }
    return is_succ;

}


void attack2(int x1, int y1, int x2, int y2){
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < 8; i++){
        int nx = (x2 + dx[i] + n - 1) % n + 1;
        int ny = (y2 + dy[i] + m - 1) % m + 1;
        if(nx == x1 && ny == y1){
            continue;
        }
        nice[nx][ny] = false;
        towers[nx][ny] =  max(0, towers[nx][ny] - towers[x1][y1] / 2);
    }
    towers[x2][y2] = max(0, towers[x2][y2] - towers[x1][y1]);
}


int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> towers[i][j];
        }
    }
    int turn = 1;
    while(k--){
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(towers[i][j] != 0){
                    v.push_back({i, j});
                }
                visited[i][j] = false;
                nice[i][j] = true;
            }
        }
        if(v.size() <= 1){
            continue;
        }
        sort(v.begin(), v.end(), cmp);
        int x1, y1, x2, y2;
        tie(x1, y1) = *v.begin();
        tie(x2, y2) = *v.rbegin();
        towers[x1][y1] += n + m;
        if(!attack1(x1, y1, x2, y2)){
            attack2(x1, y1, x2, y2);
        }
        nice[x1][y1] = false;
        nice[x2][y2] = false;
        last_attack[x1][y1] = turn;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(towers[i][j] != 0 && nice[i][j]){
                    towers[i][j]++;
                }
            }
        }
        turn++;
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            answer = max(answer, towers[i][j]);
        }
    }
    cout << answer;
    return 0;
}