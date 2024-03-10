#include <iostream>

using namespace std;

int main () {
    int n, i = 0, sum = 0, a[1000];

    while (cin >> n) {
        a[i] = n;
        sum += a[i];
        i++;
    }

    if (i < 3) {
        cout << "NO";
        return 0;
    } else {
        cout << i << endl << sum << endl;

    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (a[k] < a[j]) {
                int temp = a[k];
                a[k] = a[j];
                a[j] = temp;
            }
        }
    }


    for (int x = 0; x < i; x++) {
        cout << a[x] << " ";
    }
}

    return 0;
}