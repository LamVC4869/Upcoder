#include <iostream>
#include <fstream>
#include <cmath>
#define endl "\n"

using namespace std;

struct SoPhuc {
    int a, b;
    friend istream& operator >> (istream &is, SoPhuc &z) {
        is >> z.a >> z.b;
        return is;
    }
    friend ostream& operator << (ostream &os, SoPhuc z) {
        if (z.a != 0) {
            os << z.a;
            if (z.b < 0) os << " - " << z.b * (-1) << "*i";
            else if (z.b > 0) os << " + " << z.b << "*i";
        } else {
            if (z.b != 0) os << z.b << "*i";
            else os << 0;
        }
        return os << endl;
    }
    bool operator > (SoPhuc z) {
        if (this->a > z.a) return true;
        else if (this->a == z.a) {
            if (this->b > z.b) return true;
        }
        return false;
    }
    SoPhuc operator + (SoPhuc z) {
        SoPhuc z1;
        z1.a = this->a + z.a;
        z1.b = this->b + z.b;
        return z1;
    }
    SoPhuc operator * (SoPhuc z) {
        SoPhuc z2;
        z2.a = this->a * z.a - this->b * z.b;
        z2.b = this->a * z.b + this->b * z.a;
        return z2;
    }
};

void Scanf (SoPhuc a[], int size) {
    SoPhuc max = a[0];
    for (int i = 1; i < size; i++) if (a[i] > max) max = a[i];
    cout << max;
    SoPhuc tong;
    tong = a[0];
    for (int i = 1; i < size; i++) {
        tong = tong + a[i];
    }
    cout << tong;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    ios_base::sync_with_stdio (false);
    cin.tie (0);
    int i = 0;
    SoPhuc index, arr[1000];
    while (cin >> index) arr[i++] = index;
    Scanf (arr, i);
    return 0;
}