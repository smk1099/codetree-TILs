#include <iostream>
/*
짝수와 홀수 개수 맞추기 문제
짝수 = 홀수 인 경우 : 짝 홀 짝 홀 ... 로 묶음의 수는 홀수의 개수 * 2
짝수 > 홀수 인 경우 : 짝수의 개수 + 1 = 홀수의 개수로 맞추면 홀수의 개수 * 2 + 1
짝수 < 홀수 인 경우 : 홀수를 두개 더해서 짝수로 만들어 갯수를 같거나 짝수가 더 크게 만든다. 

*/

using namespace std;
int main() {
    int n;
    int odd = 0;
    int even = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    while(odd > even){
        odd -= 2;
        even++;
    }
    if(odd == even){
        cout << odd * 2;
    }
    else{
        cout << odd * 2 + 1;
    }
    return 0;
}