#include <iostream>
#include <math.h>

using namespace std;

int isArmstrong(int n){
    int count = 0, sum = 0;
    int res = n;
while(n != 0){
    n /= 10;
    count++;
}
n = res;
    while(n != 0){
        int temp = n % 10;
        sum += pow(temp, count);
        n /= 10;
    }
    return sum == res;
}

int main(){
long long a, b; cin >> a >> b;
int count = 0;
for(long long i = a; i <= b; i++){
    if(isArmstrong(i)){
        count++;
        cout << i << " ";
    }
}
if(count == 0){
    cout << -1;
    return 0;
}
    return 0;
}