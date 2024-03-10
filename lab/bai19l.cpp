#include <iostream>

using namespace std;

int sole(int n){
    if(n % 2 == 0){
        return 0;
    }
    return 1;
}

int main(){
int n, temp; cin >> n;
int s = 1, count = 0;
while(n != 0){
    temp = n % 10;
    if(sole(temp)){
        count++;
        s *= temp;
    }
}
if(count == 1){
    cout << temp;
}else if(count == 0){
    cout << -1;
}else if(count > 1){
    cout << s;
}
    return 0;
}