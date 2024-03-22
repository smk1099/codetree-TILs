#include <iostream>

using namespace std;

int uf[100'001];

int find(int a){
    if(uf[a] == a){
        return a;
    }
    else{
        int root = find(uf[a]);
        uf[a] = root;
        return root;
    }
}

void combine(int x, int y){
    uf[find(x)] = uf[find(y)];
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int answer = 1;
    int cur_uf = 0;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        combine(x, y);
    }
    while(k--){
        int num;
        cin >> num;
        if(cur_uf == 0){
            cur_uf = find(num);
        }
        else{
            if(cur_uf != find(num)){
                answer = 0;
                break;
            }
        }
    }
    cout << answer;

    return 0;
}