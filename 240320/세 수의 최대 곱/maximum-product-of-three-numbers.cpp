#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[100000];
    int positive = 0;
    int zero = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > 0){
            positive++;
        }
        else if(arr[i] == 0){
            zero++;
        }
    }
    sort(arr, arr + n);
    if(positive == 0 && zero != 0){
        answer = 0;
    }
    else if(positive == 1 || positive == 2){
        answer = arr[0] * arr[1] * arr[n - 1];
    }
    else{
        answer = arr[n - 1] * arr[n - 2] * arr[n - 3];
        answer = max(answer, arr[0] * arr[1] * arr[n - 1]);
    }

    cout << answer;
    return 0;
}