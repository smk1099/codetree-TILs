#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;


int main() {
    priority_queue<tuple<int, int, int>> pq;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pq.push({-(abs(x) + abs(y)), -x, -y});
    }
    for(int i = 0 ; i < m; i++){
        int x, y;
        tie(ignore, x, y) = pq.top();
        pq.pop();
        x -= 2;
        y -= 2;
        pq.push({-(abs(x) + abs(y)), x, y});
    }
    int x, y;
    tie(ignore, x, y) = pq.top();
    cout << -x << " " << -y;
    return 0;
}