#include <iostream>

using namespace std;

struct BacHai {
    int a, b, c;
    friend istream& operator >> (istream &is, BacHai &f) {
        is >> f.a >> f.b >> f.c;
        return is;
    }
    friend ostream& operator << (ostream &os, BacHai f) {
        os << f.a << "x^2+" << f.b << "x+" << f.c;
        return os << endl;
    }
    int tinhGiaTri (int index) {
        return (this->a * index * index) + (this->b * index) + this->c;
    }
    friend BacHai operator + (BacHai f1, BacHai f2) {
        BacHai f3;
        f3.a = f1.a + f2.a;
        f3.b = f1.b + f2.b;
        f3.c = f1.c + f2.c;
        return f3;
    }
    friend bool operator == (BacHai f1, BacHai f2) {
        return f1.a == f2.a && f1.b == f2.b && f1.c == f2.c;
    }
};

struct BacNhat {
    int a, b;
    friend istream& operator >> (istream &is, BacNhat &f) {
        is >> f.a >> f.b;
        return is;
    }
    friend ostream& operator << (ostream &os, BacNhat f) {
        os << f.a << "x+" << f.b;
        return os;
    }
    friend BacHai operator * (BacNhat f1, BacNhat f2) {
        BacHai f3;
        f3.a = f1.a * f2.a;
        f3.b = f1.a * f2.b + f1.b * f2.a;
        f3.c = f1.b * f2.b;
        return f3;
    }
    int tinhGiaTri (int index) {
        return this->a * index + this->b;
    }
};

int main () {
    BacHai f1, f2; cin >> f1 >> f2;
    BacNhat f3, f4; cin >> f3 >> f4;
    int index; cin >> index;
    cout << f1 << f1.tinhGiaTri (index) << endl;
    cout << f2 << f2.tinhGiaTri (index) << endl;
    BacHai f5 = f1 + f2;
    cout << f5 << f5.tinhGiaTri (index) << endl;
    BacHai f6 = f3 * f4;
    cout << "(" << f3 << ")*(" << f4 <<")=" << f6 << f6.tinhGiaTri (index) << endl;
    if (f1 == f6 && f2 == f6) cout << "TRUE3" << endl;
	else if (f1 == f6) cout << "TRUE1" << endl;
	else if (f2 == f6) cout << "TRUE2" << endl;
	else cout << "FALSE" << endl;
    return 0;
}
