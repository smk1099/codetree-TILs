#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

/*
갈림길이 있을 때 한번씩 돌아가면서 떨어진다.
예를 들어 첫번째 갈림길인 경우에는 짝수번째 홀수번째 이런식으로
그러면 n번째 공이 어느 갈림길에서 어디로 가는지 알 수 있을까?
짝수인가? -> 일단 첫번째 갈림길에서 오른쪽
2로 나눈 수에서 짝수인가? -> 두번째 갈림길에서도 오른쪽
그런식으로 하면 일단 수가 주어지고 나서 2로 나눈다. -> 짝수인지 홀수인지 판정한다
그리고 나서 갈림길을 찾고, 갈림길이 나오면 짝수 혹은 홀수에 따라 길을 옮긴다.
2를 나누고 갈림길을 찾는 과정을 반복. 단, 리프노드가 나올경우 그 곳이 정답.
2로 나눠서 홀수 -> 왼쪽
짝수 -> 오른쪽
*/

vector<pair<int, int>> tree(200001, {-1, -1});
//first가 왼쪽, second가 오른쪽 자식 노드 번호를 저장하는 이진 트리.
int n;
long long k;
bool find_answer = false;
//리프 노드에 도착하면 true로 저장
int answer = -1;
long long curr_k = 0;

int find_sub_tree(int number){
    //number에서 시작해서 다음 서브트리의 루트 번호를 찾는 함수.
    int left, right;
    tie(left, right) = tree[number];
    if(left == -1 && right == -1){
        //리프노드인 경우 정답을 체크하고 리턴.
        find_answer = true;
        answer = number;
        return number;
    }
    else if(left != -1 && right != -1){
        return number;
    }
    else if(left != -1){
        return find_sub_tree(left);
    }
    else if(right != -1){
        return find_sub_tree(right);
    }
}

int find_next(int number){
    //number 노드에서부터 다음 출발 노드 번호를 찾는 작업.
    int left, right;
    tie(left, right) = tree[number];
    int next_root;
    if(curr_k % 2 == 1){
        //현재 k가 홀수인 경우
        //현재 갈림길에서 왼쪽으로 이동.
        next_root = find_sub_tree(left);
        curr_k = (long long)(curr_k / 2 + 1);
    }
    else{
        next_root = find_sub_tree(right);
        curr_k = (long long)(curr_k / 2);
    }
    return next_root;
    
};
int main() {

    cin >> n;
    for(int i = 1; i <= n; i++){
        int n1, n2;
        cin >> n1 >> n2;
        tree[i] = {n1, n2};
    }
    cin >> k;
    curr_k = k;
    int next_number = find_next(1);
    while(!find_answer){
        next_number = find_next(next_number);
    }
    cout << answer;
    return 0;
}