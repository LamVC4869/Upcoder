#include <iostream>

using namespace std;

struct Array {
    int size, value [100];
};

void SumOfValue (int n1, int n2, int a1[], int a2[]) {
    if (n1 > n2) {
        for (int i = 0; i < n1; i++) {
            if (i >= n2) a2[i] = 0;
            cout << a1[i] + a2[i] << " ";
            }
        } else {
            for (int i = 0; i < n2; i++) {
                if (i >= n1) a1[i] = 0;
                cout << a1[i] + a2[i] << " ";
        }
    }    
}

int main () {
    Array a[2];
    for (int i = 0; i < 2; i++) {
        cin >> a[i].size;
        for (int j = 0; j < a[i].size; j++) {
            cin >> a[i].value[j];
        }
    }

    SumOfValue (a[0].size, a[1].size, a[0].value, a[1].value);

    return 0;
}