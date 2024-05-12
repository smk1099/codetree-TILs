#include <iostream>

using namespace std;

int n, m;

int graph[101][101];
int visited[101];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = (int)1e9;
        }
        visited[i] = 0;
    }
    while(m--){
        int s, e, d;
        cin >> s >> e >> d;
        graph[s][e] = d;
    }
    visited[1] = 1;
    for(int i = 1; i < n; i++){
        int min_index = -1;
        for(int j = 1; j <= n; j++){
            if(visited[j] == 1){
                continue;
            }
            if(min_index == -1){
                min_index = j;
            }
            else if(graph[1][min_index] > graph[1][j]){
                min_index = j;
            }
        }
        if(min_index == -1) break;
        visited[min_index] = 1;
        for(int j = 1; j <= n; j++){
            graph[1][j] = min(graph[1][j], graph[1][min_index] + graph[min_index][j]);
        }
    }
    for(int i = 2; i <= n; i++){
        if(graph[1][i] == (int)1e9){
            graph[1][i] = -1;
        }
    }
    for(int i = 2; i <= n; i++){
        cout << graph[1][i] << "\n";
    }
    return 0;
}