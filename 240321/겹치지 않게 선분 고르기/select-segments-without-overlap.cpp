#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int n;
set<pair<int, int>> s;
vector<pair<int, int>> v;
int answer = 0;

bool possible(pair<int, int> line){
    for(auto it = s.begin(); it != s.end(); it++){
        int x1, x2;
        tie(x1, x2) = *it;
        if(x2 < line.first) continue;
        else if(line.second < x1) break;
        else return false;
    }
    return true;
}
void choose_line(int index){
    if(index >= n){
        answer = max(answer, (int)s.size());
        return;
    }
    if(possible(v[index])){
        set<pair<int, int>>::iterator it = s.insert(v[index]).first;
        choose_line(index + 1);
        s.erase(it);
    }
    choose_line(index + 1);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }
    choose_line(0);
    cout << answer;
    return 0;
}