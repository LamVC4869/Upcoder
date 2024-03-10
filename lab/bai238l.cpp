#include <iostream>
#include <cmath>

using namespace std;

struct DaThuc {
    int n;
    int a[100];
    friend istream& operator >> (istream &is, DaThuc &d) {
        is >> d.n;
        for (int i = 0; i <= d.n; i++) is >> d.a[i];
        return is;
    }
    friend ostream& operator << (ostream &os, DaThuc d) {
        if (d.n == 0) {
            os << d.a[0];
            return os << endl;
        } else if (d.n < 0) {
            os << 0;
            return os << endl;
        }
        bool kt = false;
        for (int i = 0; i <= d.n; i++) {
            if (abs (d.a[i]) != 1 && d.a[i] != 0) {
                os << d.a[i]; kt = true;
        } else if (abs (d.a[i]) == 1) {
            if (i == 0 && d.a[i] == -1) os << '-';
            else if (i == d.n) os << 1;
            kt = true;
        }
        if (d.a[i] != 0) {
            if (d.n - i > 1) os << "x^" << d.n - i;
            else if (d.n - i == 1) os << 'x';
            kt = true;
        }
        if (d.a[i + 1] > 0 && i + 1 <= d.n && kt) os << '+';
 		else if (d.a[i + 1] == -1) os << '-';
        }
        if (!kt) os << 0;
        return os << endl;
    }
    DaThuc DaoHam () {
        for (int i = 0; i <= n; i++) a[i] *= (n - i);
        n--;
        return *this;
    }
};

int main () {
    DaThuc a; cin >> a;
    cout << a;
    cout << a.DaoHam ();
    cout << a.DaoHam ();
    return 0;
}