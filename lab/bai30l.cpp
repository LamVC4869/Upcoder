#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n, a[1000], max, count = 0; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(isPrime(a[i])){
            count++;
        }
    }
    for(int i = 0; i < n; i++){
        max = a[0];
        if(isPrime(a[i]) > max){
            max = a[i];
        }
    }

    if(count == 0){
        cout << 0;
    }else{
        cout << max;
    }
    return 0;
}