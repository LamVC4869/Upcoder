#include <iostream>

using namespace std;

struct SoMoi {
    int a;
    friend istream& operator>>(istream &is, SoMoi &A) {
        is >> A.a;
        return is;
    }
    friend ostream& operator<<(ostream &os, SoMoi B) {
        os << "[SoMoi] " << B.a;
        return os;
    }
    int sum (SoMoi A) {
        int res = 0;
        while (A.a) {
            res += A.a % 10;
            A.a /= 10;
        }
        return res;
    }
    friend bool operator>(SoMoi A, SoMoi B) {
        return A.sum (A) > B.sum (B);
    }
    friend SoMoi operator+(SoMoi A, SoMoi B) {
        SoMoi C;
        C.a = A.sum (A) + B.sum (B);
        return C;
    }
};

int main () {
    SoMoi A, B; cin >> A >> B;
    cout << A << endl << B << endl;
    A > B ? cout << "true" << endl : cout << "false" << endl;
    cout << A + B;
    return 0;
}