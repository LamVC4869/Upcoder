#include <iostream>

using namespace std;

void Solve (long long index) {
    bool kt = false;
    if (index == 0) cout << 10;
    else if (index < 10) cout << index;
    else {
        long long result = 0, push = 1;
        for (int i = 9; i > 1; i--) {
            while (index % i == 0) {
                result += push * i;
                push *= 10;
                index /= i;
            }
        }
        bool kt = (index == 1) ? true : false;
        if (!kt) cout << -1;
        else cout << result;
    }
}

int main () {
    long long n; cin >> n;
    Solve (n);
    return 0;
}