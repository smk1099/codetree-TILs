#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

/*
도착과 번호를 오름차순으로 정렬하고, 현재 시간을 계속 유지
사람이 기다린 시간 -> max(0, 입장하는 시간 - 도착시간)
- 현재 시각을 기준으로 정렬된 벡터에서 입장시간보다 작거나 같은 애들 모두 pq에 삽입
이때 pq는 번호 도착 즐기기 시간으로 삽입
다 넣고 나서 pq에서 pop을 해서 현재시간 및 기다린 시간 갱신
그 다음 다시 이 작업을 반복
*/



int main() {
    int n;
    int answer = 0;
    int curr_time = 0;
    cin >> n;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int arrival_time, enjoy_time;
        cin >> arrival_time >> enjoy_time;
        v.push_back({arrival_time, i + 1, enjoy_time});
    }
    sort(v.begin(), v.end());
    int index = 0;
    int curr_delay_time = 0;
    int count = 0;
    priority_queue<tuple<int, int, int>> pq;
    //현재 대기중인 손님들의 큐
    while(count < n){
        int arrival_time, enjoy_time;
        if(pq.empty()){
            tie(arrival_time, ignore, enjoy_time) = v[index];
            curr_delay_time = max(0, curr_time - arrival_time);
            answer = max(answer, curr_delay_time);
            if(arrival_time > curr_time){
                curr_time = arrival_time + enjoy_time;
            }
            else{
                curr_time += enjoy_time;
            }
            index++;
        }
        else{
            tie(ignore, arrival_time, enjoy_time) = pq.top();
            pq.pop();
            curr_delay_time = max(0, curr_time - arrival_time);
            answer = max(answer, curr_delay_time);
            curr_time += enjoy_time;
        }
        for(index; index < n; index++){
            int next_a_time, next_number, next_e_time;
            tie(next_a_time, next_number, next_e_time) = v[index];
            if(curr_time < next_a_time){
                break;
            }
            pq.push({-next_number, next_a_time, next_e_time});
        }
        count++;
    }
    cout << answer;
    return 0;
}