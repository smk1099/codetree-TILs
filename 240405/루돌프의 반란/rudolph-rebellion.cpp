#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

/*
게임판의 크기, 게임 턴 수, 산타의 수, 루돌프의 힘, 산타의 힘 순으로 입력

루돌프에 대한 산타들의 거리를 매 움직임마다 갱신
*/

int santa_score[31]; //산타 점수 저장 배열
int santa_state[31];
int game_board[51][51]; // 게임 판
int n, m, p, c, d;
int curr_monster_x = 0;
int curr_monster_y = 0;
//루돌프 위치

int calc_dis(int x, int y){
    int x_gap = x - curr_monster_x;
    int y_gap = y - curr_monster_y;
    return x_gap * x_gap + y_gap * y_gap;
}

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b){
    int a_x, a_y;
    int b_x, b_y;
    tie(ignore, a_x, a_y) = a;
    tie(ignore, b_x, b_y) = b;
    if(calc_dis(a_x, a_y) == calc_dis(b_x, b_y)){
        if(a_x == b_x){
            return a_y > b_y;
        }
        return a_x > b_x;
    }
    return calc_dis(a_x, a_y) < calc_dis(b_x, b_y);
}
//정렬 기준
vector<tuple<int, int, int>> santa_v;
int santa_dx[4] = {-1, 0, 1, 0};
int santa_dy[4] = {0, 1, 0, -1};
//산타 움직임

