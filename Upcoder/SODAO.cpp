#include <iostream>

using namespace std;

struct SoDao {
    int num;
    friend istream& operator>>(istream &is, SoDao &a) {
        is >> a.num;
        return is;
    }
    friend ostream& operator<<(ostream &os, SoDao a) {
        os << "[SoDao] " << a.num << "\n";
        return os;
    }
    int reverse () {
        int res = 0;
        while (num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    friend bool operator>(SoDao a, SoDao b) {
        return a.reverse () > b.reverse ();
    }
    friend int operator+(SoDao a, SoDao b) {
        return a.reverse() + b.reverse ();
    }
};

int main () {
    SoDao a, b;
    cin >> a >> b;
    cout << a << endl << b << endl;
    a > b ? cout << "YES" << endl : cout << "NO" << endl;
    cout << a + b;
    return 0;
}