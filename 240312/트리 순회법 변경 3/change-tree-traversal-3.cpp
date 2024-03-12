#include <iostream>
#include <vector>
using namespace std;

/*
왼쪽 노드 오른쪽
왼쪽 오른쪽 노드
-> 노드 왼쪽 오른쪽
으로 바꿔야됨.
*/

vector<int> pre_order(100'001);
vector<int> in_order(100'001);
vector<int> post_order(100'001);

int n;
int cnt = 1;

void set_tree(int post_start, int post_end, int in_start, int in_end){
    if(post_start > post_end) return;
    if(post_start == post_end){
        pre_order[cnt++] = post_order[post_start];
        return;
    }
    pre_order[cnt++] = post_order[post_end];
    //전위 순회를 구성해야하므로 노드 먼저 탐색
    
    int root_index = -1;
    for(int i = in_start; i <= in_end; i++){
        if(post_order[post_end] == in_order[i]){
            root_index = i;
            break;
        }
    }
    int left_subtree_length = root_index - in_start;
    int right_subtree_length = in_end - root_index;

    //왼쪽 서브트리 탐색
    set_tree(post_start, post_start + left_subtree_length - 1, in_start, root_index - 1);

    //오른쪽 서브트리 탐색
    set_tree(post_end - right_subtree_length,post_end - 1, root_index + 1, in_end);
}
int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> in_order[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> post_order[i];
    }

    set_tree(1, n, 1, n);

    for(int i = 1; i <= n; i++){
        cout << pre_order[i] << " ";
    }
    return 0;
}