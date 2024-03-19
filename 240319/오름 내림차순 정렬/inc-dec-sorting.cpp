#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int &x, int &y){
    return x > y;
}

int main() {
    int arr[101];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}