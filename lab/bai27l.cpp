#include <iostream>
#include <iomanip>

using namespace std;

int main(){
int n; cin >> n;
double a[100], sum, max, min;
for(int i = 0; i < n; i++){
    cin >> a[i];
}
max = a[0];
min = a[0];
for(int i = 0; i < n; i++){
    if(a[i] > max) max = a[i];
    if(a[i] < min) min = a[i];
}
    sum = (double)(max + min)/2;
    cout << fixed << setprecision(2) << sum;
    return 0;
}