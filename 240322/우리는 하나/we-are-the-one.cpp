#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

/*
일단 in_range를 확인하고, 갈수 있으면, 내 도시에 적힌 번호를 전파.
하지만, 만약 이미 최대 개수가 적혀있다면? 가지 않음.
*/

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, k, u, d;
int answer = 0;
queue<pair<int, int>> q;
vector<int> city_count_v;
int matrix[8][8];
int city_number[8][8];
int cur_number = 0;
bool in_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y){
    q.push({x, y});
    city_number[x][y] = cur_number++;
    int city_count = 1;
    while(!q.empty()){
        tie(x, y) = q.front();
        q.pop();
        int cur_height = matrix[x][y];
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(in_range(nx, ny) && city_number[nx][ny] == -1){
                int next_height = matrix[nx][ny];
                int gap_height = abs(next_height - cur_height);
                if(gap_height >= u && gap_height <= d){
                    city_number[nx][ny] = city_number[x][y];
                    q.push({nx, ny});
                    city_count++;
                }
            }
        }
    }
    city_count_v.push_back(city_count);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> u >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            city_number[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(city_number[i][j] == -1){
                bfs(i, j);
            }
        }
    }
    sort(city_count_v.begin(), city_count_v.end());
    for(int i = city_count_v.size() - 1; i >= 0; i--){
        if(k == 0){
            break;
        }
        answer += city_count_v[i];
        k--;
    }
    cout << answer;



    return 0;
}