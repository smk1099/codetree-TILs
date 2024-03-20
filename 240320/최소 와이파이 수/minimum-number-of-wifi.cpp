#include <iostream>

using namespace std;

int main() {
    int n, m;
    int arr[100];
    cin >> n >> m;
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            answer++;
            i += 2 * m;
        }
    }
    cout << answer;
    return 0;
}