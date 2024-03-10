#include <iostream>
#include <cmath>

using namespace std;

struct SoPhuc {
    int a, b;
    friend istream& operator >> (istream &is, SoPhuc &sp) {
        is >> sp.a >> sp.b;
        return is;
    }
    friend ostream& operator << (ostream &os, SoPhuc sp) {
        if (sp.a != 0 && sp.b != 0) {
            if (sp.b == -1) {
                os << sp.a << sp.b << "*i";
            } else if (sp.b == 1) {
                os << sp.a << '+' << sp.b << "*i";
            } else if (sp.b > 1) {
                os << sp.a << '+' << sp.b << "*i";
            } else {
                os << sp.a << sp.b << "*i";
            }
        }
        if (sp.b == 0) os << sp.a;
        if (sp.a == 0) {
            if (sp.b == 1) {
                os << 1 << "*i";
            } else if (sp.b == -1) {
                os << sp.b << "*i";
            } else if (sp.b > 1) {
                os << sp.b << "*i";
            } else if (sp.b < 1) {
                os << sp.b << "*i";
            }
        }
        return os;
    }
    friend SoPhuc operator + (SoPhuc s1, SoPhuc s2) {
        SoPhuc s3;
        s3.a = s1.a + s2.a;
        s3.b = s1.b + s2.b;
        return s3;
    }
    friend SoPhuc operator - (SoPhuc s1, SoPhuc s2) {
        SoPhuc s3;
        s3.a = s1.a - s2.a;
        s3.b = s1.b - s2.b;
        return s3;
    }
    friend SoPhuc operator * (SoPhuc s1, SoPhuc s2) {
        SoPhuc s3;
        s3.a = s1.a * s2.a - s1.b * s2.b;
        s3.b = s1.a * s2.b + s1.b * s2.a;
        return s3;
    }
    bool operator < (SoPhuc s) {
        if (this->a < s.a) return true;
        else if (this->a == s.a) {
            if (this->b < s.b) return true;
        }
        return false;
    }
};

int main () {
    int n; cin >> n;
    SoPhuc arr[n];
    for (SoPhuc &i : arr) cin >> i;
    SoPhuc max = arr[0], min = arr[0];
    SoPhuc tong = arr[0], tich = arr[0];
    for (int i = 1; i < n; i++) {
        if (!(arr[i] < max)) max = arr[i];
        if (arr[i] < min) min = arr[i];
        tong = tong + arr[i];
        tich = tich * arr[i];
    }
    cout << max << endl;
    cout << tong << endl;
    cout << tich << endl;
    cout << max - min;
    return 0;
}