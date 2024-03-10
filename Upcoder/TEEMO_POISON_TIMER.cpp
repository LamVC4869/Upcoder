#include <iostream>

using namespace std;

int main () {
    int n, time;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++) cin >> t[i];
    cin >> time;
    int result = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp = t[i + 1] - t[i];
        result += tmp;
    }
    cout << result + time;
    return 0;
}