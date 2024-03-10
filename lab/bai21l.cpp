#include <iostream>
#include <math.h>

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
int n; cin >> n;
int sum = 0;
while(cin >> n){
while(n != 0){
    int temp = n % 10;
    if(isPrime(temp)){
        sum += temp;
        }
    n /= 10;
    }
    cout << sum << endl;
}
    return 0;
}