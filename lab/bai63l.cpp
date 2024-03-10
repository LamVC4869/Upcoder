#include <iostream>

using namespace std;

int main () {
    int n;
    while (cin >> n) {
    cin.ignore();
    string a;
    cin >> a;
    if (n >= 0 && n < a.length()) {
        cout << a[n];
    } else {
        cout << -1;
    }
    cout << endl;
}
    return 0;
}