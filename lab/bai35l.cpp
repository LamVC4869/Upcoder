#include <bits/stdc++.h>

using namespace std;

bool isPrime (int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int k; cin >> k;
    int a[1000], value, i = 0, count = 0, j, max;
    while (cin >> value){
        a[i] = value;
        i++;
        if (isPrime(value) && value <= k){
            max = value;
            count++;
        }
    }

    if(count == 0){
        cout << -1;
        return 0;
    }else {

        for (j = k; j >= 0; j--){
            if (isPrime(a[j]) && a[j] <= k && a[j] >= max){
                max = a[j];
                break;
            }
        }

        cout << max;

    }
    
    return 0;
}