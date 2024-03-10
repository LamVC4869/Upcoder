#include <bits/stdc++.h>

using namespace std;

int main(){
int n, temp, test;
int sum = 0, count = 0;
while(cin >> n){
    temp = n;
    n = test;
    while(n != 0){
        n /= 10;
        count++;
    }
    while(temp != 0){
        temp %= 10;
        sum += pow(temp, count);
        temp /= 10;
    }
    if(sum == test){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
    return 0;
}