#include <bits/stdc++.h>

using namespace std;

int scp(int n){
    int x = sqrt(n);
    if(x*x == n){
        return 1;
    }
    return 0;
}

int main(){
int a, min = 999; cin >> a;
for(int i = 1; i <= a; i++){
    long long temp = a*i;
    if(scp(temp) && i < min){
        min = i;
    }
}
cout << min;
    return 0;
}