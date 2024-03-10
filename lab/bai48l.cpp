#include <iostream>

using namespace std;

int main () {
    char c, a[1000];
    int i = 0;
    
    while (cin >> c) {
        a[i] = c;
        i++;
    }

    for (int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }

    cout << endl << a[2] << " " << a[i - 1];

    return 0;
}