#include <iostream>

using namespace std;

int IsCatalan(int n){
    if(n < 2) return 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += IsCatalan(i) * IsCatalan(n - i - 1);
    }
    return sum;
}

int main(){
    int n;
    while(cin >> n){
        cout << IsCatalan(n) << endl;
    }
    return 0;
}