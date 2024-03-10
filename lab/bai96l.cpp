#include <iostream>

using namespace std;

struct dathuc {
    int bac, arr [100];
};

int main () {
    dathuc a;
    cin >> a.bac;
    int n = a.bac;
    int count = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a.arr[i];
    }
    for (int i = 0; i <= n; i++) {
        cout << a.arr[i]; count++;
        if (count == 2) {
            cout << "x";
        } else if (count > 2) {
            cout << "x^"<< count - 1<<"";
        }
        if (count <= n) {
            cout << "+";
        }
    }
    return 0;
}