#include <iostream>

using namespace std;

/*
1.B찾기
2. B를 찾고 그 다음 행과 열에서 W 찾기 단, r, c - 1까지만 찾기
*/

int arr[16][16];
int r,c;
int main() {
    cin >> r >> c;
    int answer = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char color;
            cin >> color;
            if(color == 'W'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }
    int start = arr[0][0];
    int end = arr[r - 1][c - 1];
    for(int i = 1; i < r - 1; i++){
        for(int j = 1; j < c - 1; j++){
            if(arr[i][j] == 1 - start){
                for(int x = i + 1; x < r - 1; x++){
                    for(int y = j + 1; y < c - 1; y++){
                        if(arr[x][y] == start && arr[x][y] == 1- end){
                            answer++;
                        }
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}