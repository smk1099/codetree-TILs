#include <iostream>
#include <vector>
using namespace std;

vector<int> pre_order(10'001);
vector<int> post_order(10'001);
int n;
int cnt = 0;
void set_tree(int start, int end){
    if(start > end) return;
    if(start == end){
        post_order[cnt] = pre_order[start];
        cnt++;
        return;
    }
    int right_subtree_start = end + 1;
    for(int i = start + 1; i <= end; i++){
        if(pre_order[i] > pre_order[start]){
            right_subtree_start = i;
            break;
        }
    }

    set_tree(start + 1, right_subtree_start - 1);
    set_tree(right_subtree_start, end);

    post_order[cnt++] = pre_order[start];

}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pre_order[i];
    }

    set_tree(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << post_order[i] << "\n";
    }
    return 0;
}