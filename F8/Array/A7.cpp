#include <iostream>

using namespace std;

int main () {
    int n;
    cout << "n = ";
    cin >> n;
    
    cout << "Nhap mang: ";
    int a[1000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cout << "k = ";
    cin >> k;

    cout << "Ket qua: ";
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] + a[j] == k) {
                cout << i << " " << j;
                count++;
                break;
            }
        }
        if (count == 1) {
            break;
        }
    }

    return 0;
}