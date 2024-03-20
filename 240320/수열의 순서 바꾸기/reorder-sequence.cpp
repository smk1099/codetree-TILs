#include <iostream>

using namespace std;

/*
앞에서 뒤로는 보낼 수 있으니 뒤에서부터 정렬된 애까지는 건드리지 않아도 됨.
모든 원소의 개수 - 뒤에서부터 정렬된 원소들의 개수가 답.
*/
int main() {
    int n;
    cin >> n;
    int arr[100];
    int len = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n - 2; i >= 0; i--){
        if(arr[i + 1] > arr[i]){
            len++;
        }
        else{
            break;
        }
    }
    cout << n - len;
    return 0;
}