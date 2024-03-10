#include <iostream>

using namespace std;

int TongChan (int n) {
    int temp = 0;
    while (n > 0) {
        int tmp = n % 10;
        if (tmp % 2 == 0) {
            temp += tmp;
        }
        n /= 10;
    }
    return temp;
}

int TongLe (int n) {
    int temp = 0;
    while (n > 0) {
        int tmp = n % 10;
        if (tmp % 2 != 0) {
            temp += tmp;
        }
        n /= 10;
    }
    return temp;
}

int main () {
    unsigned int n; cin >> n;
    cout << TongChan (n) * TongLe (n);
    return 0;
}