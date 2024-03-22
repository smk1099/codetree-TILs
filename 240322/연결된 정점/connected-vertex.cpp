#include <iostream>

using namespace std;

int uf[100'001];
int vertex_count[100'001];

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
    vertex_count[find(y)] += vertex_count[find(x)];
    uf[find(x)] = uf[find(y)];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
        vertex_count[i] = 1;
    }
    while(m--){
        char q;
        int a, b;
        cin >> q;
        if(q == 'x'){
            cin >> a >> b;
            combine(a, b);
        }
        else{
            cin >> a;
            cout << vertex_count[find(a)] << "\n";
        }
    }

    return 0;
}