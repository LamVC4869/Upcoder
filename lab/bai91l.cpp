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
    return ((float) a.tu / UCLN (a)) / ((float) a.mau / UCLN (a));
}

int main () {
    phanso a[1000];
    int i = 0;
    float min = 99999;
    while (cin >> a[i].tu >> a[i].mau) {
        if (value (a[i]) < min) {
            min = value (a[i]);
        }
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (value (a[j]) == min) {
            cout << a[j].tu / UCLN (a[j]) << "/" << a[j].mau / UCLN (a[j]);
            break;
        }
    }
    return 0;
}