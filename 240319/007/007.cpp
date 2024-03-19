#include <iostream>
#include <tuple>
using namespace std;

class Secret{
    public:
    string place;
    string code;
    int time;
    Secret(string place, string code, int time){
        this->place = place;
        this->code = code;
        this->time = time;
    }
};

int main() {
    string place, code;
    int time;
    cin >> place >> code >> time;
    Secret secret(place, code, time);
    cout << "secret code : " << secret.place;
    cout << "\nmeeting point : " << secret.code;
    cout << "\ntime : " << secret.time; 
    return 0;
}