#include <iostream>

using namespace std;

int count = 0;
int answer = 0;
int matrix[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

bool in_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}


int main() {
    cin >> n;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            count = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(in_range(nx, ny) && matrix[nx][ny] == 1){
                    count++;
                }
            }
            if(count >= 3){
                answer++;
            }
        }
    }
    

    cout << answer;



    return 0;
}