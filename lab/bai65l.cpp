#include <iostream>

using namespace std;

int main () {
    string str;
    cin >> str;
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        cout << str[i];
    }

    for (int j = str.length() - 1; j >= n; j--) {
        cout << str[j];
    }

    return 0;
}