bool in_range(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

int main() {
    cin >> n >> m >> p >> c >> d;
    cin >> curr_monster_x >> curr_monster_y;
    for(int i = 0; i < p; i++){
        int santa_number, x, y;
        cin >> santa_number >> x >> y;
        game_board[x][y] = santa_number;
        santa_v.push_back({santa_number, x, y});
    }
    while(m--){
        sort(santa_v.begin(), santa_v.end(), cmp);
        //루돌프의 현재 위치에 따른 산타 정렬
        // cout << "--------\n";
        // cout << "루돌프 x : " << curr_monster_x << " y : " << curr_monster_y << "\n";
        // for(int i = 0; i < santa_v.size(); i++){
        //     int num, x, y;
        //     tie(num, x, y) = santa_v[i];
        //     cout << num << " " << x << " " << y << " " << "\n";
        // }
        // for(int i = 1; i <=n; i++){
        //     for(int j = 1; j <= n; j++){
        //         cout << game_board[i][j] << ' ';
        //     }
        //     cout << "\n";
        // }
        // cout << "--------\n";

        //루돌프 움직임 시작
        //탈락하지 산타 중에 가장 가까운 산타 정보 획득
        int closest_number;
        int closest_x = -1;
        int closest_y = -1;
        for(int i = 0; i < santa_v.size(); i++){
            tie(closest_number, ignore, ignore) = santa_v[i];
            if(santa_state[closest_number] != 3){
                tie(closest_number, closest_x, closest_y) = santa_v[i];
                break;
            }
        }
        if(closest_x == -1){
            //모든 산타 탈락한 경우
            break;
        }
        int move_x = 0;
        int move_y = 0;

        if(closest_x < curr_monster_x){
            curr_monster_x--;
            move_x = -c;
        }
        else if(closest_x > curr_monster_x){
            curr_monster_x++;
            move_x = c;
        }
        if(closest_y < curr_monster_y){
            curr_monster_y--;
            move_y = -c;
        }
        else if(closest_y > curr_monster_y){
            curr_monster_y++;
            move_y = c;
        }
        //루돌프 움직임 끝

        //산타 번호순으로 정렬
        sort(santa_v.begin(), santa_v.end());

        //부딪힘 판정
        if(curr_monster_x == closest_x && curr_monster_y == closest_y){
            santa_score[closest_number] += c;
            //점수 획득
            game_board[closest_x][closest_y] = 0;
            int nx = closest_x + move_x;
            int ny = closest_y + move_y;
            if(!in_range(nx, ny)){
                santa_state[closest_number] = 3;
                get<1>(santa_v[closest_number - 1]) = nx;
                get<2>(santa_v[closest_number - 1]) = ny;
                //탈락 처리
            }
            else{
                santa_state[closest_number] = 2;
                //기절 처리
                int move_number = closest_number;
                //현재 움직이는 산타의 번호
                while(game_board[nx][ny] != 0){
                    //다음 위치에 산타가 있는 경우 계속 반복

                    int next_number = game_board[nx][ny];
                    //이미 게임판에 존재하는 산타의 번호 저장

                    game_board[nx][ny] = move_number;
                    //게임판에 움직이는 산타 번호 저장
                    get<1>(santa_v[move_number - 1]) = nx;
                    get<2>(santa_v[move_number - 1]) = ny;
                    // 벡터 정보도 업데이트

                    nx = nx + move_x / c;
                    ny = ny + move_y / c;
                    //다음 밀려나는 산타는 c만큼이 아닌 1만큼만 이동
                    if(!in_range(nx, ny)){
                        santa_state[next_number] = 3;
                        get<1>(santa_v[move_number - 1]) = nx;
                        get<2>(santa_v[move_number - 1]) = ny;
                        //게임판 밖으로 밀려난 경우 탈락처리
                        break;
                    }
                    move_number = next_number;
                }
                if(santa_state[move_number] != 3){
                    //탈락 처리가 되지 않은 산타의 경우
                    game_board[nx][ny] = move_number;
                    get<1>(santa_v[move_number - 1]) = nx;
                    get<2>(santa_v[move_number - 1]) = ny;
                }

            }
        }
        
        //산타 움직임 시작

        for(int i = 0; i < santa_v.size(); i++){
            int curr_number, curr_x, curr_y;
            int move_dir = -1;
            tie(curr_number, curr_x, curr_y) = santa_v[i];
            //기절 혹은 탈락 산타 처리
            if(santa_state[curr_number] == 3){
                continue;
            }
            else if(santa_state[curr_number] > 0){
                santa_state[curr_number]--;
                continue;
            }
            int max_gap = 0;
            //루돌프와의 거리가 최대로 줄어드는 거리를 저장.
            for(int j = 0; j < 4; j++){
                int nx = curr_x + santa_dx[j];
                int ny = curr_y + santa_dy[j];
                if(in_range(nx, ny) && game_board[nx][ny] == 0 
                && calc_dis(curr_x, curr_y) > calc_dis(nx, ny)){
                    //움직이는 다음 위치가 게임판 안에 있으며
                    //아무런 산타도 없고
                    //현재 거리보다 줄어드는 경우
                    if(move_dir == -1){
                        move_dir = j;
                        max_gap = calc_dis(curr_x, curr_y) - calc_dis(nx, ny);
                    }
                    else if(max_gap < calc_dis(curr_x, curr_y) - calc_dis(nx, ny)){
                        move_dir = j;
                        max_gap = calc_dis(curr_x, curr_y) - calc_dis(nx, ny);
                    }
                    //최대로 거리를 좁일 수 있는 방향을 구함.
                }

            }
            if(move_dir == -1){
                continue;
                //움직일 수 없으면 다음 산타로 이동.
            }
            else{
                //가장 거리가 많이 줄어드는 곳으로 이동.
                int nx = curr_x + santa_dx[move_dir];
                int ny = curr_y + santa_dy[move_dir];
                game_board[curr_x][curr_y] = 0;
                get<1>(santa_v[i]) = curr_x = nx;
                get<2>(santa_v[i]) = curr_y = ny;
                game_board[curr_x][curr_y] = curr_number;

            }
            //루돌프 부딪힘 판정
            if(curr_x == curr_monster_x && curr_y == curr_monster_y){
                santa_score[curr_number] += d;
                //산타 점수 획득
                move_dir = (move_dir + 2) % 4;
                //방향 전환

                int move_x = santa_dx[move_dir] * d;
                int move_y = santa_dy[move_dir] * d;
                //움직일 거리

                int nx = curr_x + move_x;
                int ny = curr_y + move_y;
                //다음 위치 계산

                game_board[curr_x][curr_y] = 0;

                if(!in_range(nx, ny)){
                    //게임판에 벗어나는 경우
                    santa_state[curr_number] = 3;
                    get<1>(santa_v[curr_number - 1]) = nx;
                    get<2>(santa_v[curr_number - 1]) = ny;
                    //탈락처리
                }
                else{
                    santa_state[closest_number] = 1;
                    //기절 처리
                    int move_number = curr_number;
                    //현재 움직이는 산타의 번호
                    while(game_board[nx][ny] != 0){
                        //다음 위치에 산타가 있는 경우 계속 반복

                        int next_number = game_board[nx][ny];
                        //이미 게임판에 존재하는 산타의 번호 저장

                        game_board[nx][ny] = move_number;
                        //게임판에 움직이는 산타 번호 저장
                        get<1>(santa_v[move_number - 1]) = nx;
                        get<2>(santa_v[move_number - 1]) = ny;
                        // 벡터 정보도 업데이트

                        nx = nx + move_x / d;
                        ny = ny + move_y / d;
                        //다음 밀려나는 산타는 c만큼이 아닌 1만큼만 이동
                        if(!in_range(nx, ny)){
                            santa_state[next_number] = 3;
                            get<1>(santa_v[move_number - 1]) = nx;
                            get<2>(santa_v[move_number - 1]) = ny;
                            //게임판 밖으로 밀려난 경우 탈락처리
                            break;
                        }
                        move_number = next_number;
                    }
                    if(santa_state[move_number] != 3){
                        //탈락 처리가 되지 않은 산타의 경우
                        game_board[nx][ny] = move_number;
                        get<1>(santa_v[move_number - 1]) = nx;
                        get<2>(santa_v[move_number - 1]) = ny;
                    }
                }
            }
        }
        for(int i = 1; i <= p; i++){
            if(santa_state[i] != 3){
                //탈락하지 않은 산타는 1점 부여
                santa_score[i]++;
            }
        }
    }

    for(int i = 1; i <= p; i++){
        cout << santa_score[i] << ' ';
    }
    return 0;
}