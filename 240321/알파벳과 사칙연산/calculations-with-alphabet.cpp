#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int alphabet_count = 0;
int alphabet_position[8]; //v에서 알파벳의 위치.
vector<int> v;
int answer = INT_MIN;
string input_str;
void is_count(char c){
    if(alphabet_position[(int)(c - 'a')] == -1){
        alphabet_position[(int)(c-'a')] =  alphabet_count++;;
    }
}

void calc(){
    int cur_answer = 0;
    int cur_num = 0;
    int state = 1;
    for(int i = 0; i < input_str.size(); i++){
        if(i % 2 == 0){
            cur_num = v[alphabet_position[(int)(input_str[i] - 'a')]];
            if(state == 1){
                cur_answer += cur_num;
            }
            else if(state == 2){
                cur_answer -= cur_num;
            }
            else{
                cur_answer *= cur_num;
            }
        }
        else{
            switch(input_str[i]){
                case '+':
                state = 1;
                break;
                case '-':
                state = 2;
                break;
                case '*':
                state = 3;
                break;
            }
        }
    }
    answer = max(answer, cur_answer);
}

void choose_num(int index){
    if(index >= alphabet_count){
        calc();
        return;
    }
    for(int i = 1; i <= 4; i++){
        v.push_back(i);
        choose_num(index + 1);
        v.pop_back();
    }
}
int main() {
    cin >> input_str;
    for(int i = 0; i < 8; i++){
        alphabet_position[i] = -1;
    }
    for(int i = 0; i < input_str.size(); i++){
        if(i % 2 == 0){
            is_count(input_str[i]);
        }
    }
    choose_num(0);
    cout << answer;
    return 0;
}