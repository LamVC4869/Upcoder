//clock
#include <iostream>

using namespace std;

struct Time {
    int gio, phut, giay;
    friend istream& operator >> (istream &is, Time &t) {
        char c;
        is >> t.gio >> c >> t.phut >> c >> t.giay;
        return is;
    }
    friend ostream& operator << (ostream &os, Time t) {
        if (t.gio < 10) os << 0;
        os << t.gio << ':';
        if (t.phut < 10) os << 0;
        os << t.phut << ':';
        if (t.giay < 10) os << 0;
        os << t.giay;
        return os;
    }
    Time next (Time &t, int sec) {
        t.giay += sec;
        if (t.giay >= 60) {
            int nho1 = (t.giay - t.giay % 60) / 60;
            t.giay %= 60;
            t.phut += nho1;
            if (t.phut >= 60) {
                int nho2 = (t.phut - t.phut % 60) / 60;;
                t.phut %= 60;
                t.gio += nho2;
                t.gio %= 24;
            }
        }
        return t;
    }
};

int main () {
    Time t; cin >> t;
    int sec; cin >> sec;
    cout << t.next (t, sec);
    return 0;
}