#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

int current_day = 2024 * 365 + 3 * 30 + 19;

class Information{
    public:
    int year;
    int month;
    int day;
    int current_by_gap;
    string day_of_week;
    string weather;
    void calc(){
        current_by_gap = abs(year * 365 + month * 30 + day - current_day);
    }
    Information(){
        year = 2000;
        month = 0;
        day = 0;
        day_of_week = "";
        weather = "";
        calc();
    }
    Information(int year, int month, int day, string day_of_week, string weather){
        this->year = year;
        this->month = month;
        this->day = day;
        this->day_of_week = day_of_week;
        this->weather = weather;
        calc();
    }
    void print(){
        cout  << year << "-" <<setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " ;
        cout << day_of_week << " " << weather; 
    }
};
int main() {
    int n;
    int min = INT_MAX;
    Information* info_p;
    cin >> n;
    vector<Information> *v = new vector<Information>(n);
    for(int i = 0; i < n; i++){
        int year = 0;
        int month = 0;
        int day = 0;
        string day_of_week;
        string weather;
        string input;
        string buffer;
        cin >> input >> day_of_week >> weather;
        istringstream ss(input);
        while(getline(ss, buffer, '-')){
            if(year == 0){
                year = stoi(buffer);
            }
            else if(month == 0){
                month = stoi(buffer);
            }
            else{
                day = stoi(buffer);
            }
        }
        (*v)[i] = Information(year, month, day, day_of_week, weather);
        if(min > (*v)[i].current_by_gap && weather == "Rain"){
            info_p = &(*v)[i];
            min = info_p->current_by_gap;
        }
    }
    info_p->print();

    delete v;
    return 0;
}