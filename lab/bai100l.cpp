#include <iostream>

using namespace std;

int Count0 (int n) {
    int count = 0;
    for (int i = 5; n / i > 0; i *= 5) {
        count += n / i;
    }
    return count;
}

int main () {
    int n;
    cin >> n;

    cout << Count0 (n);

    return 0;
}
