#include <iostream>

using namespace std;

int main(){
int score; cin >> score;
int sum = 0, count = 0;
string rank = "A";
while(score != -1){
    sum += score;
    count++;
    cin >> score;
}
double average = sum / count;
if(average < 4){
    rank = "F";
}else if(average < 5.5){
    rank = "D";
}else if(average < 7){
    rank = "C";
}else if(average < 8.5){
    rank = "B";
}
    cout << rank;
    return 0;
}