#include <iostream>

using namespace std;

int main(){
int n, max = INT_MIN, max2 = INT_MIN;
while(cin >> n){
    int temp = n;
    if(temp > max) max = temp;
    if(temp > max2 && temp < max) max2 = temp;
}
cout << max2 << " " << max;
    return 0;
}