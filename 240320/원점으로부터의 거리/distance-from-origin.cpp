#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b){
    int x1, y1, number1;
    int x2, y2, number2;
    tie(x1, y1, number1) = a;
    tie(x2, y2, number2) = b;
    if(abs(x1)+ abs(y1) == abs(x2) + abs(y2)){
        return number1 < number2;
    }
    return abs(x1)+ abs(y1) < abs(x2) + abs(y2);
}
int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y, i + 1};
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        int number;
        tie(ignore, ignore, number) = v[i];
        cout << number << "\n";
    }
    return 0;
}