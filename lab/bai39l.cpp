#include <iostream>

using namespace std;

int main(){
    int n, i = 0, count = 0, a[1000];
    while (cin >> n){
        count++;
        a[i] = n;
        i++;
    }

    for (int j = i + 1; j < count; j++){
        if (a[i] > a[j]){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    for (i = 0; i < count; i++){
        cout << a[i] << " ";
    }

    return 0;
}