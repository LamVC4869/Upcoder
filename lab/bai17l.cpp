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
int n, x; cin >> n;
int count = 0;
for(int i = 2; i < n; i++){
    if(isPrime(i)){
        for(int j = 2; j < n; j++){
            if(isPrime(j) && i*j == n && x != i){
                x = j;
                count++;
            }
        }
    }
}
cout << count;
    return 0;
}