#include <iostream>

using namespace std;

int parent[100'001];

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        int root = find(parent[a]);
        parent[a] = root;
        return root;
    }
}

void combine(int a, int b){
    parent[find(a)] = parent[find(b)];
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    while(m--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            combine(a, b);
        }
        else{
            if(parent[a] == parent[b]){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}