#include <iostream>

using namespace std;

int main(){
    int n, x; cin >> n >> x;
    int a[1000], count = 0, i;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

for (int i = 1; i <= n; i++){
    if (a[i] == x){
        count++;
        break; 
    }
}

    if (count == 0){
        cout << -1;
    }else {
        cout << i;
    }
    return 0;
}