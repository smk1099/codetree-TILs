#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(101);
int main() {
    int n;
    int answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i] <= arr[j] && arr[j] <= arr[k]){
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}