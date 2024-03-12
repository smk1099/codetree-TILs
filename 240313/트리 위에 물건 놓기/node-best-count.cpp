#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
dp[i][0] -> i번째 노드를 칠하지 않았을때 나올 수 있는 최대값
dp[i][1] -> i번째 노드를 칠했을때 나올 수 있는 최대값

dp[i][0] = dp[i의 자식 노드][1]들의 합
dp[i][1] = dp[i의 자식 노드][0]들의 합 + 자신의 값

리프노드의 경우는 dp[i][0] = 0, dp[i][1] = 자신의 값


이 문제에서는 dp[i][0] -> 해당 노드에 물건을 놓지 않았을때 최소 물건의 수
dp[i][1] -> 해당 노드에 물건을 놓았을 때 최소 물건의 수

dfs(1)을 돌린후에 dp[1][0]과 dp[1][1] 중에 더 작은 수를 찾으면 됨.
*/
int n;
vector<int> graph[100'001];
vector<int> visited(100'001, 0);
vector<vector<int>> dp(100'001, vector<int> (2, 0));

void dfs(int number){
    visited[number] = 1;
    for(int i = 0 ; i < graph[number].size(); i++){
        int next_number = graph[number][i];
        if(visited[next_number] == 0){
            dfs(next_number);
        }
    }

    dp[number][1] += 1;
    for(int i = 0; i < graph[number].size(); i++){
        int next_number = graph[number][i];
        dp[number][1] += min(dp[next_number][0], dp[next_number][1]);
        dp[number][0] += dp[next_number][1];
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}