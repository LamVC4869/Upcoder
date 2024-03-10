#include <iostream>
#include <math.h>

using namespace std;

bool SNT(int n){
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

int SCP(int n){
    int temp = sqrt(n);
    if(temp*temp == n){
        return 1;
    }else{
        return 0;
    }
}

int SHH(int n){
    int sum0 = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            sum0 += i;
        }
    }
    if(sum0 == n){
        return 1;
    }else{
        return 0;
    }
}

int main(){
int x, n; cin >> n >> x;
if(n == 2){
    if(SNT(x)){
        cout << "yes";
    }else{
        cout << "no";
    }
}else if(n == 1){
    if(SHH(x) == 1){
        cout << "yes";
    }else{
        cout << "no";
    }
}else if(n == 3){
    if(SCP(x) == 1){
        cout << "yes";
    }else{
        cout << "no";
    }
}
    return 0;
}