#include <iostream>
#include <vector>
using namespace std;

/*
전위 순회에서 첫번째 수는 루트
중위 순회에서 루트 앞으로는 왼쪽 서브트리, 루트 뒤로는 오른쪽 서브트리
후위 순회에서는 왼쪽 서브트리 오른쪽 서브트리 루트 순으로 탐색.
*/

vector<int> pre_order(100'001);
vector<int> in_order(100'001);
vector<int> post_order(100'001);
int n;
int cnt = 1;
void set_tree(int start, int end, int in_start, int in_end){
    //전위 순회에서 시작과 끝, 중위 순회에서 시작과 끝.
    if(start > end) return;
    if(start == end){
        post_order[cnt++] = pre_order[start];
        return;
    }


    int left_subtree_length = 0;
    for(int i = in_start; i <= in_end; i++){
        if(pre_order[start] == in_order[i]){
            break;
        }
        left_subtree_length++;
    }

    set_tree(start + 1, start + left_subtree_length, in_start, in_start + left_subtree_length - 1);
    //왼쪽 서브트리
    set_tree(start + left_subtree_length + 1, end, in_start + left_subtree_length + 1, in_end);
    //오른쪽 서브트리

    //루트를 마지막으로 탐색
    post_order[cnt++] = pre_order[start];
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pre_order[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> in_order[i];
    }

    set_tree(1, n, 1, n);

    for(int i = 1; i <= n; i++){
        cout << post_order[i] << " ";
    }
    
    return 0;
}