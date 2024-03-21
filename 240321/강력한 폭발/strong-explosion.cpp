#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n;
int bomb_count = 0;
int matrix[21][21];
int answer = 0;
int cur_answer = 0;
int dx[3][4] ={{1, 2, -1, -2},{1, -1, 0, 0}, {1, 1, -1, -1}};
int dy[3][4] = {{0, 0, 0, 0}, {0, 0, 1, -1}, {1, -1, 1, -1}};
vector<int> v;
vector<pair<int, int>> bomb_position;
vector<pair<int, int>> area_position;

bool in_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void matrix_clear(){
    while(area_position.size() != 0){
        int x, y;
        tie(x, y) = area_position[area_position.size() - 1];
        matrix[x][y] = 0;
        area_position.pop_back();
    }
}

void calc_area(){
    for(int i = 0; i < bomb_position.size(); i++){
        int bomb_number = v[i];
        int x, y;
        tie(x, y) = bomb_position[i];
        for(int j = 0; j < 4; j++){
            int nx = x + dx[bomb_number][j];
            int ny = y + dy[bomb_number][j];
            if(in_range(nx, ny) && matrix[nx][ny] == 0){
                matrix[nx][ny] = 2;
                cur_answer++;
                area_position.push_back({nx, ny});
            }
        }
    }
    answer = max(answer, cur_answer);
}


void choose_num(int index){
    //폭탄의 종류 선택
    if(index > bomb_count){
        cur_answer = bomb_count;
        calc_area();
        matrix_clear();
        return;
    }
    for(int i = 0; i < 3; i++){
        v.push_back(i);
        choose_num(index + 1);
        v.pop_back();
    }
    
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                bomb_count++;
                bomb_position.push_back({i, j});
            }
        }
    }
    choose_num(1);
    cout << answer;
    return 0;
}