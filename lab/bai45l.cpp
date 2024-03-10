#include <iostream>
#include <string>

using namespace std;

int main () {
    string a; getline (cin, a);
    char c; cin >> c;
    int count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == c) {
            count++;
        }
    }

    cout << count;

    return 0;
}