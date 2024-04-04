#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
가장 많은 점을 포함하는 영역의 점의 개수의 최소?
직선이 점을 최대한 나눠야 함.
일단 입력을 받고, 해당 좌표까지의 누적합을 구하는데, N의 절반을 넘을때를 찾으면 됨.
넘는 좌표를 기준으로 해당 좌표의 누적합과 N - 그 전 좌표의 누적합을 비교함.
좌표의 누적합 > N - 그 전 좌표 누적합 : 해당 좌표의 -1에 그어야 함.
좌표의 누적합 < N - 그 전 좌표의 누적합 : 해당 좌표의 +1에 그어야 함.
*/

int n;
vector<int> x_pre_sum(1001, 0);
vector<int> y_pre_sum(1001, 0);
vector<int> x_position(1001, 0);
vector<int> y_position(1001, 0);

vector<pair<int, int>> positions;
vector<int> area_count(4, 0);
int main() {
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x_position[x]++;
        y_position[y]++;
        positions.push_back({x, y});
    }
    for(int i = 1; i < 1001; i++){
        x_pre_sum[i] = x_pre_sum[i - 1] + x_position[i];
        if(x_pre_sum[i] > n / 2){
            if(x_pre_sum[i] > n - x_pre_sum[i - 1]){
                a = i - 1;
            }
            else{
                a = i + 1;
            }
            break;
        }
    }
    for(int i = 1; i < 1001; i++){
        y_pre_sum[i] = y_pre_sum[i - 1] + y_position[i];
        if(y_pre_sum[i] > n / 2){
            if(y_pre_sum[i] >= n - y_pre_sum[i - 1]){
                b = i - 1;
            }
            else{
                b = i + 1;
            }
            break;
        }
    }

    for(int i = 0; i < positions.size(); i++){
        int curr_x, curr_y;
        tie(curr_x, curr_y) = positions[i];
        if(curr_x > a && curr_y > b){
            area_count[1]++;
        }
        else if(curr_x < a && curr_y > b){
            area_count[0]++;
        }
        else if(curr_x < a && curr_y < b){
            area_count[3]++;
        }
        else{
            area_count[2]++;
        }
    }
    sort(area_count.begin(), area_count.end());

    cout << *area_count.rbegin();

    return 0;
}