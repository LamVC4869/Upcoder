#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#define endl "\n"

using namespace std;

struct SoPhuc {
    int a, b;
    friend istream& operator >> (istream &is, SoPhuc &z) {
        is >> z.a >> z.b;
        return is;
    }
    friend ostream& operator << (ostream &os, SoPhuc z) {
        os << '{';
        if (z.a != 0) os << z.a;
        if (z.b != 0) {
            if (z.b == 1) os << "+i";
            else if (z.b == -1) os << "-i";
            else if (z.b > 1) os << '+' << z.b << 'i';
            else if (z.b < -1) os << z.b << 'i';
        }
        return os << '}';
    }
    double modul () {
        return sqrt (pow (this->a, 2) + pow (this->b, 2));
    }
    SoPhuc operator + (SoPhuc z) {
        SoPhuc result;
        result.a = this->a + z.a;
        result.b = this->b + z.b;
        return result;
    }
    SoPhuc operator - (SoPhuc z) {
        SoPhuc result;
        result.a = this->a - z.a;
        result.b = this->b - z.b;
        return result;
    }
};

struct MangSoPhuc {
    vector<SoPhuc> arr;
    friend istream& operator >> (istream &is, MangSoPhuc &a) {
        SoPhuc input;
        while (is >> input) a.arr.push_back (input);
        return is;
    }
    friend ostream& operator << (ostream &os, MangSoPhuc a) {
        SoPhuc tong = a.arr[0];
        for (int i = 0; i < a.arr.size (); i++) {
            os << a.arr[i] << ' ';
            if (i != 0) tong = tong + a.arr[i];
        }
        os << endl;
        for (int i = 0; i < a.arr.size (); i++) os << fixed << setprecision (2) << a.arr[i].modul () << ' ';
        os << endl << tong;
        return os;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    MangSoPhuc a;
    cin >> a;
    cout << a;
    return 0;
}