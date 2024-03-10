#include <bits/stdc++.h>

using namespace std;

bool isPrime (long n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt (n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

long reverse (long n){
    int temp = 0;
    while (n != 0){
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

int main(){
    long P, Q; cin >> P >> Q;
    if (Q - P <= 100000){
        for (long i = P; i <= Q; i++){
            if (isPrime (reverse (i))){
                cout << i << endl;
            }
        }
    }
    return 0;
}