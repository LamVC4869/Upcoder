#include <iostream>

using namespace std;

int SCS (int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

bool Output (int n) {
    if (SCS (n) % 2 != 0) return true;
    return false;
}

int main () {
    int n; cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (Output (i)) {
            count++;
        }
    }

    cout << count;

    return 0;
}