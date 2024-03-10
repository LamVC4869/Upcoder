#include <bits/stdc++.h>

using namespace std;

float Sum(float x, int n){
    float sum = 0, temp = x;
    for(int i = 1; i <= 2 * n + 1; i += 2){
        sum += temp;
        temp *= x*x;
    }
    return sum;
}

int main(){
float x; int n; cin >> x >> n;
cout << fixed << setprecision(2) << Sum(x, n);
    return 0;
}