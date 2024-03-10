#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int x, i = 0;
    int a[1000];
    while (cin >> x) {
        a[i++] = x;
    }
    
    for (int j = 0; j < i; j++) {
        if (a[j] == 1) {
            cout << "+ x^" << i - j - 1<< " ";
        } else if (a[j] == -1) {
                cout << "- x^" << i - j - 1<< " ";
        } else if (j == i - 2) {
            if (a[j] > 0) {
                cout << "+ " << a[j] << "x ";
            } else if (a[j] < 0) {
                a[j] = abs (a[j]);
                cout << "- " << a[j] << "x ";
            }
        } else if (j == i - 1) {
            if (a[j] > 0) {
                cout << "+ " << a[j];
            } else if (a[j] < 0) {
                cout << "- " << abs (a[j]);
            }
        } else if (j > 0) {
            if (a[j] > 0) {
                cout << "+ " << a[j] << "x^" << i - j - 1<< " ";
            } else if (a[j] < 0) {
                cout << "- " << abs (a[j]) << "x^" << i - j - 1<< " ";
            }
        } else {
            cout << a[j] << "x^" << i - j - 1<< " ";
        }
    }
    cout << " = " << 0;

    return 0;
}