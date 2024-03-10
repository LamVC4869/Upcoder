#include <iostream>

using namespace std;

int FBNC(int n){
    if(n == 1 || n == 2){
        return 1;
    }else if(n >= 3){
        return FBNC(n - 1) + FBNC(n - 2);
    }
}

int main(){
int n; cin >> n;
for(int i = 1; i <= n; i++){
    cout << FBNC(i) << " ";
}
    return 0;
}