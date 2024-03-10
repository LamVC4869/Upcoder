#include <bits/stdc++.h>

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
int n, a[100], count = 0, temp = 0;
while(cin >> n){
    a[temp] = n;
    temp++;
}
for(int i = k; i >= 0; i--){
    if(isPrime(a[i])){
        count++;
        cout << a[i];
        break;
    }
}
if(count == 0){
    cout << -1; return 0;
}
    return 0;
}