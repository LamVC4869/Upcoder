#include <iostream>

using namespace std;

struct Phanso {
    int tu, mau;
    friend bool operator> (Phanso p1, Phanso p2) {
        return (p1.tu * p2.mau - p1.mau * p2.tu) > 0;
    }
};

int UCLN (int a, int b) {
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main () {
    int n; cin >> n;
    Phanso phanso[n];
    for (int i = 0; i < n; i++) {
        cin >> phanso[i].tu >> phanso[i].mau;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (phanso[i] > phanso[j]) {
                Phanso tmp = phanso[i];
                phanso[i] = phanso[j];
                phanso[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << phanso[i].tu / UCLN (phanso[i].tu, phanso[i].mau) << "/" << phanso[i].mau / UCLN (phanso[i].tu, phanso[i].mau) << " ";
    return 0;
}