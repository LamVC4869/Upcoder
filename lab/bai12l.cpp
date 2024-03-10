#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double s = 0;
    for(int i = 1; i <= n; i++){
        s += 1.00/i;
    }
    cout << round(s*100)/100;
    return 0;
}