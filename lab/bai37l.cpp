#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int k; cin >> k;
    int n = 0, count = 0, temp, a[100];
    while(cin >> temp){
        a[n] = temp;
        n++;
    }
    for(int i = k; i > 0; i--){
        if(isPrime(a[i]) && a[i] <= k){
            count++;
            cout << a[i];
            break;
            }
        }
        if(count == 0){
            cout << 0;
            return 0;
        }
    return 0;
}