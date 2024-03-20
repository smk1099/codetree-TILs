#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int min_val = 101;
    for(int i = 0; i < n; i++){
        min_val = min(min_val, arr[i]);
    }
    int second_val = 101;
    for(int i = 0; i < n; i++){
        if(arr[i] == min_val) continue;
        second_val = min(second_val, arr[i]);
    }
    int answer = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == second_val){
            if(answer != -1){
                answer = -1;
                break;
            }
            answer = i + 1;
        }
    }
    cout << answer;

    return 0;
}