#include <iostream>

using namespace std;

int arr[21][21];
int n;
bool in_range(int x){
    return x >= 0 && x + 2 < n ;
}

int main() {
    int answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int curr_sum = 0;
            if(in_range(j)){
                for(int x = j; x <= j + 2; x++){
                    curr_sum += arr[i][x];
                }
            }
            answer = max(answer, curr_sum);
        }
        
    }
    cout << answer;
    return 0;
}