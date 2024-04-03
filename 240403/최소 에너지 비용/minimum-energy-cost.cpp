#include <iostream>

using namespace std;
/*
왼쪽에서 오른쪽까지 가는데 필요한 총 비용 계산
지금까지의 충전소중에 최소 비용의 충전소를 저장
이동 시에 다음 이동까지 필요한 에너지를 최소 비용 충전소에서 충전하면 됨.
*/

int min_charge_number[100'001];
int charge_cost[100'001];
int move_cost[100'001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> move_cost[i];
    }
    cin >> charge_cost[1];
    int min_cost = charge_cost[1];
    min_charge_number[1] = 1;
    for(int i = 2; i <= n; i++){
        cin >> charge_cost[i];
        if(min_cost > charge_cost[i]){
            min_cost = charge_cost[i];
            min_charge_number[i] = i; 
        }
        else{
            min_charge_number[i] = min_charge_number[i - 1];
        }
    }
    long long answer = 0;
    for(int i = 1; i < n; i++){
        answer += move_cost[i] * charge_cost[min_charge_number[i]];
    }

    cout << answer;
    return 0;
}