#include <iostream>
#include <math.h>

using namespace std;

int main(){
int n, h; cin >> n;
if(n < 5){
    cout << -1; return 0;
}
for(int i = 1; i <= n; i++){
    for(int z = 1; z <= n; z++){
        h = sqrt(pow(i, 2) + pow(z, 2));
        if(h <= n && z != i && z < i && pow(h, 2) == pow(i, 2) + pow(z, 2)){
            cout << z << " " << i << " " << h << endl;
        }
    }
}
    return 0;
}