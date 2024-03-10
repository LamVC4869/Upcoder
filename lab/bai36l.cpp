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

    int n; cin >> n;
    int sum = 0, count = 0;
    bool temp = true;
    
    for (int i = 1; i <= n; i++){
        if (isPrime(i)){
            count++;
            sum += i;
        }
    }
    if (count == 0){
        cout << "NO";
        return 0;
    }else {
    cout << "Tong cac so nguyen to <= " << n << " la:" << endl;
    }

    for(int i = 1; i <= n; i++){
        if(isPrime(i)){
            if (!temp){
                cout << " + ";
            }
            cout << i;
            temp = false;
        }
    }
 
    cout << " = " << sum;

    return 0;
}