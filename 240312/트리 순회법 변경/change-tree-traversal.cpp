#include <iostream>
#include <vector>
using namespace std;

/*
전위 순회는 어쨋든 부모를 먼저 체크하는 것.
나보다 작은 수면 바로 내 왼쪽 자식으로 설정.
나보다 큰 수면 부모 숫자보다 큰지 확인해서 
부모의 숫자보다 크면 과정을 반복하고 아니면 내 오른쪽 자식으로 설정
*/
int n;
vector<int> left_child(1'000'001, -1);
vector<int> right_child(1'000'001, -1);
vector<int> parent(1'000'001, -1);
void post_order(int node){
    if(node == -1) return;
    post_order(left_child[node]);
    post_order(right_child[node]);
    cout << node << "\n";
}
int main() {
    cin >> n;
    int curr_num, input_num, parent_num;
    //현재 노드, 입력 노드, 현재 노드의 부모 노드
    int root = -1;
    cin >> curr_num;
    root = curr_num;
    for(int i = 1; i < n; i++){
        cin >> input_num;
        if(curr_num > input_num){
            left_child[curr_num] = input_num;
            parent[input_num] = curr_num;
        }
        else{
            while(curr_num < input_num){
                parent_num = parent[curr_num];
                if(parent_num == -1){
                    right_child[curr_num] = input_num;
                    break;
                }
                else if(parent_num > input_num){
                    right_child[curr_num] = input_num;
                    parent[input_num] = parent_num;
                    break;
                }
                curr_num = parent_num;
            }
        }
        curr_num = input_num;
    }
    post_order(root);
    return 0;
}