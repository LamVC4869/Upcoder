#include <bits/stdc++.h>

using namespace std;

bool isPrime (int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    int a[1000], max, count = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (isPrime(a[i]) == true){
            count++;
            max = a[i];
        }
    }
    
for (int j = 0; j < n; j++){
    if(isPrime(a[j]) == true){
        if(a[j] > max) max = a[j];
    }
}

if (count == 0){
    cout << 0;
}else {
    cout << max;
}

    return 0;
}