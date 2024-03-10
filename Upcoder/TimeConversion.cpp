#include <iostream>

using namespace std;

struct Time {
    int gio, phut, giay;
    string When;
    Time (string str) {
        this->gio = stoi (str.substr (0, 2));
        this->phut = stoi (str.substr (3, 2));
        this->giay = stoi (str.substr (6, 2));
        this->When = str.substr (9, 2);
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
};

void TimeConversion (int seconds, Time &t) {
    if (t.When == "PM" && t.gio < 12) t.gio += 12;
    t.giay += seconds;
    if (t.giay >= 60) {
        int x = t.giay - (t.giay % 60);
        t.giay %= 60, x /= 60;
        t.phut += x;
        if (t.phut >= 60) {
            int h = t.phut - (t.phut % 60);
            t.phut %= 60, h /= 60;
            t.gio += h;
            if (t.gio >= 24) {
                t.gio %= 24;
            }
        }
    }
    cout << t;
}

int main () {
    string times;
    int seconds;
    getline (cin, times);
    Time t(times);
    cin >> seconds;
    TimeConversion (seconds, t);
    return 0;
}