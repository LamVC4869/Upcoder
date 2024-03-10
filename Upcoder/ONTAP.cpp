#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PhanSo {
    int a, b;
    friend istream& operator >> (istream &is, PhanSo &p) {
        char temp;
        is >> p.a >> temp >> p.b;
        return is;
    }
    static int gcd (int a, int b) {
        int x = a, y = b;
        return (y == 0) ? x : gcd (y, x % y);
    }
    friend ostream& operator << (ostream &os, PhanSo p) {
        if (p.a == 0) {
            os << 0; return os;
        } else if (p.b == 1) {
            os << p.a; return os;
        }
        int ucln = gcd (p.a, p.b);
        p.a /= ucln, p.b /= ucln;
        os << p.a << '/' << p.b;
        return os;
    }
    bool operator == (const PhanSo another) {
        return this->a * another.b == this->b * another.a;
    }
    bool operator > (const PhanSo another) {
        return this->a * another.b > this->b * another.a;
    }
    bool operator < (const PhanSo another) {
        return this->a * another.b < this->b * another.a;
    }
    PhanSo operator + (const PhanSo another) {
        PhanSo res;
        res.a = this->a * another.b + this->b * another.a;
        res.b = this->b * another.b;
        return res;
    }
    PhanSo operator = (PhanSo another) {
        this->a = another.a;
        this->b = another.b;
        return *this;
    }
};  

template <typename T>
struct Array {
    int size = 0;
    vector<T> arr;
    friend istream& operator >> (istream &is, Array &a) {
        is >> a.size;
        a.arr.resize (a.size);
        for (T &i : a.arr) is >> i;
        return is;
    }
    friend ostream& operator << (ostream &os, Array a) {
        for (int i = 0; i < a.size; i++) os << a.arr[i] << ' ';
        return os;
    }
    Array operator = (Array another) {
        size = another.size;
        arr.resize(size);
        for (int i = 0; i < size; i++) arr[i] = another.arr[i];
        return *this;
    }
    Array operator + (const Array another) {
        Array t;
        t.size = min (this->size, another.size);
        t.arr.resize (t.size);
        for (int i = 0; i < t.size; i++) t.arr[i] = this->arr[i] + another.arr[i]; 
        int i = t.size;
        while (i < this->size) {
            t.arr.push_back (this->arr[i]);
            i++;
            t.size++;
        }
        while (i < another.size) {
            t.arr.push_back (another.arr[i]);
            i++;
            t.size++;
        }
        return t;
    }
    Array SORT () {
        sort (arr.begin (), arr.end ());
        return *this;
    }
    Array RSORT () {
        sort (arr.rbegin (), arr.rend ());
        return *this;
    }
    T SUM () {
        T result = arr[0];
        for (int i = 1; i < size; i++) result = result + arr[i];
        return result;
    }
    T MAX () {
        T MaxVal = arr[0];
        for (int i = 1; i < size; i++) if (arr[i] > MaxVal) MaxVal = arr[i];
        return MaxVal;
    }
};

int main () {
    char c; cin >> c;
    Array<int> in1, in2;
    Array<PhanSo> ps1, ps2;
    vector<int> in1Even, in1Odd, in2Even, in2Odd;
    if (c == 'I') {
        cin >> in1 >> in2;
        Array<int> in3 = in1 + in2;
        cout << in1 << endl;
        cout << "MAX 1 = " << in1.MAX () << endl;
        cout << "SUM 1 = " << in1.SUM () << endl;
        in1.SORT ();
        for (int i = 0; i < in1.size; i++) if (in1.arr[i] % 2 == 0) cout << in1.arr[i] << ' ';
        for (int i = 0; i < in1.size; i++) if (in1.arr[i] % 2 == 1) cout << in1.arr[i] << ' ';
        cout << endl;
        cout << in2 << endl;
        cout << "MAX 2 = " << in2.MAX () << endl;
        cout << "SUM 2 = " << in2.SUM () << endl;
        in2.RSORT ();
        for (int i = 0; i < in2.size; i++) if (in2.arr[i] % 2 == 1) cout << in2.arr[i] << ' ';
        for (int i = 0; i < in2.size; i++) if (in2.arr[i] % 2 == 0) cout << in2.arr[i] << ' ';
        cout << endl;
        cout << in3;
    } else if (c == 'F') {
        cin >> ps1 >> ps2;
        Array<PhanSo> ps3 = ps1 + ps2;
        cout << ps1 << endl;
        cout << "MAX 1 = " << ps1.MAX () << endl;
        cout << "SUM 1 = " << ps1.SUM () << endl;
        ps1.SORT ();
        cout << ps1 << endl;
        cout << ps2 << endl;
        cout << "MAX 2 = " << ps2.MAX () << endl;
        cout << "SUM 2 = " << ps2.SUM () << endl;
        ps2.RSORT ();
        cout << ps2 << endl;
        cout << ps3;
    }
    return 0;
}