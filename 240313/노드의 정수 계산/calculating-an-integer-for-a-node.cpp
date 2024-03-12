#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100'001];
vector<int> visited(100'001, 0);
vector<int> values(100'001, 0);
vector<int> dp(100'001, 0);
int n;

void dfs(int number){
    visited[number] = 1;
    for(int i = 0; i < graph[number].size(); i++){
        int next_number = graph[number][i];
        if(visited[next_number] == 0){
            dfs(next_number);
        }
    }

    dp[number] += values[number];
    for(int i = 0; i < graph[number].size(); i++){
        int next_number = graph[number][i];
        if(dp[next_number] < 0){
            continue;
        }
        dp[number] += dp[next_number];
    }
}
int main() {
    cin >> n;
    for(int i = 2; i <= n; i++){
        int t, a, p;
        cin >> t >> a >> p;
        if(t == 0){
            a = -a;
        }
        values[i] = a;
        graph[p].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}