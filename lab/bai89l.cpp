#include <iostream>

using namespace std;

struct phanso {
    int tu, mau;
};

int UCLN (phanso a) {
        while (a.mau != 0) {
            int tmp = a.tu % a.mau;
            a.tu = a.mau;
            a.mau = tmp;
        }
    return a.tu;
}

float value (phanso a) {
    return ((float)(a.tu / UCLN (a)) / ((float)a.mau / UCLN (a)));
}

int main () {
    phanso arr[1000];
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].tu >> arr[i].mau;
    }

    float min = 999;
    for (int i = 0; i < n; i++) {
        if (value (arr[i]) < min) {
            min = value (arr[i]);
        }
    }

    for (int j = 0; j < n; j++) {
        if (value (arr[j]) == min) {
            cout << arr[j].tu / UCLN (arr[j]) << "/" << arr[j].mau / UCLN (arr[j]);
            break;
        }
    }

    return 0;
}