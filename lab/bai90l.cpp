#include <iostream>

using namespace std;

struct phanso {
    int tu, mau;
};

int UCLN (int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main () {
    phanso a[1000];
    int i = 0;
    int top = 0, bottom = 1;
    while (cin >> a[i].tu >> a[i].mau) {
        top = (a[i].tu * bottom + top * a[i].mau);
        bottom *= a[i].mau;
    }
    cout << top / UCLN (top, bottom) << "/" << bottom / UCLN (top, bottom);
    return 0;
}