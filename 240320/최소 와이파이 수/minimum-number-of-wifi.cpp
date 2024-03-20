#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num == 1){
            answer++;
            i += 2 * m;
        }
    }
    cout << answer;
    return 0;
}