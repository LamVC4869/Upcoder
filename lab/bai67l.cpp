#include <iostream>

using namespace std;

int reverse (int n) {
    int temp = 0;
    while (n != 0) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

int main () {
    int n; cin >> n;
    int sum = n + reverse (n);
    int temp = reverse (sum);
    cout << (temp % 1000) / 100; 
    return 0;
}