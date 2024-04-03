#include <iostream>

using namespace std;

/*
폭탄 번호별로 마지막 등장 위치를 저장해놓고
폭탄이 등장할 때 마지막 위치와 현재 위치의 차가 K보다 작거나 같으면
answer = max(answer, 현재 폭탄의 번호)
*/
int last_bomb_position[1'000'001];

int main() {
    int n, k;
    cin >> n >> k;
    int answer = -1;
    int curr_position = 1;
    while(n--){
        int bomb_number;
        cin >> bomb_number;
        if(last_bomb_position[bomb_number] != 0){
            if(curr_position - last_bomb_position[bomb_number] <= k){
                answer = max(answer, bomb_number);
            }
        }
        last_bomb_position[bomb_number] = curr_position;
        curr_position++;
    }
    cout << answer;
    return 0;
}