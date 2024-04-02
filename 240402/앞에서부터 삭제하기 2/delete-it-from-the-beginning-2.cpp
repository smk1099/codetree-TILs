#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

/*
뒤에서부터 입력받는다고 생각하고, 하나씩 입력하는데
최소값만 빼고 평균 구하기
*/
int arr[100'000];
int main() {
    double answer = 0;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    int min_number = arr[n - 1];
    answer = arr[n - 1];
    double sum = 0;
    int count = 1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < min_number){
            sum += min_number;
            min_number = arr[i];
        }
        else{
            sum += arr[i];
        }
        answer = max(answer, sum / count);
        count++;
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;
    return 0;
}